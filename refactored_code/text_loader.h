#ifndef TEXT_LOADER_H
#define TEXT_LOADER_H

#include "storage_type.h"
#include "loader.h"
#include <string>
using namespace std; 

class text_loader: public loader {
    public:
        text_loader(): loader("loader.bin"){};
        text_loader(const string& s): loader(s){};
        virtual ~text_loader() {}

        /**
         * function that returns a copy of storage with the double values contained in the source text file
         * @param storage storage that will store the values of source
         * @throws ios_base::failure if source can not be opened
         * @return storage with the values of the source file
        */
        virtual storage_type& load(storage_type& storage);
};


#endif // TEXT_LOADER_H