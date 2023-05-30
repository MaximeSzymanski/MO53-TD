#ifndef TEXT_WRITER_H
#define TEXT_WRITER_H

#include "storage_type.h"
#include "writer.h"
#include <string>

using namespace std; 


/**
 * text_writer implements the writer class to write data in a text file
 * from a storage_type object 
 * @see writer
 * @see writer_type
*/
class text_writer: public writer {
    private:
        /**
         * path to the destination text file
        */
        string destination;

    public:
        /**
         * default constructor
        */
        text_writer(): destination("output.txt"){};
        /**
         * constructor used to set the the path to the destination text file
         * @param s path for the source bin file used by the write function
         * @see #write(storage_type&) 
        */
        text_writer(const string& p_destination): destination(p_destination){};
        /**
         * copy constructor
         * @param p_text_writer text_writer to copy from
        */
        text_writer(const text_writer& p_text_writer): destination(p_text_writer.destination){};
        /**
         * copy operator
         * @param p_text_writer text_writer to copy from
        */
        text_writer& operator=(const text_writer& p_text_writer);
        /**
         * destructor function
        */
        virtual ~text_writer() {};

        /**
         * Function that writes data from a storage_type object into a bin file.
         * Use this {@link #text_writer(const string&) text_writer constructor} to set the path to the destination bin file.
         * @param storage object that stores the data the write function uses
         * @throws write_exception when an error linked to writing occurs
        */
        virtual void write(storage_type& storage);

};


#endif // TEXT_WRITER_H