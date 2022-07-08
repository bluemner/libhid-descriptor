#include "hidraw-linux.h"

int32_t file_count(const char* directory){
	int32_t size = 0;
	struct dirent *entry;
	DIR *dp;
	dp = opendir(directory);
	if (dp == NULL) 
	{
		perror("opendir");
		return -EBADF;
	}
	while((entry = readdir(dp))){
		if(entry->d_name[0] == '.') continue;
		++size;
	}
	closedir(dp);
	return size;
}

int open_file(const char* path, char *buffer,const size_t buffer_size){
  FILE *fp = fopen(path, "r");
  if(fp == NULL) {
      return -EBADF;
  }
  size_t len = fread(buffer, sizeof(char), buffer_size, fp);
  if(ferror(fp) != 0) {
      fputs("Error reading file", stderr);
      fclose(fp);
      return -EBADF;
  }
  
  buffer[len] = '\0'; 
  fclose(fp);
  return len;
}

const char* bustype_string(int bustype){
	switch (bustype)
	{
		case BUS_USB:
			return "USB";
		case BUS_PCI:
			return "PCI";
		case BUS_BLUETOOTH:
			return "Bluetooth";
		case BUS_VIRTUAL:
			return "Virtual";
		default:
			return "Other";
	}
}
 
int load_hid_descriptor(const char* path, hid_raw_descriptor_t *descriptor){

  int result, descriptor_size = 0;
  memset(descriptor, 0x0, sizeof(*descriptor));
  
  int fd = open(path, O_RDONLY);
  if (fd < 0){
      fprintf(stderr, "You must run as elevated user or be in a group that has access to: %s\n", path);
      result = -EBADF;
			goto finally;
  }
  result = ioctl(fd, HIDIOCGRDESCSIZE, &descriptor_size);
  if(result < 0){
			fprintf(stderr, "Error getting description size: %s\n", path);
      result = -EPERM;
			goto finally;
  }
  descriptor->size = descriptor_size;

	if( descriptor->size > HID_MAX_DESCRIPTOR_SIZE) return -256;

  result = ioctl(fd, HIDIOCGRDESC, descriptor);
  if (result < 0){
		fprintf(stderr, "Error getting description: %s\n", path);
    result= -EPERM;
		goto finally;
  }
	result = 0;
finally:
  close(fd);
  return result;
}

int device_id_directory(const char* directory, hidraw_input_t* hid){
	struct dirent *entry;
  DIR *dp;
  char buf[PATH_MAX];

  dp = opendir(directory);
	char input[8];
	const uint8_t input_size =8;
	while((entry = readdir(dp))){
		if(entry->d_name[0] == '.') continue;
		memset(&input[0], 0, sizeof(input));
		if(STRING_STARTS_WITH("bustype", entry->d_name)){
			snprintf(buf, sizeof(buf), "%s/%s" ,directory, entry->d_name);	
		
			if(open_file( buf, input, input_size) < 0) 
					continue; 
				hid->id.bustype = (__u16) strtoul(input, NULL, 16); 
			continue;
		}
		if(STRING_STARTS_WITH("product", entry->d_name)){
			snprintf(buf, sizeof(buf), "%s/%s" ,directory, entry->d_name);	
		
			if(open_file( buf, input, input_size) < 0) 
					continue; 
				hid->id.product = (__u16) strtoul(input, NULL, 16); 
			continue;
		}
		if(STRING_STARTS_WITH("vendor", entry->d_name)){
			snprintf(buf, sizeof(buf), "%s/%s" ,directory, entry->d_name);	
		
			if(open_file( buf, input, input_size) < 0) 
					continue; 
				hid->id.vendor = (__u16) strtoul(input, NULL, 16); 
				continue;
		}
		if(STRING_STARTS_WITH("version", entry->d_name)){
			snprintf(buf, sizeof(buf), "%s/%s" ,directory, entry->d_name);	
			if(open_file( buf, input, input_size) < 0) 
					continue; 
				hid->id.version = (__u16) strtoul(input, NULL, 16); 
				continue;
		}

	}
	closedir(dp);
  return 0;
}

