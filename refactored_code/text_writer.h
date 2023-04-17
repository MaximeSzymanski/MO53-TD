#ifndef TEXT_WRITER_H
#define TEXT_WRITER_H

#include "storage_type.h"
#include "writer.h"
#include <string>

using namespace std; 

class text_writer: public writer {
    private:
        string destination;

    public:
        text_writer(): destination("output.txt"){};
        text_writer(const string& p_destination): destination(p_destination){};
        text_writer(const text_writer& p_text_writer): destination(p_text_writer.destination){};
        text_writer& operator=(const text_writer& p_text_writer);
        virtual ~text_writer() {};

        virtual void write(storage_type& storage);

};


#endif // TEXT_WRITER_H