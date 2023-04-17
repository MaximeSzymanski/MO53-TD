#include "text_writer.h"
#include "storage_type.h"
#include <iostream>
#include <fstream>

using namespace std; 


text_writer& text_writer::operator=(const text_writer& p_text_writer) {
    this->destination = p_text_writer.destination;
    return *this;
}

void text_writer::write(storage_type& storage) {
    ofstream f{destination, std::ios::binary};
    if(!f.is_open()) {
        cout << "File cannot be opened for writing." << endl;
    }

    for (size_t i=0; i<storage.size(); ++i) {
        const double &value = storage.get_element(i);
        f.write(reinterpret_cast<const char *>(&value), sizeof(double));
    }
}