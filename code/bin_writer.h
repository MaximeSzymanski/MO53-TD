#ifndef BIN_WRITER_H
#define BIN_WRITER_H

#include "storage_type.h"
#include "writer.h"
#include <string>

using namespace std; 

/**
 * bin_writer implements the writer class to write data in a bin file
 * from a storage_type object 
 * @see writer
 * @see writer_type
*/
class bin_writer: public writer {
    private:
        /**
         * path to the destination bin file
        */
        string destination;

    public:
        /**
         * default constructor
        */
        bin_writer(): destination("output.bin"){};
        /**
         * constructor used to set the the path to the destination bin file
         * @param s path to the destination bin file used by the write function
         * @see #write(storage_type&) 
        */
        bin_writer(const string& p_destination): destination(p_destination){};
        /**
         * copy constructor
         * @param p_bin_writer bin_writer to copy from
        */
        bin_writer(const bin_writer& p_bin_writer): destination(p_bin_writer.destination){};
        /**
         * copy operator
         * @param p_bin_writer bin_writer to copy from
        */
        bin_writer& operator=(const bin_writer& p_bin_writer);
        /**
         * destructor function
        */
        virtual ~bin_writer() {};
        /**
         * Function that writes data from a storage_type object into a bin file.
         * Use this {@link #bin_writer(const string&) bin_writer constructor} to set the path to the destination bin file.
         * @param storage object that stores the data the write function uses
         * @throws write_exception when an error linked to writing occurs
        */
        virtual void write(storage_type& storage);

};


#endif // BIN_WRITER_H