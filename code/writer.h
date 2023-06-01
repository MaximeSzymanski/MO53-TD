#ifndef WRITER_H
#define WRITER_H

#include "storage_type.h"
#include <string>
#include <stdexcept>
#include <string>

using namespace std; 

/**
 * Exception used by the descendants of the writer class when an error 
 * linked to writing occurs 
 * @see writer
*/
class write_exception: public runtime_error {
    public:
        write_exception(const string &message): runtime_error(message) {}
};

/**
 * Writer is an abstract class used to write data from an object that inherits from storage_type
 * @see storage_type
*/
class writer {
    public:
        /**
         * default constructor
        */
        writer() {};
        /**
         * destructor function
        */
        virtual ~writer() {};
        /**
         * Pure virtual function that writes data from a storage_type object.
         * @param storage object that stores the data the write function uses
         * @throws write_exception when an error linked to writing occurs
        */
        virtual void write(storage_type& storage) = 0;

};


#endif // WRITER_H