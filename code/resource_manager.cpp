#include "resource_manager.h"

#include <memory>

#include "loader.h"
#include "text_loader.h"
#include "bin_loader.h"

#include "writer.h"
#include "bin_writer.h"
#include "text_writer.h"
#include "screen_writer.h"

#include "storage_type.h"
#include "list_storage.h"
#include "vector_storage.h"

#include "calculation.h"
#include "storage_average.h"
#include "storage_count.h"
#include "storage_sum.h"
#include "storage_type.h"
#include "moving_average.h"

using namespace std;

std::shared_ptr<loader> resource_manager::make_loader(shared_enum::input input, string load_file)
{
    switch (input)
    {
    case shared_enum::input::INPUT_BIN:
        return make_shared<bin_loader>(load_file);
    case shared_enum::input::INPUT_TEXT:
        return make_shared<text_loader>(load_file);
    default:
        return nullptr;
    }
}

shared_ptr<storage_type> resource_manager::make_storage(shared_enum::storage storage)
{
    switch (storage)
    {
    case shared_enum::storage::LIST:
        return make_shared<list_storage>();
    case shared_enum::storage::VECTOR:
        return make_shared<vector_storage>();
    default:
        return nullptr;
    }
}

shared_ptr<writer> resource_manager::make_writer(shared_enum::output output)
{
    switch (output)
    {
    case shared_enum::output::OUTPUT_BIN:
        return make_shared<bin_writer>();
    case shared_enum::output::OUTPUT_SCREEN:
        return make_shared<screen_writer>();
    case shared_enum::output::OUTPUT_TEXT:
        return make_shared<text_writer>();
    default:
        return nullptr;
    }
}

shared_ptr<calculation> resource_manager::make_calculation(shared_enum::calculation calculation, int window_width)
{
    switch (calculation)
    {
    case shared_enum::calculation::AVG:
        return make_shared<storage_average>();
    case shared_enum::calculation::COUNT:
        return make_shared<storage_count>();
    case shared_enum::calculation::MOVING_AVG:
        if (window_width > 0)
            return make_shared<moving_average>(window_width);
    case shared_enum::calculation::SUM:
        return make_shared<storage_sum>();
    default:
        return nullptr;
    }
}
