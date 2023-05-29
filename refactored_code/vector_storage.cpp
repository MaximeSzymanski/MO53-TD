#include "vector_storage.h"
#include "storage_type.h"

#include <memory>
#include <algorithm>
#include <functional>
#include <stdexcept>

using namespace std;

vector_storage::vector_storage(const vector_storage &vector_storage)
{
    *this = vector_storage;
}

vector_storage &vector_storage::operator=(const vector_storage &vector_storage)
{
    _size = vector_storage._size;
    _capacity_data = vector_storage._capacity_data;
    _data = unique_ptr<double[]>(new double[_capacity_data]);
    for (int i = 0; i < _capacity_data; i++)
    {
        _data[i] = vector_storage._data[i];
    }
    return *this;
};

void vector_storage::push_back(const double d)
{
    /*
     * If the size of storage is greater than the capacity of the data array
     * then a duplicate of `_data` with double the capacity is created and
     * assigned to `_data`
     */
    if (_size >= _capacity_data)
    {
        _capacity_data *= 2;
        auto new_data = new double[_capacity_data];
        for (int i = 0; i < _capacity_data; ++i)
        {
            new_data[i] = _data[i];
        }
        _data = unique_ptr<double[]>(new_data);
    }

    // Add the new element to the vector.
    _data[_size++] = d;
}

double vector_storage::get_element(const int position)
{
    // Check if the index is valid.
    if (position < 0 || position >= _capacity_data)
    {
        throw out_of_range("Index is out of range");
    }

    // Return the element at the specified index.
    return _data[position];
}

void vector_storage::clear()
{
    _capacity_data = 10;
    _data = make_unique<double[]>(_capacity_data);
    _size = 0;
}

int vector_storage::size()
{
    return _size;
}

double vector_storage::pop_element()
{
    // Check if the vector is empty.
    if (_size == 0)
    {
        throw out_of_range("Storage is empty");
    }

    // Remove the last element from the vector.
    return _data[_size--];
}

void vector_storage::sort_storage(const bool ascending)
{
    if (ascending)
    {
        sort(_data.get(), _data.get() + _capacity_data);
    }
    else
    {
        sort(_data.get(), _data.get() + _capacity_data, greater<double>());
    }
}
