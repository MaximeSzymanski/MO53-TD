#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

class storage_type {
    public:
        // Coplien form functions
        storage_type() {}
        storage_type(const storage_type& storage) {}
        storage_type& operator=(const storage_type storage) {return *this;}
        virtual ~storage_type() {}

        virtual void add_element(double d) {};
        virtual void clear_elements() {};
    };


#endif // STORAGE_TYPE_H