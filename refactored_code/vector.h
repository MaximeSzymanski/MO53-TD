#ifndef STORAGE_TYPE_H
#define DATA_LIST_H

#include "storage_type.h"

class vector: public storage_type {
    public:
    
    vector() {}
    virtual ~vector() {}

    virtual void add_element(double d) {};
    virtual void clear_elements() {};

};


#endif // STORAGE_TYPE_H