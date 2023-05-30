#include "list_storage.h"

#include <stdexcept>

list_storage::list_storage(const list_storage &other)
{
    shared_ptr<list_element> ptr(other._head);
    while (ptr)
    {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
}

list_storage &list_storage::operator=(const list_storage &other)
{
    clear();
    shared_ptr<list_element> ptr = other._head;
    while (ptr)
    {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
    return *this;
}

void list_storage::clear()
{
    shared_ptr<list_element> tmp = _head;
    while (tmp)
    {
        _head = tmp->get_next();
        tmp = _head;
    }
    _head = _tail = make_shared<list_element>();
}

void list_storage::push_back(double v)
{
    if (!_head)
    {
        _head = make_shared<list_element>(list_element(v));
        _tail = _head;
    }
    else
    {
        _tail->set_next(make_shared<list_element>(list_element(v, _tail)));
        _tail = _tail->get_next();
    }
}

double list_storage::pop_element()
{
    if (!_head)
    {
        throw out_of_range("Storage is empty");
    }

    double return_value = _head->get_value();
    shared_ptr<list_element> tmp = _head->get_next();
    _head = tmp;
    if (tmp)
    {
        tmp->set_prev({});
    }
    else
    {
        _tail = _head; // both =nullptr
    }

    return return_value;
}

int list_storage::size() const
{
    size_t s = 0;
    shared_ptr<list_element> ptr = _head;
    while (ptr)
    {
        ptr = ptr->get_next();
        ++s;
    }
    return s;
}

double list_storage::get_element(int position) const
{
    size_t pos = 0;
    shared_ptr<list_element> ptr = _head;
    while (ptr)
    {
        if (pos == position)
            return ptr->get_value();
        ptr = ptr->get_next();
        ++pos;
    }

    // Error case: position out of bounds
    throw out_of_range("Index is out of range");
}

void list_storage::sort_storage(bool ascending)
{
    // Naive sort
    shared_ptr<list_element> ptr = _head;
    while (ptr && ptr->get_next())
    {
        shared_ptr<list_element> min_element = ptr;
        shared_ptr<list_element> cursor = ptr;
        while (cursor)
        {
            if (ascending && cursor->get_value() < min_element->get_value())
                min_element = cursor;
            else if (!ascending && cursor->get_value() > min_element->get_value())
                min_element = cursor;
            cursor = cursor->get_next();
        }
        double tmp = ptr->get_value();
        ptr->set_value(min_element->get_value());
        min_element->set_value(tmp);
        ptr = ptr->get_next();
    }
}