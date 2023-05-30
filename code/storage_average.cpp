#include "storage_average.h"
#include "storage_type.h"

void storage_average::calculate(storage_type &storage)
{
    // Check that the storage is not empty
    if (storage.size() == 0)
    {
        return;
    }

    // Calculate the avg of the data stored in the storage
    double average = 0.0;
    for (int i = 0; i < storage.size(); ++i)
    {
        average += storage.get_element(i);
    }
    average /= storage.size();
    storage.clear();
    storage.push_back(average);
}