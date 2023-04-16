#ifndef STORAGE_TYPE_H
#define DATA_LIST_H

class storage_type {
    public:
    
    storage_type() {}
    virtual ~storage_type() {}

    virtual void add_element(double d) = 0;
    virtual void clear_elements() = 0;
};


#endif // STORAGE_TYPE_H