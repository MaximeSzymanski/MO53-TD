#ifndef TEXT_LOADER_H
#define TEXT_LOADER_H

#include "storage_type.h"
#include "loader.h"
#include <string>
using namespace std; 

/**
 * text_loader implements the loader class to load data from a text file
 * in an object that inherits from storage_type
 * @see loader
*/
class text_loader: public loader {
    public:
        /**
         * default constructor
        */
        text_loader(): loader("loader.bin"){};
        /**
         * constructor used to set the the path to the source file
         * @param s path for the source file used by the load function
         * @see #load(storage_type&) 
        */
        text_loader(const string& s): loader(s){};
        /**
         * destructor function
        */
        virtual ~text_loader() {}

        /**
         * function that returns a copy of storage with the double values contained in the source text file
         * Use this {@link #text_loader(const string&) text_loader constructor} to set the path to the source file
         * @param storage storage that will store the values of source
         * @throws ios_base::failure if source can not be opened
         * @return storage with the values of the source file
        */
        virtual storage_type& load(storage_type& storage);
};


#endif // TEXT_LOADER_H