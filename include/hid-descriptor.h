/**
 * 
 * [Class Definition](https://www.usb.org/document-library/device-class-definition-hid-111]
 * PDF USB hid1_11.pdf https://www.usb.org/sites/default/files/documents/hid1_11.pdf
 * 
 * [Usage Tables](https://www.usb.org/document-library/hid-usage-tables-13)
 * PDF USB hut1_3_0.pdf https://usb.org/sites/default/files/hut1_3_0.pdf
 */
#ifndef __BAGPIPE_HID_PROFILE_H__
#define __BAGPIPE_HID_PROFILE_H__
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>

#include "hid-event-codes.h"

#ifndef HID_MAX_DESCRIPTOR_SIZE
  #define HID_MAX_DESCRIPTOR_SIZE 4096 // Size from HID MAX descriptor size in linux/hid.h
#endif


typedef struct libhid_report_descriptor {
	uint32_t size; // size descriptor
	uint8_t value[HID_MAX_DESCRIPTOR_SIZE]; // Descriptor
} libhid_report_descriptor_t;

/**
 * 
 * 6.2.2.1 Items Types and Tags [Class Definition] 
 */
typedef struct hid_item {
 union {
    bool     none; // 0
    uint8_t  uint8; // 1
    uint16_t uint16;  // 2
    uint32_t uint32;  // 3 => 4 (8*4 = 32)
  } data;
  uint8_t size; // hid size will use for data
  uint8_t type; // hid type code
  uint8_t value;
  char *text;
  char *subtext;
} hid_item_t;



/**
 * Hid Description
 */
typedef struct hid_descriptor {
  hid_item_t *items;
  uint16_t items_size;
} hid_descriptor_t;

typedef struct hid_32bit_field
{
    uint32_t bit_00: 1;
    uint32_t bit_01: 1;
    uint32_t bit_02: 1;
    uint32_t bit_03: 1;
    uint32_t bit_04: 1;
    uint32_t bit_05: 1;
    uint32_t bit_06: 1;
    uint32_t bit_07: 1;
    uint32_t bit_08: 1;
    uint32_t bit_09: 1;
    uint32_t bit_10: 1;
    uint32_t bit_11: 1;
    uint32_t bit_12: 1;
    uint32_t bit_13: 1;
    uint32_t bit_14: 1;
    uint32_t bit_15: 1;
    uint32_t bit_16: 1;
    uint32_t bit_17: 1;
    uint32_t bit_18: 1;
    uint32_t bit_19: 1;
    uint32_t bit_20: 1;
    uint32_t bit_21: 1;
    uint32_t bit_22: 1;
    uint32_t bit_23: 1;
    uint32_t bit_24: 1;
    uint32_t bit_25: 1;
    uint32_t bit_26: 1;
    uint32_t bit_27: 1;
    uint32_t bit_28: 1;
    uint32_t bit_29: 1;
    uint32_t bit_30: 1;
    uint32_t bit_31: 1;
} hid_32bit_field_t;

const char* page_text(uint16_t *usage_page, uint16_t *page );

/**
 * Need to fix the signed on data if its encoded using 2's complemnt
 * @param[in] size current HID_SIZE with fix where 3 => 4.
 * @param[in] data data the needs to be set correctly
*/
int16_t print_singed_int(const uint8_t size,const uint32_t data);

/**
 * Should create the item create
 * @param[out] item to be create will set all text values to null
 */
void libhid_descriptor_item_create(hid_item_t *item);


/**
 * Should create the item create
 * @param[out] item to be deallocate
 */
void libhid_descriptor_item_destroy(hid_item_t *item);

/**
 * 
 * @param[in]  raw_report raw hid descriptor
 * @param[out] descriptor descriptor profile that will store the data. 
 */
int32_t libhid_descriptor_create(const libhid_report_descriptor_t *raw_report, hid_descriptor_t *hid_descriptor);

/**
 * 
 * @param[out] descriptor descriptor profile that will store the data.
 */
void libhid_descriptor_destroy(hid_descriptor_t *descriptor);

/**
 * Get the number of items in the hid descriptor
 * @param[in] raw_report raw hid descriptor
 * @returns count of items in hid descriptor
 */
int32_t libhid_count(const libhid_report_descriptor_t *raw_report);

/**
 * Lib Hid Descriptor
 * 
 * @param[in]  raw_report raw hid descriptor
 * @param[out] descriptor descriptor profile that will store the data. 
 * @returns negative number if error
 */
int32_t libhid_descriptor(const libhid_report_descriptor_t *raw_report, hid_descriptor_t *descriptor);

/**
 * Prints the descriptor to stdout
 * @param[in] descriptor descriptor profile that will store the data.  
 * @param[in] spaces number of spaces to add in print statement
 */
void libhid_descriptor_print_tab(const hid_descriptor_t *descriptor, const uint8_t spaces);

/**
 * Print descriptor to standard out
 * @param[in] descriptor descriptor profile that will store the data.  
 */
void libhid_descriptor_print(const hid_descriptor_t *descriptor);
#endif
