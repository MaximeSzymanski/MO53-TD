#include "text_loader.h"
#include "storage_type.h"
#include <string>
#include <fstream>
#include <array>
#include <iostream>

using namespace std; 

storage_type& text_loader::load(storage_type& storage) {
    // Create a copy of storage
    storage_type& returned_storage{storage};
    // Open the source bin file
    ifstream f{source};
    
    if (!f.is_open()) {
        throw ios_base::failure("File cannot be opened for reading.");

    }
    // store in returned_storage the data of f
    array<char, 100> buffer;
    while (f.getline(&buffer[0], 100)) {
        returned_storage.push_back(stold(string{buffer.data()}));
    }

    return returned_storage;
}
