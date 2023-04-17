#ifndef WRITER_H
#define WRITER_H

#include "storage_type.h"
#include <string>
using namespace std; 

class writer {
    public:
        writer() {};
        virtual ~writer() {};

        virtual void write(storage_type& storage) = 0;

};


#endif // WRITER_H