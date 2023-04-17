#ifndef SCREEN_WRITER_H
#define SCREEN_WRITER_H

#include "storage_type.h"
#include "writer.h"
#include <string>

using namespace std; 

class screen_writer: public writer {
    public:
        screen_writer() {};
        virtual ~screen_writer() {};

        virtual void write(storage_type& storage);

};


#endif // SCREEN_WRITER_H