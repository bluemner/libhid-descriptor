/**
 * @file hid-descriptor.c
 */
#include "hid-descriptor.h"
#include "hid-event-codes-text.h"

void hid_main_item_text(const hid_32bit_field_t *field, hid_main_item_text_t *text, const uint8_t hid_main){
    text->bit_00 = (field->bit_00 == 0) ? HID_TEXT_MAIN_ITEM_DATA: HID_TEXT_MAIN_ITEM_CONSTANT;
		text->bit_01 = (field->bit_01 == 0) ? HID_TEXT_MAIN_ITEM_ARRAY: HID_TEXT_MAIN_ITEM_VARIABLES;
		text->bit_02 = (field->bit_02 == 0) ? HID_TEXT_MAIN_ITEM_ABSOLUTE: HID_TEXT_MAIN_ITEM_RELATIVE;
		text->bit_03 = (field->bit_03 == 0) ? HID_TEXT_MAIN_ITEM_NO_WRAP: HID_TEXT_MAIN_ITEM_WRAP;
		text->bit_04 = (field->bit_04 == 0) ? HID_TEXT_MAIN_ITEM_LINEAR: HID_TEXT_MAIN_ITEM_NON_LINEAR;
		text->bit_05 = (field->bit_05 == 0) ? HID_TEXT_MAIN_ITEM_PREFERRED_STATE: HID_TEXT_MAIN_ITEM_NO_PREFERRED;
		text->bit_06 = (field->bit_06 == 0) ? HID_TEXT_MAIN_ITEM_NO_NULL_POSITION: HID_TEXT_MAIN_ITEM_NULL_STATE;
		/*if input set to reserved*/
		text->bit_07 = (hid_main == HID_MAIN_INPUT) ? HID_TEXT_RESERVED :  (field->bit_07 == 0) ? HID_TEXT_MAIN_ITEM_NON_VOLATILE: HID_TEXT_MAIN_ITEM_VOLATILE;
		text->bit_08 = (field->bit_06 == 0) ? HID_TEXT_MAIN_ITEM_BIT_FIELD: HID_TEXT_MAIN_ITEM_BUFFERED_BYTES;
}

const char* page_text(uint16_t *usage_page, uint16_t *page ){

	switch(*usage_page){
		case HID_USAGE_PAGE_GENERIC_DESKTOP_PAGE:
				if (*page > HID_GENERIC_DESKTOP_PAGE_MAX) return NULL;
				return hid_generic_desktop_page_text[*page];
		case HID_USAGE_PAGE_CONSUMER_PAGE:
				if (*page > HID_CONSUMER_PAGE_MAX) return NULL;
				return hid_consumer_page_item_text[*page];
		default:
				return NULL;
	}
}

int16_t print_singed_int(const uint8_t size,const uint32_t data){
	int16_t b1 = 0x01 << ((8* size) -1);
	int16_t b2 = 0x01 << (8* size) ;
	if (size <= 0)
		return 0;
	if (data <= (b1 - 1))
		return (int16_t) data;
	return -1 * (b2 -data);
}

int32_t libhid_count(const libhid_report_descriptor_t *raw_report){
	uint8_t hid_size;
	uint32_t i = 0;
	int32_t count = 0;

	while(i < raw_report->size){

		hid_size = raw_report->value[i] & HID_SIZE;

		if(hid_size == 3) // 8 * 3 is 24 bits move them over to 32 bit
				hid_size = 4;

		if(i + hid_size >= raw_report->size)
				return -EPROTO;

		i += 1 + hid_size;
		++count;
	}
	return count;
}

void libhid_descriptor_item_create(hid_item_t *item){
	item->text = NULL;
	item->subtext = NULL;
	item->size = 0; 
}

void libhid_descriptor_item_destroy(hid_item_t *item){

	if(item->text != NULL) {
		free(item->text);
		item->text = NULL;
	}
	if(item->subtext != NULL) {
		free(item->subtext);
		item->subtext = NULL;
	}
	item->size = 0;
}

int32_t libhid_descriptor_create(const libhid_report_descriptor_t *raw_report, hid_descriptor_t *hid_descriptor){
	int32_t result = libhid_count(raw_report);
	if (result < 0) return result;
	hid_descriptor->items_size = (int16_t) result;
	hid_descriptor->items = malloc(hid_descriptor->items_size * sizeof(hid_item_t));
	int16_t i=0;
	for(; i < hid_descriptor->items_size; i++){
		libhid_descriptor_item_create(&(hid_descriptor->items[i]));
	}

	return libhid_descriptor(raw_report, hid_descriptor);
}

void libhid_descriptor_destroy(hid_descriptor_t *descriptor){
	if(descriptor->items_size  == 0 && descriptor->items == NULL)
		return;

	if (descriptor->items == NULL){
		descriptor->items_size =0;
		return;
	}
	int32_t i= 0;
	for(; i< descriptor->items_size; i++){
		libhid_descriptor_item_destroy(&(descriptor->items[i]));
	}
	free(descriptor->items);
	descriptor->items = NULL;
	descriptor->items_size =0;
}

