#include <iostream>
#include "vector.h"
#include "text_loader.h"
#include "bin_loader.h"
#include "loader.h"
#include <memory>
#include "writer.h"
#include "screen_writer.h"
#include "text_writer.h"

using namespace std;

/**
 * This main is only used to test code.
 * This code is not final
*/
int main() {
    shared_ptr<loader> l(new bin_loader());
    shared_ptr<storage_type> s(new vector());
    shared_ptr<writer> w = make_shared<text_writer>(text_writer("destination.txt"));
    storage_type& ref = l->load(*s, "binary.bin");
    w->write(ref);

    return 0;
}
