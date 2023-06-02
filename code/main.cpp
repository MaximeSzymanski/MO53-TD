#include "process.h"
#include "resource_manager.h"
#include "shared_enum.h"
#include <iostream>

using namespace std;

/**
 * Entry point of the program:
 * 1) It asks how information to the user on how the data should be processed
 * 2) It process the data
 */
int main()
{
    // The following code asks the user which loader, storage type, calculation and writer they would like to use
    cout << "Which loader type would you like to use?\n(1) bin loader\n(2) text loader\n";
    int loader_choice = 0;
    while (loader_choice < 1 || loader_choice > 3)
    {
        cin >> loader_choice;
    }

    cout << "Which file would you like to load the data from?\n";
    string source_file;
    cin >> source_file;

    cout << "Which storage type would you like to use?\n(1) vector\n(2) linked list\n";
    int storage_type_choice = 0;
    while (storage_type_choice < 1 || storage_type_choice > 2)
    {
        cin >> storage_type_choice;
    }

    cout << "What calculation function would you like to use?\n(1) Move average\n(2) Storage sum\n(3) Storage average\n(4) Storage count\n";
    int calculation_type_choice = 0;
    while (calculation_type_choice < 1 || calculation_type_choice > 4)
    {
        cin >> calculation_type_choice;
    }

    int moving_average_window_width = 0;
    if (calculation_type_choice == 1)
    {
        cout << "What window width would you like for the moving average window?\n";
        while (moving_average_window_width <= 0)
        {
            cin >> moving_average_window_width;
        }
    }

    cout << "Which writer type would you like to use?\n(1) binary writer\n(2) text writer\n(3) screen writer\n";
    int writer_choice = 0;
    while (writer_choice < 1 || writer_choice > 3)
    {
        cin >> writer_choice;
    }

    string destination_file;
    if (writer_choice == 1 || writer_choice == 2)
    {
        cout << "What file would you like to print the results in?\n";
        cin >> destination_file;
    }

    // The following chooses which loader type, storage type, calculation type and writer type to use based on the answers of the user
    shared_enum::input input_type;
    switch (loader_choice)
    {
    case 1:
        input_type = shared_enum::input::INPUT_BIN;
        break;
    case 2:
        input_type = shared_enum::input::INPUT_TEXT;
        break;
    }

    shared_enum::storage storage_type;
    switch (storage_type_choice)
    {
    case 1:
        storage_type = shared_enum::storage::VECTOR;
        break;
    case 2:
        storage_type = shared_enum::storage::LIST;
        break;
    }

    shared_enum::calculation calculation_type;
    switch (calculation_type_choice)
    {
    case 1:
        calculation_type = shared_enum::calculation::MOVING_AVG;
        break;
    case 2:
        calculation_type = shared_enum::calculation::SUM;
        break;
    case 3:
        calculation_type = shared_enum::calculation::AVG;
        break;
    case 4:
        calculation_type = shared_enum::calculation::COUNT;
        break;
    }

    shared_enum::output output_type;
    switch (writer_choice)
    {
    case 1:
        output_type = shared_enum::output::OUTPUT_BIN;
        break;
    case 2:
        output_type = shared_enum::output::OUTPUT_TEXT;
        break;
    case 3:
        output_type = shared_enum::output::OUTPUT_SCREEN;
        break;
    }

    // Create a resource manager
    resource_manager mgr{};
    // Create a process by using the resource manager and the loader, storage type, calculation and writer chosen by the user
    process p{
        mgr.make_loader(input_type, source_file),
        mgr.make_storage(storage_type),
        mgr.make_calculation(calculation_type, moving_average_window_width),
        mgr.make_writer(output_type, destination_file)};

    // execute the process
    p.execute();

    return 0;
}
