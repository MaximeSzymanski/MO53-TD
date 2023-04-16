#ifndef LOADER_H
#define LOADER_H

#include "storage_type.h"
#include <string>
using namespace std; 

class loader {
    public:
    
        loader() {};
        loader(const loader& vector) {};
        loader& operator=(const loader& loader) {return *this;};
        virtual ~loader() {};

        /**
         * Pure virtual function that returns a copy of storage with the double values contained in the source file
         * @param storage storage that will store the values of source
         * @param source path to the source file containg double values
         * @throws ios_base::failure if source can not be opened
         * @return storage with the values of the source file
        */
        virtual storage_type& write(storage_type& storage, std::string source) = 0;

};


#endif // LOADER_H