int32_t libhid_descriptor(const libhid_report_descriptor_t *raw_report, hid_descriptor_t *descriptor){
	int16_t descriptor_index=0;
	uint16_t page, usage_page;
	uint32_t i=0, j=0;
	char* text = "";
	char* subtext = "";
	const char * temp;
	char buf[256];
	hid_main_item_text_t field_text;
	uint8_t parts[4];	 
	while(i < raw_report->size){
		uint8_t  value = raw_report->value[i];
		uint8_t  size = value & HID_SIZE;
		uint16_t hid = value & HID_TYPE;
		uint32_t data = 0;

		if(size == 3) // 8 * 3 is 24 bits move them over to 32 bit
			size = 4;

		if(i + size >= raw_report->size)
			return -EPROTO;
		memset(parts, 0, sizeof(parts));
		for (j = 0; j < size; j++){
			parts[j] = raw_report->value[i + j + 1];
			data |= raw_report->value[i + j + 1] << (j * 8); //hidraw_report_descriptor
		}

		hid_32bit_field_t bit_field;
		memcpy(&bit_field, parts , sizeof(parts));
		switch (hid)
		{
				/**
				 * Global
				*/
				case HID_GLOBAL_REPORT_ID:
						text = "REPORT ID";
						snprintf(buf, sizeof(buf), "(%d)", data);
						subtext = buf;
						break;
				case HID_GLOBAL_LOGICAL_MINIMUM :
						text= "LOGICAL_MINIMUM";
						snprintf(buf, sizeof(buf), "(%d)", print_singed_int(size, data));
						subtext = buf;
						break;
				case HID_GLOBAL_LOGICAL_MAXIMUM :
						text= "LOGICAL_MAXIMUM";
						snprintf(buf, sizeof(buf), "(%d)", print_singed_int(size, data));
						subtext = buf;
						break;
				case HID_GLOBAL_PHYSICAL_MINIMUM:
						text= "PHYSICAL_MINIMUM";
						snprintf(buf, sizeof(buf), "(%d)", print_singed_int(size, data));
						subtext = buf;
						break;
				case HID_GLOBAL_PHYSICAL_MAXIMUM:
						text= "PHYSICAL_MAXIMUM";
						snprintf(buf, sizeof(buf), "(%d)", print_singed_int(size, data));
						subtext = buf;
						break;
				case HID_GLOBAL_UNIT_EXPONENT   : text= "UNIT_EXPONENT"; break;
				case HID_GLOBAL_UNIT            : text= "UNIT"; break;
				case HID_GLOBAL_REPORT_SIZE     : text= "REPORT_SIZE";
						snprintf(buf, sizeof(buf), "(%d)", data);
						subtext = buf;
						break;
				case HID_GLOBAL_REPORT_COUNT    : text= "REPORT_COUNT";
						snprintf(buf, sizeof(buf), "(%d)", data);
						subtext = buf;
						break;
				case HID_GLOBAL_USAGE_PAGE:
						text="USAGE PAGE";
						usage_page = data;
						if (usage_page > 0xFF00){
							snprintf(buf, sizeof(buf), "(Vendor defined 0x%02hX)", data);
							subtext = buf;
							break;
						}
						if (usage_page > HID_USAGE_PAGE_MAX){
							break;
						}
						temp = hid_usage_page_text[usage_page];

						if (temp == NULL){
							break;
						}
						snprintf(buf, sizeof(buf), "(%s)", temp);
						subtext = buf;
						break;
				/**
				 * MAIN
				 */
				case HID_MAIN_INPUT:
						text="INPUT";
						hid_main_item_text(&bit_field,&field_text, HID_MAIN_INPUT);
						snprintf(buf, sizeof(buf), "(%s,%s,%s,%s,%s,%s,%s,%s)",
										field_text.bit_00,
										field_text.bit_01,
										field_text.bit_02,
										field_text.bit_03,
										field_text.bit_04,
										field_text.bit_05,
										field_text.bit_06,
										field_text.bit_08);
						subtext = buf;
						break;

				case HID_MAIN_OUTPUT:
						text="OUTPUT";

						hid_main_item_text(&bit_field, &field_text,HID_MAIN_OUTPUT );
						snprintf(buf, sizeof(buf), "(%s,%s,%s,%s,%s,%s,%s,%s,%s)",
										field_text.bit_00,
										field_text.bit_01,
										field_text.bit_02,
										field_text.bit_03,
										field_text.bit_04,
										field_text.bit_05,
										field_text.bit_06,
										field_text.bit_07,
										field_text.bit_08);
						subtext = buf;
						break ;

				case HID_MAIN_FEATURE:
						text= "FEATURE";
						hid_main_item_text(&bit_field,&field_text, HID_MAIN_FEATURE);
						snprintf(buf, sizeof(buf), "(%s,%s,%s,%s,%s,%s,%s,%s)",
										field_text.bit_00,
										field_text.bit_01,
										field_text.bit_02,
										field_text.bit_03,
										field_text.bit_04,
										field_text.bit_05,
										field_text.bit_06,
										field_text.bit_08);
						subtext = buf;
						break;
				case HID_MAIN_COLLECTION:
						text= "BEGIN COLLECTION";
						
						if (data > HID_COLLECTION_MAX)
							break;
						temp = hid_main_item_collection_text[data];
						if (temp == NULL)
								break;
						snprintf(buf, sizeof(buf), "(%s)", temp);
						subtext = buf;
						break;
				case HID_MAIN_END_COLLECTION:
						text="END COLLECTION";
						break;

				case HID_LOCAL_USAGE:
						text ="USAGE";
						page = data;

						temp = page_text(&usage_page, &page);
						if (temp == NULL){
							snprintf(buf, sizeof(buf), "(0x%02hX)", data);
						}else {
							snprintf(buf, sizeof(buf), "(%s)",temp);
						}

						subtext = buf;
						break;
				case HID_LOCAL_USAGE_MAXIMUM:
						text ="USAGE MAXIMUM";
						snprintf(buf, sizeof(buf), "(0x%02hX)", data);
						subtext = buf;
						break;
				case HID_LOCAL_USAGE_MINIMUM:
						text ="USAGE MINIMUM";
						snprintf(buf, sizeof(buf), "(0x%02hX)", data);
						subtext = buf;
						break;
				default:
						break;
		}
		switch (size)
		{
			case 1:
				descriptor->items[descriptor_index].data.uint8= (uint8_t) data;
				break;
			case 2:
				descriptor->items[descriptor_index].data.uint16= (uint16_t) data;
				break;
			case 3: // 3 is unlikely... (8*3 = 24 which is not a normal size...)  
			case 4:
				descriptor->items[descriptor_index].data.uint32= (uint32_t) data;
				break;		
			default:
				descriptor->items[descriptor_index].data.none = 0;
				break;
		}
		descriptor->items[descriptor_index].size = size;
		descriptor->items[descriptor_index].type = hid;
		descriptor->items[descriptor_index].value = value;
		descriptor->items[descriptor_index].text = strdup((char *)text);
		descriptor->items[descriptor_index].subtext = strdup((char *)subtext);

		memset(buf, 0, strlen(buf));
		i += 1 + size;
		++descriptor_index;
	}

	return 0;
}

