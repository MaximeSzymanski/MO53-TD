#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "shared_enum.h"

class Resource_manager{

void make_reader(shared_enum::input);
void make_storage(shared_enum::storage);
void make_writer(shared_enum::output);

void make_calculation(shared_enum::calculation);

};


#endif