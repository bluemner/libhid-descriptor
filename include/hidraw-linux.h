/**
 * @file hidraw-linux.h
 * @brief Public interface for hidraw-linux.
 * 
 * Include the header file with the code:
 * @code
 * #include <hidraw-linux.h>
 * @endcode
 */

#include <inttypes.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <linux/hidraw.h>
#include <linux/types.h>
#include <linux/input.h>
#include <linux/hid.h>
#include <linux/limits.h> 
#include <dirent.h>


#ifndef STRING_EQUALS
  #define STRING_EQUALS(lhs, rhs) strcmp(lhs, rhs) == 0
#endif
#ifndef STRING_STARTS_WITH
  #define STRING_STARTS_WITH(prefix, string) strncmp(prefix, string, strlen(prefix)) == 0
#endif

typedef struct hidraw_report_descriptor hid_raw_descriptor_t;


typedef struct hidraw_input {
  char* input;
  char* event_path;
  char* device_name;
  struct input_id id;
} hidraw_input_t;

/**
 *  Hidraw
 */
typedef struct hidraw {
  char* name; // hidraw name 
  char* hidraw_path; // hidraw file path
  hid_raw_descriptor_t hid_raw_descriptor;
  hidraw_input_t * inputs;
  uint16_t input_count;
} hidraw_t;

/**
 * Hidraw collection
 */
typedef struct hidraw_collection {
  hidraw_t * items; // items in collection
  uint16_t size;    // length of the collection
} hidraw_collection_t;


/**
 * Get count of files in directory excluding the `.` and `..` symbolic links 
 * @param[in] directory to which get file count
 * @return file count
 */
int32_t file_count(const char* directory);

/**
 * @param[in] path path to open should be absolute
 * @param[out] buffer for file to load in
 * @param[in] buffer_size max value for previous argument
 * @return size of file or negative number if error.
 */
int open_file(const char* path, char *buffer, const size_t buffer_size);

/**
 * @param[in] bustype number from input
 * @return name of bus type
 */
const char* bustype_string(int bustype);

/**
 * Load HID description
 * @param[in] path path to hid description
 * @param[out] descriptor hidraw result object
 */
int load_hid_descriptor(const char* path, hid_raw_descriptor_t *descriptor);


int device_input_directory(const char* directory, hidraw_input_t* hid);

/*
 * Get /sys/class/hidraw/%s/device/input/
*/
int device_directory(const char* directory, hidraw_t* hid);

/**
 * Allocates memory for @c hidraw_t
 * @param[out] hid object that will be allocated 
 */
void hidraw_create(hidraw_t * hid);

/**
 * Deallocates memory for @c hidraw_t
 * In most cases should be called after \c hidraw_create
 * @param [out] hid object that will be allocated 
 */
void hidraw_delete(hidraw_t * hid);

/**
 * Sets @c hidraw_input_t to default state will all @a NULL values
 * @param[out] hid object that will be allocated
 */
void hidraw_input_create(hidraw_input_t* hid);

/** 
 * Deallocates / frees memory used by @c hidraw_input_t. 
 * @param[out] hid object that will be deallocated
 */
void hidraw_input_delete(hidraw_input_t * hid);


/**
 * Get collection of HID Raw information from /sys/class/hidraw.
 * 
 * Remember to run hidraw_collection_delete when done!
 * 
 * @param[out] collection of hidraw; one item for each dev list in /sys/class/hidraw
 */
void hidraw_collection_create(hidraw_collection_t *collection);

/**
 * Deallocate memory
 * @param[out] collection that will be deallocated
 */
void hidraw_collection_delete(hidraw_collection_t *collection);

/**
 * Print method for debugging / output to stdout
 * @param[out] collection to print to stdout
 */
void hidraw_collection_print(hidraw_collection_t *collection);
