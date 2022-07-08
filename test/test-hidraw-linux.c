#include "hidraw-linux.h"

/**
 * Main entry method
 * @param [in] argc arguments count
 * @param [in] argv arguments vector
 */
int main(int argc, char** argv){
	hidraw_collection_t hid_devices;
	hidraw_collection_create(&hid_devices);
	printf("Hid Device Count: %d\n", hid_devices.size);
	hidraw_collection_print(&hid_devices);
	hidraw_collection_delete(&hid_devices);
	return EXIT_SUCCESS;
}

