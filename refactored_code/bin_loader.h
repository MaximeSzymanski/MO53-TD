#ifndef BIN_LOADER_H
#define BIN_LOADER_H

#include "storage_type.h"
#include "loader.h"
#include <string>

using namespace std; 


/**
 * bin_loader implements the loader class to load data from a binary file
 * in an object that inherits from storage_type
 * @see loader
*/
class bin_loader: public loader {
    public:
        /**
         * default constructor
        */
        bin_loader(): loader("loader.bin"){};
        /**
         * constructor used to set the the path to the source file
         * @param s path for the source file used by the load function
         * @see #load(storage_type&) 
        */
        bin_loader(const string& s): loader(s){};
        /**
         * destructor function
        */
        virtual ~bin_loader() {}

        /**
         * Function that returns a copy of {@code storage] with the double values contained in the source binary file
         * Use this {@link #bin_loader(const string&) bin_loader constructor} to set the path to the source file}
         * @param storage storage that will store the values of source
         * @param storage a copy of storage is returned with the values stored in the source binary file
         * @throws ios_base::failure if source can not be opened
         * @return a copy of storage with the values of the source binary file
        */
        virtual storage_type& load(storage_type& storage);
};


#endif // BIN_LOADER_H