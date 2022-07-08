/**
 * @file dynamic-linux.h
 * @brief Private interface for Generic Dynamic library code Linux.
 * 				Attempts to map the windows DLL library to a more generic one. 
 * Include the header file with the code:
 * @code
 * #include <dynamic-library.h>
 * @endcode
 */
#ifndef __DYNAMIC_LIBRARY_WIN_H__
#define __DYNAMIC_LIBRARY_WIN_H__
#include <windows.h>
#include <stdlib.h>

/**
 * Load function; 
 * This will changer per operating system;
 *
 * @param[in] libptr reference to dlopen of lib*.*.[so|dll] file
 * @param[in] name of functions to load
 */
void* vtable_load_function(void* libptr, const char* name){
	FARPROC fp;
  fp= GetProcAddress ((HINSTANCE)handle, name);
	return (!fp)? NULL: (void *)(intptr_t)fp;
}

void* load_library(const char* lib_path){
	HINSTANCE hInst;
  hInst= LoadLibrary (lib_path);
	return hInst;
}
/** 
 * Can be used if library function calls are no longer needed.
 * Needed if you don't want to run out of virtual address space.
 * @param[out] libptr that will be deallocated
 */
int close_library(void* libptr){
	if (libptr == NULL) return 0;
  BOOL ok = FreeLibrary ((HINSTANCE)handle);
	return ok? 0: -1;
}
#endif
