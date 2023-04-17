#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

class storage_type {
    public:
        // Coplien form functions
        storage_type() {}
        storage_type(const storage_type& storage) {}
        storage_type& operator=(const storage_type& storage) {return *this;}
        virtual ~storage_type() {}

        virtual void add_element(double d) = 0;
        virtual double get_element(int position) = 0;
        virtual void clear_elements() = 0;
        virtual int size() = 0;
    };


#endif // STORAGE_TYPE_H