int device_input_directory(const char* directory, hidraw_input_t* hid){
  struct dirent *entry;
  DIR *dp;
  char buf[PATH_MAX];

  dp = opendir(directory);
  if (dp == NULL) 
  {
      perror("opendir");
      return -EBADF;
  }
  while((entry = readdir(dp))){
		if(entry->d_name[0] == '.') continue;
		
		if(STRING_STARTS_WITH("event", entry->d_name)){
			snprintf(buf, sizeof(buf), "/dev/input/%s", entry->d_name);
			hid->event_path = strdup(buf);						
		}
		if(STRING_STARTS_WITH("name", entry->d_name)){
			snprintf(buf, sizeof(buf), "%s/%s" ,directory, entry->d_name);
			
			char input[256 +1];
			if(open_file( buf, input, 256) < 0) 
					continue; 
			hid->device_name = strdup(input); 
		}

  }
	
  closedir(dp);
	snprintf(buf, sizeof(buf), "%s/id",directory);
  return device_id_directory(buf, hid);
}

int device_directory(const char* directory, hidraw_t* hid)
{
	struct dirent *entry;
	DIR *dp;
	char buf[PATH_MAX];

	dp = opendir(directory);
	if (dp == NULL) 
			return -EBADF;
	
	int size = file_count(directory);
	if(size < 0) return -2;

	hid->input_count = (uint16_t) size;
	hid->inputs = (hidraw_input_t*) malloc(hid->input_count * sizeof(hidraw_input_t));
	int index = 0;
	hidraw_input_t *current;
	for(; index < hid->input_count; index++){
		current = &(hid->inputs[index]);
		hidraw_input_create(current);
	}

	index = 0;
	current = NULL;
	while((entry = readdir(dp)))
	{
		if(entry->d_name[0] == '.') continue;      
		current = &(hid->inputs[index++]);
		snprintf(buf, sizeof(buf), "%s", entry->d_name);
		current->input = strdup(buf);
		snprintf(buf, sizeof(buf), "%s/%s", directory, entry->d_name);
		device_input_directory(buf, current);
	}
	closedir(dp);
	return 0;
}

int32_t hid_device_count()
{
  int size = 0;
  struct dirent *entry;
  DIR *dp;
  char *directory = "/sys/class/hidraw/";
  dp = opendir(directory);
  if (dp == NULL) 
  {
    perror("opendir");
    return -EBADF;
  }
  while((entry = readdir(dp))){
    if(entry->d_name[0] == '.') continue;
    ++size;
  }
  closedir(dp);
  return size;
}

int hid_device_paths(hidraw_collection_t* hidraw_devices)
{
	int index = 0;
	struct dirent *entry;
	DIR *dp;
	char buf[PATH_MAX];
	char *directory = "/sys/class/hidraw";
	dp = opendir(directory);
	if (dp == NULL) 
	{
		perror("opendir");
		return -EBADF;
	}
	hidraw_t *current;
	while((entry = readdir(dp))){
		if( index == hidraw_devices->size  ) {
			closedir(dp);
			return -1;
		}
		
		if(entry->d_name[0] == '.') continue;
		//index = entry->d_name[strlen(entry->d_name)-1] - '0';
		current = &(hidraw_devices->items[index]);
		current-> name = strdup(entry->d_name);
		snprintf(buf, sizeof(buf), "/dev/%s", entry->d_name);
		current-> hidraw_path = strdup(buf);
		load_hid_descriptor(current->hidraw_path, &(current->hid_raw_descriptor));

		snprintf(buf, sizeof(buf), "/sys/class/hidraw/%s/device/input", entry->d_name);
		device_directory(buf, current);
		++index;
	}

	closedir(dp);
	return index;
}

