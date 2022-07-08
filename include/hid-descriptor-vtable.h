#ifndef __LIBHID_DESCRIPTOR_VTABLE_H__
#define __LIBHID_DESCRIPTOR_VTABLE_H__
#include "dynamic-library.h"
#include "hid-descriptor.h"

typedef union libhid_descriptor_print_fn {
    void *ptr;
    void (*call) (hid_descriptor_t *descriptor);
} libhid_descriptor_print_fn;
typedef union libhid_descriptor_print_tab_fn {
    void *ptr;
    void (*call) (hid_descriptor_t *descriptor, uint8_t spaces);
} libhid_descriptor_print_tab_fn;

typedef union libhid_descriptor_create_fn {
    void *ptr;
    int16_t (*call) (const libhid_report_descriptor_t *raw_report, hid_descriptor_t *hid_descriptor);
} libhid_descriptor_create_fn;

typedef union libhid_descriptor_destroy_fn {
    void *ptr;
    void (*call) (hid_descriptor_t *hid_descriptor);
} libhid_descriptor_destroy_fn;

typedef struct libhid_descriptor_virtual_table {
  libhid_descriptor_print_fn libhid_descriptor_print;
  libhid_descriptor_print_tab_fn libhid_descriptor_print_tab;
  libhid_descriptor_create_fn libhid_descriptor_create;
  libhid_descriptor_destroy_fn libhid_descriptor_destroy;
} libhid_descriptor_virtual_table;


/**
 * Load virtual table
 *
 * @param[in] libptr reference to dlopen of lib*.*.[so|dll] file
 * @param[in] vtable of functions to load
 */
void libhid_descriptor_virtual_table_load(void* libptr, libhid_descriptor_virtual_table *vtable){
	vtable->libhid_descriptor_print.ptr = vtable_load_function(libptr, "libhid_descriptor_print");
	vtable->libhid_descriptor_print_tab.ptr = vtable_load_function(libptr, "libhid_descriptor_print_tab");
	vtable->libhid_descriptor_create.ptr = vtable_load_function(libptr, "libhid_descriptor_create");
	vtable->libhid_descriptor_destroy.ptr = vtable_load_function(libptr, "libhid_descriptor_destroy");
}
/**
 * Clear virtual table
 *
 * @param[in] vtable to clear out
 */
void libhid_descriptor_virtual_table_close(libhid_descriptor_virtual_table *vtable){
	vtable->libhid_descriptor_print.ptr = NULL;
	vtable->libhid_descriptor_print_tab.ptr = NULL;
	vtable->libhid_descriptor_create.ptr = NULL;
	vtable->libhid_descriptor_destroy.ptr = NULL;
}
/**
 * Validate virtual table is loaded with address
 * 
 * @param[in] vtable to validate
 * @returns @c 0 if loaded successfully
 */
bool libhid_descriptor_virtual_table_validate(libhid_descriptor_virtual_table *vtable){
	if(vtable->libhid_descriptor_print.ptr ==0x0) return -1;
	if(vtable->libhid_descriptor_print_tab.ptr ==0x0) return -1;
    if(vtable->libhid_descriptor_create.ptr ==0x0) return -1;
	if(vtable->libhid_descriptor_destroy.ptr ==0x0) return -1;
	return 0;
}


#endif