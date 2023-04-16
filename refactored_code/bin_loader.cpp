#include "bin_loader.h"
#include "storage_type.h"
#include <string>
#include <fstream>
#include <array>
#include <iostream>

using namespace std; 

storage_type& bin_loader::write(storage_type& storage, const std::string source) {
    storage_type& returned_storage{storage};
    ifstream f{source, std::ios::binary};
    
    if (!f.is_open()) {
        throw ios_base::failure("File cannot be opened for reading.");

    }

    double buffer;
    while (f.read(reinterpret_cast<char *>(&buffer), sizeof(double))) {
        returned_storage.add_element(buffer);
    }

    return returned_storage;
}
