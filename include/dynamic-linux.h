/**
 * @file dynamic-linux.h
 * @brief Private interface for Generic Dynamic library code Linux.
 * 
 * Include the header file with the code:
 * @code
 * #include <dynamic-library.h>
 * @endcode
 */
#ifndef __DYNAMIC_LIBRARY_LINUX_H__
#define __DYNAMIC_LIBRARY_LINUX_H__
#include <dlfcn.h>
#include <stdlib.h>

/**
 * Load function; 
 * This will changer per operating system;
 *
 * @param[in] libptr reference to dlopen of lib*.*.[so|dll] file
 * @param[in] name of functions to load
 */
void* vtable_load_function(void* libptr, const char* name){
	const char* dlsym_error = dlerror();
	void* ptr = dlsym(libptr, name);
	dlsym_error = dlerror();
	return (dlsym_error)? NULL: ptr;
}



/**
 * Load library function; 
 * @param[in] lib_path path to the library
 * @returns Pointer to the library or @c NULL Pointer
 */
void* load_library(const char* lib_path){
	void* ptr = dlopen(lib_path, RTLD_LAZY);
	const char* dlsym_error = dlerror();
	return (dlsym_error)? NULL: ptr;
}
/** 
 * Can be used if library function calls are no longer needed.
 * Needed if you don't want to run out of virtual address space.
 * @param[out] libptr that will be deallocated
 * @returns negative after result. 
 */
int close_library(void* libptr){
	if (libptr == NULL) return 0;
	return dlclose(libptr);
}
#endif