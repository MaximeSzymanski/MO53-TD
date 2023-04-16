#ifndef TEXT_LOADER_H
#define DATA_LIST_H

#include "storage_type.h"
#include <string>
using namespace std; 

class text_loader {
    public:
    
    text_loader() {}
    virtual ~text_loader() {}

    virtual storage_type& write(storage_type& storage, std::string source);
};


#endif // TEXT_LOADER_H