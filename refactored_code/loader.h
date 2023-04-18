#ifndef LOADER_H
#define LOADER_H

#include "storage_type.h"
#include <string>
using namespace std; 

/**
 * Loader is an abstract class used to load data from a source file 
 * in an object that inherits from storage_type
 * @see storage_type
*/
class loader {
    protected:
        /**
         * path to the source file
        */
        string source;

    public:
        /**
         * default constructor
        */
        loader(): source("load.txt"){};
        /**
         * constructor used to set the the path to the source file
         * @param s path for the source file used by the load function
         * @see #load(storage_type&) 
        */
        loader(const string& s): source(s){};
        /**
         * destructor function
        */
        virtual ~loader() {};

        /**
         * Pure virtual function that returns a copy of storage with the double values contained in the source file
         * Use this {@link #loader(const string&) loader constructor} to set the path to the source file
         * @param storage a copy of storage is returned with the values stored in the source file
         * @throws ios_base::failure if source can not be opened
         * @return a copy of storage with the values of the source file
        */
        virtual storage_type& load(storage_type& storage) = 0;

};


#endif // LOADER_H