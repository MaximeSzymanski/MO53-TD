#include "moving_average.h"
#include "storage_type.h"
#include "list_storage.h"

#include <memory>

void moving_average::calculate(storage_type &storage)
{
    storage_type &temp = storage;
    storage.clear();
    if (_window_width < temp.size())
    {
        double current_sum = 0.0;
        for (size_t i = 0; i < _window_width; ++i)
        {
            current_sum += temp.get_element(i);
        }
        storage.push_back(current_sum / _window_width);
        for (size_t i = 0; i + _window_width < temp.size(); ++i)
        {
            current_sum -= temp.get_element(i);
            current_sum += temp.get_element(i + _window_width);
            storage.push_back(current_sum / _window_width);
        }
    }
}