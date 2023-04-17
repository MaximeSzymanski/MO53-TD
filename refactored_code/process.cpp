#include "process.h"
#include <iostream>
#include "vector.h"
#include "text_loader.h"
#include "bin_loader.h"
#include "loader.h"
#include <memory>
#include "writer.h"
#include "screen_writer.h"
#include "text_writer.h"
#include "bin_writer.h"
#include <string>

using namespace std;

void process::choose_how_to_process() {
    cout << "Which loader type would you like to use?\n(1) bin loader\n(2) text loader\n";
    int loader_choice = 0;
    while(loader_choice < 1 || loader_choice > 3) {
        cin >> loader_choice;
    }

    cout << "Which file would you like you load the data from?\n";
    string source_file;
    cin >> source_file;

    // TODO: add the option to choose linked list
    cout << "Which storage type would you like to use?\n(1) vector\n";
    int storage_type_choice = 0;
    while(storage_type_choice != 1) {
        cin >> storage_type_choice;
    }

    // TODO: add calculation choice

    cout << "Which writer type would you like to use?\n(1) binary writer\n(2) text writer\n(3) screen writer\n";
    int writer_choice = 0;
    while(writer_choice < 1 || writer_choice > 3) {
        cin >> writer_choice;
    }

    string destination_file;
    if(writer_choice == 1 || writer_choice == 2) {
        cout << "What file would you like to print the results in?\n";
        cin >> destination_file;
    }

    switch(loader_choice) {
        case 1: 
            _loader = make_shared<bin_loader>(bin_loader(source_file));
            break;
        case 2:
            _loader = make_shared<text_loader>(text_loader(source_file));
            break;
    }

    switch(storage_type_choice) {
        case 1: 
            _storage = make_shared<vector>(vector());
            break;
    }

    switch(writer_choice) {
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

void process::execute() {
    choose_how_to_process();

    try {
        storage_type& loaded_storage = _loader->load(*_storage);
        // TODO: calculate the loaded data
        _writer->write(loaded_storage);
    } catch(exception& e) {
        cerr << "\nAn exception was caught:\n" << e.what() << endl;
    }
}