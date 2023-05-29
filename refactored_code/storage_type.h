#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

/**
 * The `storage_type` class is an abstract base class that provides
 * a generic storage mechanism for storing data.
 */
class storage_type
{
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
    storage_type(){};

    /**
     * Copy constructor
     *
     * @param storage The object to be copied
     */
    storage_type(const storage_type &storage){};

    /**
     * Assignment operator
     *
     * @param storage The object to be assigned
     * @return A reference to this object
     */
    storage_type &operator=(const storage_type &storage) { return *this; };

    /**
     * Virtual destructor
     */
    virtual ~storage_type(){};

    /**
     * Pushes a new element onto the end of the storage.
     *
     * @param d The element to be pushed
     */
    virtual void push_back(const double d) = 0;

    /**
     * Gets the element at the specified position.
     *
     * @param position The position of the element to be retrieved
     * @return The element at the specified position
     * @throws out_of_range if the position is outside the bounds of the storage
     */
    virtual double get_element(const int position) = 0;

    /**
     * Removes the last element and returns its value
     *
     * @return The last element of the storage
     * @throws out_of_range if there are no elements stored
     */
    virtual double pop_element() = 0;

    /**
     * Clears the storage.
     */
    virtual void clear() = 0;

    /**
     * Gets the size of the storage.
     *
     * @return The size of the storage
     */
    virtual int size() = 0;

    /**
     * Sorts the storage in ascending order.
     */
    virtual void sort_storage(const bool ascending) = 0;
};

#endif // STORAGE_TYPE_H