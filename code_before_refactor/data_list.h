#ifndef DATA_LIST_H
#define DATA_LIST_H


#include <vector>
#include <string>
#include <memory>
#include <iostream>
using namespace std;

/**
 * Class that represents an element of values_list that stores a double
 * @see values_list 
 */
class list_element {
    /**
     * value of the double that is stored within the element
    */
    double _value;
    /**
     * previous element of the list
    */
    weak_ptr<list_element> _prev;
    /**
     * next element of the list
    */
    shared_ptr<list_element> _next;

public:
    /**
     * Constructor of the class
     * @param v double asigned to the element
     * @param p previous element of the list
     * @param n next element of the list
    */
    list_element(double v=0.0, weak_ptr<list_element> p={}, shared_ptr<list_element> n={}):
        _value(v), _prev(p), _next(n) {}
    /**
     * Destructor of the list element
    */
    ~list_element() {}

    /**
     * @return the next element of the list
    */
    shared_ptr<list_element> get_next() {return _next;}
    /**
     * @param n the next element of the list
    */
    void set_next(shared_ptr<list_element> n) {_next = n;}
    /**
     * @return the previous element of the list
    */
    weak_ptr<list_element> get_prev() {return _prev;}
    /**
     * @param n the previous element of the list
    */
    void set_prev(weak_ptr<list_element> n) {_prev = n;}
    /**
     * @return the double value of the element
    */
    double get_value()const {return _value;}
    /**
     * @param the double value of the element
    */
    void set_value(double v) {_value = v;}
};

class values_list {
    shared_ptr<list_element> _head;
    shared_ptr<list_element> _tail;

public:
    values_list(): _head(make_shared<list_element>()), _tail(make_shared<list_element>()) {}
    values_list(const values_list &other);
    ~values_list() {clear_list();}
    values_list &operator=(const values_list &other);

    void clear_list();
    void add_value(double v); // Always add at the end
    void pop_element(); // Remove last element
    size_t size()const;
    double get_value(size_t position)const;

    void sort_list(bool ascending);
};

class data_list {
    values_list _values;
public:
    data_list();
    data_list(const data_list &other);
    ~data_list() {_values.clear_list();}

    // Input methods
    void from_text(const std::string &source);
    void from_binary(const std::string &source);

    // Output methods
    void to_text(const std::string &destination);
    void to_binary(const std::string &destination);
    void print_data()const;

    // Computation (return new instances of data_table)
    data_list moving_average(size_t window_width);
    data_list sort_table(bool ascending=true);
    data_list average(); // returns a data_table with only one value
    data_list table_sum(); // returns a data_table with only one value
    data_list table_count(); // returns a data_table with only one value
};

#endif // DATA_LIST_H
