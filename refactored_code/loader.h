#ifndef LOADER_H
#define DATA_LIST_H

#include "storage_type.h"
#include <string>
using namespace std; 

class loader {
    public:
    
    loader() {}
    virtual ~loader() {}

    virtual storage_type& write(storage_type& storage, std::string source) = 0;

};


#endif // LOADER_H