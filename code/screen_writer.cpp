#include "screen_writer.h"
#include "storage_type.h"
#include <iostream>

using namespace std;

void screen_writer::write(storage_type &storage)
{
    // Print in the console the data of storage
    cout << "Results: " << endl;
    for (size_t i = 0; i < storage.size(); ++i)
    {
        cout << storage.get_element(i) << endl;
    }
}