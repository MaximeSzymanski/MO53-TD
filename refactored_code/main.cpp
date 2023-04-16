#include <iostream>
#include "vector.h"
#include "text_loader.h"
#include "bin_loader.h"
#include "loader.h"
#include <memory>

using namespace std;

/**
 * This main is only used to test code.
 * This code is not final
*/
int main() {
    shared_ptr<loader> l = make_shared<bin_loader>(bin_loader());
    shared_ptr<storage_type> s = make_shared<vector>(vector());
    l->write(*s, "binary.bin");

    return 0;
}
