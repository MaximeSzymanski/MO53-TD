#ifndef VECTOR_H
#define VECTOR_H

#include "storage_type.h"
#include <list>

using namespace std; 

class vector: public storage_type {
    private:
        list<double> l;

    public:
        vector(): l(){};
        vector(const vector& vector): l(vector.l){};
        vector& operator=(const vector& vector) { this->l = vector.l; return *this;};
        virtual ~vector() {};

        virtual void add_element(double d) {
            l.push_back(d);
        };
        virtual double get_element(int position) {
            list<double>::iterator it = l.begin();
            advance(it, position);
            return *it;
        }
        virtual void clear_elements() {l.clear();};
        virtual int size() { return l.size(); };

};


#endif // VECTOR_H