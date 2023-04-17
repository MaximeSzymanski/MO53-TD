#ifndef WRITER_H
#define WRITER_H

#include "storage_type.h"
#include <string>

#include <string>

using namespace std; 


struct write_exception: public runtime_error
{
    write_exception(const string &message): runtime_error(message) {}
};

class writer {
    public:
        writer() {};
        virtual ~writer() {};

        virtual void write(storage_type& storage) = 0;

};


#endif // WRITER_H