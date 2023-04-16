#ifndef TEXT_LOADER_H
#define TEXT_LOADER_H

#include "storage_type.h"
#include "loader.h"
#include <string>
using namespace std; 

class text_loader: public loader {
    public:
        text_loader() {}
        text_loader(const text_loader& storage) {}
        text_loader& operator=(const text_loader storage) {return *this;}
        virtual ~text_loader() {}

        /**
         * function that returns a copy of storage with the double values contained in the source text file
         * @param storage storage that will store the values of source
         * @param source path to the source text file containg double values
         * @throws ios_base::failure if source can not be opened
         * @return storage with the values of the source file
        */
        virtual storage_type& write(storage_type& storage, std::string source);
};


#endif // TEXT_LOADER_H