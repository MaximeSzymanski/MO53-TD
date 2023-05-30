#ifndef SCREEN_WRITER_H
#define SCREEN_WRITER_H

#include "storage_type.h"
#include "writer.h"
#include <string>

using namespace std; 

/**
 * screen_writer implements the writer class to write data in the console
 * from a storage_type object 
 * @see writer
 * @see writer_type
*/
class screen_writer: public writer {
    public:
        /**
         * default constructor
        */
        screen_writer() {};
        /**
         * destructor function
        */
        virtual ~screen_writer() {};
        /**
         * Function that writes data from a storage_type object in the console
         * @param storage object that stores the data the write function uses 
        */
        virtual void write(storage_type& storage);

};


#endif // SCREEN_WRITER_H