#include "resource_manager.h"


using namespace std;


void Resource_manager::make_reader(shared_enum::input input){
    switch (input)
    {
    case  shared_enum::input::BIN:
        /* code */
        break;
    case  shared_enum::input::TEXT:
        /* code */
        break;

    default:
        break;
    }

}

void Resource_manager::make_storage(shared_enum::storage storage){
    switch (storage)
    {
    case shared_enum::storage::LIST :
        /* code */
        break;
    case shared_enum::storage::VECTOR :
        /* code */
        break;
    default:
        break;
    }
}


void Resource_manager::make_writer(shared_enum::output output){
    switch (output)
    {
    case shared_enum::output::BIN :
        /* code */
        break;
    case shared_enum::output::SCREEN :
        /* code */
        break;
    case shared_enum::output::TEXT :
        /* code */
        break;

    default:
        break;
    }
}

void Resource_manager::make_calculation(shared_enum::calculation calculation){
 switch (calculation)
    {
    case shared_enum::calculation::AVG :
        /* code */
        break;
    case shared_enum::calculation::COUNT :
        /* code */
        break;
    case shared_enum::calculation::MOVING_AVG :
        /* code */
        break;
    case shared_enum::calculation::SORT :
        /* code */
        break;
    case shared_enum::calculation::SUM :
        /* code */
        break;

    default:
        break;
    }
}