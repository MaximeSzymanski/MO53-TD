#ifndef BIN_WRITER_H
#define BIN_WRITER_H

#include "storage_type.h"
#include "writer.h"
#include <string>

using namespace std; 

class bin_writer: public writer {
    private:
        string destination;

    public:
        bin_writer(): destination("output.txt"){};
        bin_writer(const string& p_destination): destination(p_destination){};
        bin_writer(const bin_writer& p_bin_writer): destination(p_bin_writer.destination){};
        bin_writer& operator=(const bin_writer& p_bin_writer);
        virtual ~bin_writer() {};

        virtual void write(storage_type& storage);

};


#endif // BIN_WRITER_H