#ifndef VECTOR_STORAGE_H
#define VECTOR_STORAGE_H

#include "storage_type.h"

#include <list>
#include <memory>
#include <iostream>

using namespace std;

/**
 * This class provides a way to store doubles by inheriting from storage_type.
 * The class stores the doubles in an array.
 */
class vector_storage : public storage_type
{
private:
    /**
     * A pointer to the data.
     */
    unique_ptr<double[]> _data;

    /**
     * The size of the vector.
     */
    int _size;

    /**
     * The capacity of the vector.
     */
    int _capacity_data;

public:
    /**
     * This constructor constructs a new vector_storage object with a default size of 10.
     */
    vector_storage()
    {
        _size = 0;
        _capacity_data = 10;
        _data = make_unique<double[]>(10);
    };

    /**
     * This constructor constructs a new vector_storage object that is a copy of the existing vector_storage object.
     *
     * @param vector_storage The vector_storage object to copy.
     */
    vector_storage(const vector_storage &vector_storage);

    /**
     * This function assigns the value of an existing vector_storage object to this object.
     *
     * @param vector_storage The vector_storage object to assign.
     * @return A reference to this object.
     */
    vector_storage &operator=(const vector_storage &vector_storage);

    /**
     * Destroys this vector_storage object.
     */
    virtual ~vector_storage() {}

    /**
     * This function adds a new element to the vector.
     *
     * @param d The new element to add.
     */
    virtual void push_back(const double d);

    /**
     * This function gets the element at the specified position in the vector.
     *
     * @param position The position of the element to get.
     * @return The element at the specified position.
     * @throws out_of_range if the position is outside the bounds of the storage
     */
    virtual double get_element(const int position);

    /**
     * This function clears the vector, removing all of the elements.
     */
    virtual void clear();

    /**
     * his function gets the size of the vector.
     *
     * @return The size of the vector.
     */
    virtual int size();

    /**
     * This function sorts the vector in ascending order.
     *
     * @param ascending Whether to sort in ascending or descending order.
     */
    virtual void sort_table(const bool ascending);

    /**
     * Removes the last element and returns its value
     *
     * @return The last element of the storage
     * @throws out_of_range if there are no elements stored
     */
    virtual double pop_element();
};

#endif // VECTOR_H