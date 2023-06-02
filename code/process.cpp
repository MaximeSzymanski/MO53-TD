#include "process.h"
#include <iostream>
#include "storage_type.h"
#include "loader.h"
#include "writer.h"
#include "calculation.h"

using namespace std;

void process::execute()
{
    try
    {
        // load data
        storage_type &loaded_storage = _loader->load(*_storage);
        // Calculate data
        _calculation->calculate(loaded_storage);
        // write the calculated data
        _writer->write(loaded_storage);
    }
    catch (exception &e)
    {
        cerr << "\nAn exception was caught:\n"
             << e.what() << endl;
    }
}