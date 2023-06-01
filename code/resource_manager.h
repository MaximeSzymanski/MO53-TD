#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "shared_enum.h"

class Resource_manager{

static loader* make_loader(shared_enum::input);
static storage_type* make_storage(shared_enum::storage);
static writer* make_writer(shared_enum::output);

static calculation* make_calculation(shared_enum::calculation, int);

};


#endif