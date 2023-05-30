#include "storage_sum.h"
#include "storage_type.h"

void storage_sum::calculate(storage_type &storage)
{
    double current_sum = 0.0;
    for (int i = 0; i < storage.size(); ++i)
    {
        current_sum += storage.get_element(i);
    }
    storage.clear();
    storage.push_back(current_sum);
}