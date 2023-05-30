#include "moving_average.h"
#include "storage_type.h"
#include <memory>
#include "list_storage.h"

void moving_average::calculate(storage_type &storage)
{
    // Create a temporary storage that contains the data of `storage`
    list_storage temp{};
    for (int i = 0; i < storage.size(); ++i)
    {
        temp.push_back(storage.get_element(i));
    }

    // Clear the storage_type object.
    storage.clear();

    // If the window_width property is less than the size of the data set, calculate the moving average.
    if (_window_width < temp.size())
    {
        double current_sum = 0.0;
        for (int i = 0; i < _window_width; ++i)
        {
            current_sum += temp.get_element(i);
        }
        storage.push_back(current_sum / _window_width);
        for (int i = 0; i + _window_width < temp.size(); ++i)
        {
            current_sum -= temp.get_element(i);
            current_sum += temp.get_element(i + _window_width);
            storage.push_back(current_sum / _window_width);
        }
    }
}