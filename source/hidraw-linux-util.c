#include "hid-descriptor-vtable.h"
#include "hidraw-linux-vtable.h"


void hidraw_collection_print_with_descriptor(hidraw_collection_t *collection, libhid_descriptor_virtual_table *vtable)
{
	int i= 0, j=0;
	hidraw_t* current;
	hidraw_input_t* current_input;
	libhid_report_descriptor_t report_descriptor;
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
		hid_descriptor_t descriptor;
		printf("\tHid Profile:\n");
		report_descriptor.size = current->hid_raw_descriptor.size;
		for(j=0; j < report_descriptor.size; j++)
			report_descriptor.value[j] = current->hid_raw_descriptor.value[j];
			
		if( current->hid_raw_descriptor.size > 0 && vtable->libhid_descriptor_create.call(&report_descriptor,&descriptor) > -1){
			vtable->libhid_descriptor_print_tab.call(&descriptor, 4*2);
			vtable->libhid_descriptor_destroy.call(&descriptor);
		}
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

/**
 * Main entry method
 * @param[in] argc arguments count
 * @param[in] argv arguments vector
 */
int main(int argc, char** argv){
	char* lib_path = get_lib_path(argv[0], "/lib.hid.descriptor.so");
	printf("lib path: %s\n", lib_path);
	void* lib_ptr  = load_library(lib_path);
	free(lib_path);
	lib_path= NULL;
	libhid_descriptor_virtual_table vtable;
	libhid_descriptor_virtual_table_load(lib_ptr, &vtable);
	if( libhid_descriptor_virtual_table_validate(&vtable)){ 
		fprintf(stderr, "vtable validation failed\n");
		return EXIT_FAILURE;
	}
	
	lib_path = get_lib_path(argv[0], "/lib.hid.rawlinux.so");
	printf("lib path: %s\n", lib_path);
	void* lib_hidraw_linux = load_library(lib_path);
	free(lib_path);
	hidraw_virtual_table vtable_hidraw;
	hidraw_virtual_table_load(lib_hidraw_linux, &vtable_hidraw);
	if( hidraw_virtual_table_validate(&vtable_hidraw)){ 
		fprintf(stderr, "vtable validation failed\n");
		return EXIT_FAILURE;
	}

	hidraw_collection_t hid_devices;
	vtable_hidraw.hidraw_collection_create.call(&hid_devices);
	printf("Hid Device Count: %d\n", hid_devices.size);
	hidraw_collection_print_with_descriptor(&hid_devices, &vtable);
	vtable_hidraw.hidraw_collection_delete.call(&hid_devices);
	return EXIT_SUCCESS;
}
