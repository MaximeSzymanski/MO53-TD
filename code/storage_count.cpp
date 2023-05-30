#include "storage_count.h"
#include "storage_type.h"

void storage_count::calculate(storage_type &storage)
{
    int size_storage = storage.size();
    storage.clear();
    storage.push_back(static_cast<double>(size_storage));
}