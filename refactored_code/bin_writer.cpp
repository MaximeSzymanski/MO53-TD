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
    ofstream f{destination};
    if(!f.is_open()) {
        cout << "File cannot be opened for writing." << endl;
    }

    for (size_t i=0; i<storage.size(); ++i) {
        f << storage.get_element(i) << endl;
    }
}