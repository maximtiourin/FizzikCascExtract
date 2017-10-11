#include "includes/CascLib/CascLib.h"
#include <SimpleOpt.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const CSimpleOpt::SOption CMDOPTS[] = {    
    SO_END_OF_OPTIONS
};

/*
 * Command Line
 * exe <path_to_casc_storage> <path_to_listfile> <path_to_extract_destination>
 */
int main(int argc, char **argv) {
	//Handle command line arguments
	CSimpleOpt args(argc, argv, CMDOPTS);
	while (args.Next()) {
		if (args.LastError() == SO_SUCCESS) {

		}
		else {
		   cerr << "Invalid Argument: " << args.OptionText() << endl;
		   return -1;
		}
	}

	if (args.FileCount() != 3) {
		cerr << "Expected 3 filepaths: <path_to_casc_storage> <path_to_listfile> <path_to_extract_destination>" << endl;
		return -1;
	}

	HANDLE casc; //Casc Storage handle
	string listFile = args.File(0);
	string storage = args.File(1);
	string dest = args.File(2);

	//Remove trailing slashes for storage path if they exist
   if ((storage[storage.size() - 1] == '/') || (storage[storage.size() - 1] == '\\')) {
		storage = storage.substr(0, storage.size() - 1);
	}

	//Open casc storage
	if (!CascOpenStorage(storage.c_str(), 0, &casc)) {
		cerr << "Failed to open the casc storage '" << storage << "'" << endl;
		return -1;
	}

	CascCloseStorage(casc);

	return 0;
}