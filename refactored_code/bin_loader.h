#ifndef BIN_LOADER_H
#define BIN_LOADER_H

#include "storage_type.h"
#include "loader.h"
#include <string>
using namespace std; 

class bin_loader: public loader {
    public:
        bin_loader() {};
        virtual ~bin_loader() {}

        /**
         * function that returns a copy of storage with the double values contained in the source bin file
         * @param storage storage that will store the values of source
         * @param source path to the source bin file containg double values
         * @throws ios_base::failure if source can not be opened
         * @return storage with the values of the source file
        */
        virtual storage_type& write(storage_type& storage, const std::string source);
};


#endif // BIN_LOADER_H