void libhid_descriptor_print_tab(const hid_descriptor_t *descriptor, const uint8_t spaces){
	
  uint8_t tab =4, tab_next=4,value;
  uint32_t i, j;
	for(i =0; i < descriptor->items_size; i++){
    tab = tab_next;
    value = descriptor->items[i].value;
		switch (descriptor->items[i].type)
		{
      case HID_MAIN_COLLECTION:
        tab_next+=2;
        break;
      case HID_MAIN_END_COLLECTION:
        tab_next-=2;
				tab-=2;
        break;
      default:
        break;
    }
		for(j=0; j< spaces; j++){
			printf(" ");
		}
    switch (descriptor->items[i].size)
		{
				case 0:
						printf("  0x%02hX\t\t\t\t ", value);
						break;
				case 1:
						printf("  0x%02hX 0x%02hX\t\t\t", value, descriptor->items[i].data.uint8);
						break;
				case 2:
						printf("  0x%02hX 0x%02hX 0x%02hX\t\t", value, descriptor->items[i].data.uint16 & 0xff , (descriptor->items[i].data.uint16 >> 8) & 0xff);
						break;
				case 3:
						printf("  0x%02hX 0x%02hX 0x%02hX 0x%02hX\t", value, descriptor->items[i].data.uint32 & 0xff , (descriptor->items[i].data.uint32 >> 8) & 0xff, (descriptor->items[i].data.uint32 >> 16) & 0xff);
						break;
				case 4:
						printf("  0x%02hX 0x%02hX 0x%02hX 0x%02hX 0x%02hX\t", value,(descriptor->items[i].data.uint32 >>  0) & 0xff, 
																																			  (descriptor->items[i].data.uint32 >>  8) & 0xff, 
																																			  (descriptor->items[i].data.uint32 >> 16) & 0xff, 
																																			  (descriptor->items[i].data.uint32 >> 24) & 0xff);
						break;
				default:
						break;
		}
    printf("%*s", tab , "");
    printf("%s%s\n" , descriptor->items[i].text, descriptor->items[i].subtext);
  }

}
void libhid_descriptor_print(const hid_descriptor_t *descriptor){
	libhid_descriptor_print_tab(descriptor, 0);
}
