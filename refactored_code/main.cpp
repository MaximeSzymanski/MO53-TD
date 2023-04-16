#include <iostream>
#include "vector.h"
#include "text_loader.h"
#include "loader.h"
#include <memory>

using namespace std;

/**
 * This main is only used to test code.
 * This code is not final
*/
int main() {
    shared_ptr<loader> l = make_shared<text_loader>(text_loader());
    shared_ptr<storage_type> s = make_shared<vector>(vector());
    l->write(*s, "texte.txt");

    return 0;
}
