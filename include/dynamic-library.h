/**
 * @file dynamic-library.h
 * @brief Public interface for Generic Dynamic library code.
 * 
 * Include the header file with the code:
 * @code
 * #include <dynamic-library.h>
 * @endcode
 */
#ifndef _DYNAMIC_LIBRARY_FN_
#define _DYNAMIC_LIBRARY_FN_
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef __linux__
    #include "dynamic-linux.h"
#elif defined(WINVER)
    #include "dynamic-win.h"
#endif


/**
 * Breaks up working directory argv[0] by taking the part upto the last slash
 * Then appends the lib name to the end
 * 
 * @param[in] working_dir absolute path to the folder with the binary. In most cases argv[0]. 
 * @param[in] lib_name name if library you wish to load. 
 */
char* get_lib_path(const char* working_dir, const char* lib_name ){
    
    char * path = strdup(working_dir);
    char * pch  = strrchr(path,'/'); // get index of last slash
    path[pch-path] = '\0'; // end string at index

    char * lib_path =  malloc(strlen(lib_name) + strlen(path) + 1);
    if (lib_path == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(lib_path, path);    
    strcpy(lib_path + strlen(path) , lib_name);
    free(path);
    return lib_path;
}

#endif
