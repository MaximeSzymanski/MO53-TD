#ifndef WRITER_H
#define WRITER_H

#include "storage_type.h"
#include <string>
#include <stdexcept>
#include <string>

using namespace std; 


class write_exception: public runtime_error {
    public:
        write_exception(const string &message): runtime_error(message) {}
};

class writer {
    public:
        writer() {};
        virtual ~writer() {};

        virtual void write(storage_type& storage) = 0;

};


#endif // WRITER_H