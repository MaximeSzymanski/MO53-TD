#include "bin_writer.h"
#include "storage_type.h"
#include <iostream>
#include <fstream>

using namespace std; 


bin_writer& bin_writer::operator=(const bin_writer& p_text_writer) {
    this->destination = p_text_writer.destination;
    return *this;
}

void bin_writer::write(storage_type& storage) {
    // open the destination file
    ofstream f{destination, std::ios::binary};
    if(!f.is_open()) {
        throw write_exception("File cannot be opened for writing.");
    }
    // Write into f in a binary format the data stored in storage 
    for (size_t i=0; i<storage.size(); ++i) {
        const double &value = storage.get_element(i);
        f.write(reinterpret_cast<const char *>(&value), sizeof(double));
    }
}