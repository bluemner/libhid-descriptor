#ifndef __LIBHID_RAW_LINUX_VTABLE_H__
#define __LIBHID_RAW_LINUX_VTABLE_H__

#include "dynamic-library.h"
#include "hidraw-linux.h"

typedef union hidraw_collection_create_fn {
    void *ptr;
    void (*call) (hidraw_collection_t *collection);
} hidraw_collection_create_fn;

typedef union hidraw_collection_delete_fn {
    void *ptr;
    void (*call) (hidraw_collection_t *collection);
} hidraw_collection_delete_fn;

typedef struct hidraw_virtual_table {
  hidraw_collection_create_fn hidraw_collection_create;
  hidraw_collection_delete_fn hidraw_collection_delete;
} hidraw_virtual_table;

/**
 * Load virtual table
 *
 * @param[in] libptr reference to dlopen of lib*.*.[so|dll] file
 * @param[in] vtable of functions to load
 */
void hidraw_virtual_table_load(void* libptr, hidraw_virtual_table *vtable){
	vtable->hidraw_collection_create.ptr = vtable_load_function(libptr, "hidraw_collection_create");
	vtable->hidraw_collection_delete.ptr = vtable_load_function(libptr, "hidraw_collection_delete");
}

/**
 * Delete virtual table
 *
 * @param[in] vtable to clear out
 */
void hidraw_virtual_table_delete(hidraw_virtual_table *vtable){
	vtable->hidraw_collection_create.ptr = NULL;
	vtable->hidraw_collection_delete.ptr = NULL;
}

/**
 * Validate virtual table is loaded with address
 * 
 * @param[in] vtable to validate
 * @returns @c 0 if loaded successfully
 */
bool hidraw_virtual_table_validate(const hidraw_virtual_table *vtable){
	if(vtable->hidraw_collection_create.ptr ==NULL) return -1;
	if(vtable->hidraw_collection_delete.ptr ==NULL) return -1;
	return 0;
}

#endif