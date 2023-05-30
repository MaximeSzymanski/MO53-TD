#include "process.h"
#include <iostream>
#include "vector_storage.h"
#include "text_loader.h"
#include "bin_loader.h"
#include "loader.h"
#include <memory>
#include "writer.h"
#include "screen_writer.h"
#include "text_writer.h"
#include "bin_writer.h"
#include "list_storage.h"
#include <string>
#include "calculation.h"
#include "moving_average.h"
#include "storage_sum.h"

using namespace std;

void process::choose_how_to_process()
{
    // The following code corresponds to step 1 of choose_how_to_to_process i.e
    // 1) Ask the user which loader, storage type, calculation and writer they would like to use
    cout << "Which loader type would you like to use?\n(1) bin loader\n(2) text loader\n";
    int loader_choice = 0;
    while (loader_choice < 1 || loader_choice > 3)
    {
        cin >> loader_choice;
    }

    cout << "Which file would you like you load the data from?\n";
    string source_file;
    cin >> source_file;

    cout << "Which storage type would you like to use?\n(1) vector\n(2) linked list\n";
    int storage_type_choice = 0;
    while (storage_type_choice < 1 || storage_type_choice > 2)
    {
        cin >> storage_type_choice;
    }

    // TODO: add calculation choice
    cout << "What calculation function would you like to use?\n(1) Move average\n(2) Storage sum\n";
    int calculation_type_choice = 0;
    while (calculation_type_choice < 1 || calculation_type_choice > 2)
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

    // The following code corresponds to step 2 of choose_how_to_to_process i.e
    // 2) initialize the loader, storage type, calculation and writer according to the input from the user
    switch (loader_choice)
    {
    case 1:
        _loader = make_shared<bin_loader>(bin_loader(source_file));
        break;
    case 2:
        _loader = make_shared<text_loader>(text_loader(source_file));
        break;
    }

    switch (storage_type_choice)
    {
    case 1:
        _storage = make_shared<vector_storage>(vector_storage());
        break;
    case 2:
        _storage = make_shared<list_storage>(list_storage());
        break;
    }

    // TODO: add calculation
    switch (calculation_type_choice)
    {
    case 1:
        _calculation = make_shared<moving_average>(moving_average(moving_average_window_width));
        break;
    case 2:
        _calculation = make_shared<storage_sum>(storage_sum());
        break;
    }

    switch (writer_choice)
    {
    case 1:
        _writer = make_shared<bin_writer>(bin_writer(destination_file));
        break;
    case 2:
        _writer = make_shared<text_writer>(text_writer(destination_file));
        break;
    case 3:
        _writer = make_shared<screen_writer>(screen_writer());
        break;
    }
}

void process::execute()
{
    /*
    The function does the next steps:
    1) Ask the user which loader, storage type, calculation and writer they would like to use<br>
    2) initialize the loader, storage type, calculation and writer according to the input from the user<br>
    */
    choose_how_to_process();
    try
    {
        // load data
        storage_type &loaded_storage = _loader->load(*_storage);
        // Calculate data using the loaded data
        _calculation->calculate(loaded_storage);
        // write the calculated data
        _writer->write(loaded_storage);
    }
    catch (exception &e)
    {
        cerr << "\nAn exception was caught:\n"
             << e.what() << endl;
    }
}