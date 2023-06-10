#ifndef LIST_STORAGE_H
#define LIST_STORAGE_H

#include "storage_type.h"

#include <vector>
#include <string>
#include <memory>

using namespace std;

/**
 * Class that represents an element of list_storage that stores a double
 * @see list_storage
 */
class list_element
{
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
    list_element(double v = 0.0, weak_ptr<list_element> p = {}, shared_ptr<list_element> n = {}) : _value(v), _prev(p), _next(n) {}
    /**
     * Destructor of the list element
     */
    ~list_element() {}

    /**
     * Get the next element of the list
     * @return the next element of the list
     */
    shared_ptr<list_element> get_next() { return _next; }

    /**
     * Set the next element of the list
     * @param n the next element of the list
     */
    void set_next(shared_ptr<list_element> n) { _next = n; }

    /**
     * Get the previous element of the list
     * @return the previous element of the list
     */
    weak_ptr<list_element> get_prev() { return _prev; }

    /**
     * Set the previous element of the list
     * @param n the previous element of the list
     */
    void set_prev(weak_ptr<list_element> n) { _prev = n; }

    /**
     * Get value of the list element
     * @return the double value of the element
     */
    double get_value() const { return _value; }

    /**
     * Set the value of the list element
     * @param the double value of the element
     */
    void set_value(double v) { _value = v; }
};

/**
 * @class ListIterator
 * @brief Iterator for traversing elements of a linked list.
 *
 * The `ListIterator` class allows iteration over the elements of a linked list.
 * It is used in conjunction with the `list_storage` class to iterate through the stored elements in the list.
 */
class ListIterator
{
public:

    /**
     * Constructor of the `ListIterator` class.
     *
     * @param ptr A `shared_ptr` pointing to a list element.
     */
    ListIterator(shared_ptr<list_element> ptr) : _ptr(ptr) {}

     /**
     * Dereference operator.
     *
     * Retrieves the value of the current element pointed by the iterator.
     *
     * @return A constant reference to the value of the current element.
     */
    const double &operator*() const { return _ptr->get_value(); }

    /**
     * Pre-increment operator.
     *
     * Moves the iterator to the next element in the list.
     *
     * @return A reference to the iterator after the increment.
     */
    ListIterator &operator++()
    {
        _ptr = _ptr->get_next();
        return *this;
    }

    /**
     * Post-increment operator.
     *
     * Moves the iterator to the next element in the list.
     *
     * @return A copy of the iterator before the increment.
     */
    ListIterator operator++(int)
    {
        ListIterator tmp(*this);
        operator++();
        return tmp;
    }

    /**
     * Equality operator.
     *
     * @param other The iterator to be compared with.
     * @return `true` if the iterators point to the same element, `false` otherwise.
     */
    bool operator==(const ListIterator &other) const { return _ptr == other._ptr; }

    /**
     * Inequality operator.
     *
     * @param other The iterator to be compared with.
     * @return `true` if the iterators point to different elements, `false` otherwise.
     */
    bool operator!=(const ListIterator &other) const { return _ptr != other._ptr; }

private:
    /**
     * A `shared_ptr` pointing to a list element.
     */
    shared_ptr<list_element> _ptr;
};



/**
 * This class provides a way to store doubles by inheriting from storage_type.
 * The class stores the doubles in list_element objects
 * @see list_element
 */
class list_storage : public storage_type
{
private:
    shared_ptr<list_element> _head;
    shared_ptr<list_element> _tail;

public:
    /*
     * Coplien form functions (Default constructor, copy constructor, assignment operator, and destructor):
     * These functions are used to implement the Copy and Swap idiom.
     *  The Copy and Swap idiom is a technique for preventing
     * the copy constructor and assignment operator from making
     * unnecessary copies of objects.
     */

    /**
     * Default constructor
     */
    list_storage(){};

    /**
     * Copy constructor
     *
     * @param storage The object to be copied
     */
    list_storage(const list_storage &storage);

    /**
     * Assignment operator
     *
     * @param storage The object to be assigned
     * @return A reference to this object
     */
    list_storage &operator=(const list_storage &storage);

    /**
     * Virtual destructor
     */
    virtual ~list_storage(){};

    /**
     * Pushes a new element onto the end of the storage.
     *
     * @param d The element to be pushed
     */
    virtual void push_back(const double d);

    /**
     * Gets the element at the specified position.
     *
     * @param position The position of the element to be retrieved
     * @return The element at the specified position
     * @throws out_of_range if the position is outside the bounds of the storage
     */
    virtual double get_element(const int position) const;

    /**
     * Removes the last element and returns its value
     *
     * @return The last element of the storage
     * @throws out_of_range if there are no elements stored
     */
    virtual double pop_element();

    /**
     * Clears the storage.
     */
    virtual void clear();

    /**
     * Gets the size of the storage.
     *
     * @return The size of the storage
     */
    virtual int size() const;

    /**
     * Sorts the storage in ascending order.
     */
    virtual void sort_storage(const bool ascending);

    ListIterator begin();

    ListIterator end();

    double operator[](int position);

};

#endif // LIST_STORAGE_H