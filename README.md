# libhid-descriptor

* [Summary](#summary)
* [lib.hid.descriptor](#lib-hid-descriptor)
  * [Sample Descriptor](#sample-descriptor)
  * [Sample Profile](#sample-profile)
  * [Descriptor Usage](#descriptor-usage)
    * [static](#static)
    * [dynamic](#dynamic)
* [lib.hid.rawlinux](#lib-hid-rawlinux)
* [hidraw-linux-util](#linux-util)


# Summary
library for parsing the USB Human interface device (hid) descriptor.


> Note: Not all usage tables are not yet implemented.
> Code is not recommended for production use.

## Useful information
 * [Usage Tables](https://www.usb.org/document-library/hid-usage-tables-13)
   * [PDF USB hut1_3_0.pdf](https://usb.org/sites/default/files/hut1_3_0.pdf)
 * [Class Definition](https://www.usb.org/document-library/device-class-definition-hid-111)   
   * [PDF USB hid1_11.pdf](https://www.usb.org/sites/default/files/documents/hid1_11.pdf)


There is also a hid raw library for linux which will access all hid devices and display there profile. 

[↥ TOP ↥](#libhid-descriptor)


# lib-hid-descriptor

Takes the HID descriptor and makes a profile

## Sample Descriptor

```
Hid Descriptor:
  05 01 09 06 a1 01 05 07 19 e0 
  29 e7 15 00 25 01 75 01 95 08 
  81 02 95 01 75 08 81 01 95 03 
  75 01 05 08 19 01 29 03 91 02 
  95 05 75 01 91 01 95 06 75 08 
  15 00 26 ff 00 05 07 19 00 2a 
  ff 00 81 00 c0 
```
[↥ TOP ↥](#libhid-descriptor)
## Sample Profile
```
Hid Profile:
  0x05 0x01			    USAGE PAGE(Generic Desktop Page)
  0x09 0x06			    USAGE(Keyboard)
  0xA1 0x01			    BEGIN COLLECTION(Application (mouse, keyboard))
  0x05 0x07			      USAGE PAGE(Keyboard/Keypad Page)
  0x19 0xE0			      USAGE MINIMUM(0xE0)
  0x29 0xE7			      USAGE MAXIMUM(0xE7)
  0x15 0x00			      LOGICAL_MINIMUM(0)
  0x25 0x01			      LOGICAL_MAXIMUM(1)
  0x75 0x01			      REPORT_SIZE(1)
  0x95 0x08			      REPORT_COUNT(8)
  0x81 0x02			      INPUT(Data,Variables,Absolute,No Wrap,Linear,Preferred State,No Null position,Bit Field)
  0x95 0x01			      REPORT_COUNT(1)
  0x75 0x08			      REPORT_SIZE(8)
  0x81 0x01			      INPUT(Constant,Array,Absolute,No Wrap,Linear,Preferred State,No Null position,Bit Field)
  0x95 0x03			      REPORT_COUNT(3)
  0x75 0x01			      REPORT_SIZE(1)
  0x05 0x08			      USAGE PAGE(LED Page)
  0x19 0x01			      USAGE MINIMUM(0x01)
  0x29 0x03			      USAGE MAXIMUM(0x03)
  0x91 0x02			      OUTPUT(Data,Variables,Absolute,No Wrap,Linear,Preferred State,No Null position,Non Volatile,Bit Field)
  0x95 0x05			      REPORT_COUNT(5)
  0x75 0x01			      REPORT_SIZE(1)
  0x91 0x01			      OUTPUT(Constant,Array,Absolute,No Wrap,Linear,Preferred State,No Null position,Non Volatile,Bit Field)
  0x95 0x06			      REPORT_COUNT(6)
  0x75 0x08			      REPORT_SIZE(8)
  0x15 0x00			      LOGICAL_MINIMUM(0)
  0x26 0xFF 0x00		  LOGICAL_MAXIMUM(255)
  0x05 0x07			      USAGE PAGE(Keyboard/Keypad Page)
  0x19 0x00			      USAGE MINIMUM(0x00)
  0x2A 0xFF 0x00		  USAGE MAXIMUM(0xFF)
  0x81 0x00			      INPUT(Data,Array,Absolute,No Wrap,Linear,Preferred State,No Null position,Bit Field)
  0xC0				     END COLLECTION
```
[↥ TOP ↥](#libhid-descriptor)
## Descriptor Usage
### Static
```c
int main(){
  libhid_report_descriptor_t report = { .size=1 , .value= { 05 , 01 } };
  hid_descriptor_t descriptor; 
  
  libhid_descriptor_create(&report,&descriptor); // Populate descriptor form report.value.
  libhid_descriptor_print(&descriptor); // Prints out text
  libhid_descriptor_destroy(&descriptor); // Clean up memory
}
```
### Dynamic 
> Have not verified / tested the windows implementation yet; Proceeded with caution.
```c
#include "hid-descriptor-vtable.h" 
 
int main(int argc, char** argv){
	char* lib_path = get_lib_path(argv[0], "/lib.hid.descriptor.so");
	printf("lib path: %s\n", lib_path);
	void* lib_ptr  = load_library(lib_path);
	free(lib_path);
	lib_path= NULL;
	libhid_descriptor_virtual_table vtable;
	libhid_descriptor_virtual_table_load(lib_ptr, &vtable);
	if( libhid_descriptor_virtual_table_validate(&vtable)){ 
		fprintf(stderr, "vtable validatin failed\n");
		return EXIT_FAILURE;
	}

  vtable->libhid_descriptor_create.call(&report,&descriptor); 
  vtable->libhid_descriptor_print.call(&descriptor); 
  vtable->libhid_descriptor_destroy.call(&descriptor);

  return 0;
}
```
[↥ TOP ↥](#libhid-descriptor)
# lib-hid-rawlinux

Library that can be used to access the hid raw information. This is similar to some of the systemd libraries.
## Sample
```c
#include "hid-descriptor-vtable.h"
#include "hidraw-linux-vtable.h"
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
}
```
[↥ TOP ↥](#libhid-descriptor)
# Linux util

Utility that will out print all hid profiles for all connected devices.

>You may need to run with sudo / elevated privileges to get hid profile. 
>This will generate a message: 
>```
>You must run as elevated user or be in a group that has access to: /dev/hidraw<N>
>```
> Where `<N>` is the hid raw number


## Compile
```
make hidraw-linux-lib
```
## Running
```
./hidraw-linux-util
```
### Output
```
lib path: bin/lib.hid.descriptor.so
lib path: bin/lib.hid.rawlinux.so
Hid Device Count: 12
hidraw8
	Hid Path: /dev/hidraw8
	Hid Descriptor Size: 65
	Hid Descriptor:
		05 01 09 06 a1 01 05 07 19 e0 
		29 e7 15 00 25 01 75 01 95 08 
		81 02 95 01 75 08 81 01 95 03 
		75 01 05 08 19 01 29 03 91 02 
		95 05 75 01 91 01 95 06 75 08 
		15 00 26 ff 00 05 07 19 00 2a 
		ff 00 81 00 c0 
	Hid Profile:
          0x05 0x01			    USAGE PAGE(Generic Desktop Page)
          0x09 0x06			    USAGE(Keyboard)
          0xA1 0x01			    BEGIN COLLECTION(Application (mouse, keyboard))
          0x05 0x07			      USAGE PAGE(Keyboard/Keypad Page)
          0x19 0xE0			      USAGE MINIMUM(0xE0)
          0x29 0xE7			      USAGE MAXIMUM(0xE7)
          0x15 0x00			      LOGICAL_MINIMUM(0)
          0x25 0x01			      LOGICAL_MAXIMUM(1)
          0x75 0x01			      REPORT_SIZE(1)
          0x95 0x08			      REPORT_COUNT(8)
          0x81 0x02			      INPUT(Data,Variables,Absolute,No Wrap,Linear,Preferred State,No Null position,Bit Field)
          0x95 0x01			      REPORT_COUNT(1)
          0x75 0x08			      REPORT_SIZE(8)
          0x81 0x01			      INPUT(Constant,Array,Absolute,No Wrap,Linear,Preferred State,No Null position,Bit Field)
          0x95 0x03			      REPORT_COUNT(3)
          0x75 0x01			      REPORT_SIZE(1)
          0x05 0x08			      USAGE PAGE(LED Page)
          0x19 0x01			      USAGE MINIMUM(0x01)
          0x29 0x03			      USAGE MAXIMUM(0x03)
          0x91 0x02			      OUTPUT(Data,Variables,Absolute,No Wrap,Linear,Preferred State,No Null position,Non Volatile,Bit Field)
          0x95 0x05			      REPORT_COUNT(5)
          0x75 0x01			      REPORT_SIZE(1)
          0x91 0x01			      OUTPUT(Constant,Array,Absolute,No Wrap,Linear,Preferred State,No Null position,Non Volatile,Bit Field)
          0x95 0x06			      REPORT_COUNT(6)
          0x75 0x08			      REPORT_SIZE(8)
          0x15 0x00			      LOGICAL_MINIMUM(0)
          0x26 0xFF 0x00		      LOGICAL_MAXIMUM(255)
          0x05 0x07			      USAGE PAGE(Keyboard/Keypad Page)
          0x19 0x00			      USAGE MINIMUM(0x00)
          0x2A 0xFF 0x00		      USAGE MAXIMUM(0xFF)
          0x81 0x00			      INPUT(Data,Array,Absolute,No Wrap,Linear,Preferred State,No Null position,Bit Field)
          0xC0				     END COLLECTION
	Input Count: 1
		Index: 0
		Input: input14
		Event Path: /dev/input/event12
		Device Name: Logitech Gaming Keyboard G105
		Id: 
		  Bustype: 0x0003
		  Product: 0xc248
		  Vendor:  0x046d
		  Version: 0x0110
```
[↥ TOP ↥](#libhid-descriptor)