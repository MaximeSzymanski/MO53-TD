#include "resource_manager.h"

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


loader* Resource_manager::make_loader(shared_enum::input input){
    switch (input)
    {
    case  shared_enum::input::BIN:
        break;
    case  shared_enum::input::TEXT:
        break;
    default:
        return nullptr;
        break;
    }
}

storage_type* Resource_manager::make_storage(shared_enum::storage storage){
    switch (storage)
    {
    case shared_enum::storage::LIST :
        return new list_storage();
        break;
    case shared_enum::storage::VECTOR :
        return new vector_storage();
        break;
    default:
        return nullptr;
        break;
    }
}


writer* Resource_manager::make_writer(shared_enum::output output){
    switch (output)
    {
    case shared_enum::output::BIN :
        return new bin_writer();
        break;
    case shared_enum::output::SCREEN :
        return new screen_writer();
        break;
    case shared_enum::output::TEXT :
        return new text_writer();
        break;

    default:
        return nullptr;
        break;
    }
}

calculation* Resource_manager::make_calculation(shared_enum::calculation calculation, int window_width = 0){
 switch (calculation)
    {
    case shared_enum::calculation::AVG :
        return new storage_average();
        break;
    case shared_enum::calculation::COUNT :
        return new storage_count();
        break;
    case shared_enum::calculation::MOVING_AVG :
        if(window_width > 0)
            return new moving_average(window_width);
        break;
    case shared_enum::calculation::SORT :
        /* code */
        break;
    case shared_enum::calculation::SUM :
        return new storage_sum();
        break;

    default:
        return nullptr;
        break;
    }
}