void hidraw_input_create(hidraw_input_t* hid){
	hid->input = NULL;
	hid->event_path= NULL;
	hid->device_name = NULL;
}

void hidraw_input_delete(hidraw_input_t * hid){
	
	if(hid->input !=NULL){
		free(hid->input);
		hid->input= NULL;
	}
	if(hid->event_path !=NULL){
		free(hid->event_path);
		hid->event_path= NULL;
	}
	if(hid->device_name !=NULL){
		free(hid->device_name);
		hid->device_name= NULL;
	}
}

void hidraw_create(hidraw_t * hid){
	hid->hidraw_path= NULL;
	hid->name= NULL;
	hid->inputs= NULL;
	hid->input_count= 0;
	hid->hid_raw_descriptor.size=0;
}

void hidraw_delete(hidraw_t * hid){

	if(hid->name !=NULL){
		free(hid->name);
		hid->name= NULL;
	}
	if(hid->hidraw_path !=NULL){
		free(hid->hidraw_path);
		hid->hidraw_path= NULL;
	}
	int i=0;
	hidraw_input_t * current;
	for(; i< hid->input_count; i++){
		current = &(hid->inputs[i]);
		hidraw_input_delete(current);
	}
	hid->input_count =0;
	if(hid->inputs !=NULL){
		free(hid->inputs);
		hid->inputs = NULL;
	}

}

void hidraw_collection_create(hidraw_collection_t *collection){

	int32_t size = file_count("/sys/class/hidraw/");  //hid_device_count();
	if(size < 0){
		collection->items = NULL;
		return;
	}
	collection->size = (uint16_t) size;
	collection->items = (hidraw_t*) malloc(collection->size  * sizeof(hidraw_t));
	int i= 0;
	hidraw_t *current;
	for(; i< collection->size; i++ ){
		current = &(collection->items[i]);
		hidraw_create(current);
	}
	hid_device_paths(collection);
}

void hidraw_collection_delete(hidraw_collection_t *collection){
	int i= 0;
	hidraw_t *current;
	for(; i< collection->size; i++ ){
		current = &(collection->items[i]);
		hidraw_delete(current);

	}
	if (collection-> items != NULL){
		free(collection->items);
		collection-> items = NULL;
	}
	collection->size = 0;
	
}

void hidraw_collection_print(hidraw_collection_t *collection)
{
	int i= 0, j=0;
	hidraw_t* current;
	hidraw_input_t* current_input;
	for(; i< collection->size; i++ ){
		current = &(collection->items[i]);
		if (current == NULL || current->name == NULL) continue;
		printf("%s\n", current->name);
		printf("\tHid Path: %s\n", current->hidraw_path);
		printf("\tHid Descriptor Size: %d\n", current->hid_raw_descriptor.size);
		printf("\tHid Descriptor:\n\t\t");
		for(j=0; j< current->hid_raw_descriptor.size; j++ ){
			printf("%02hhx ", current->hid_raw_descriptor.value[j] );
			if( ((j +1) % 10) == 0 && j+1 > 1 ) printf("\n\t\t");
		}
		printf("\n");
		printf("\tInput Count: %d\n", current->input_count);
		for(j=0; j< current->input_count; j++ ){
			current_input = &(current->inputs[j]);
			printf("\t\tIndex: %d\n", j);
			printf("\t\tInput: %s\n", current_input-> input);
			printf("\t\tEvent Path: %s\n", current_input-> event_path);
			printf("\t\tDevice Name: %s", current_input-> device_name);
			printf("\t\tId: \n");
			printf("\t\t  Bustype: 0x%04hx\n", current_input->id.bustype);
			printf("\t\t  Product: 0x%04hx\n", current_input->id.product);
			printf("\t\t  Vendor:  0x%04hx\n", current_input->id.vendor);
			printf("\t\t  Version: 0x%04hx\n", current_input->id.version);
		}
	}
}
