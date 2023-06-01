#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "shared_enum.h"
#include "loader.h"
#include "storage_type.h"
#include "writer.h"
#include "calculation.h"
#include <memory>

class Resource_manager {
public:
    static std::shared_ptr<loader> make_loader(shared_enum::input);
    static std::shared_ptr<storage_type> make_storage(shared_enum::storage);
    static std::shared_ptr<writer> make_writer(shared_enum::output);
    static std::shared_ptr<calculation> make_calculation(shared_enum::calculation, int);
};

#endif
