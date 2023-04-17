#ifndef LOADER_H
#define LOADER_H

#include "storage_type.h"
#include <string>
using namespace std; 

class loader {
    public:
        string source;

    public:
        loader(): source("load.txt"){};
        loader(const string& s): source(s){};
        virtual ~loader() {};

        /**
         * Pure virtual function that returns a copy of storage with the double values contained in the source file
         * @param storage storage that will store the values of source
         * @throws ios_base::failure if source can not be opened
         * @return storage with the values of the source file
        */
        virtual storage_type& load(storage_type& storage) = 0;

};


#endif // LOADER_H