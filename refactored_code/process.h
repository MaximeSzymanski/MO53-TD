#ifndef PROCESS_H
#define PROCESS_H

#include "storage_type.h"
#include <string>
#include "bin_loader.h"
#include <memory>
#include "loader.h"
#include "writer.h"
#include "vector_storage.h"
#include "screen_writer.h"

using namespace std;

/**
 * Class used to process data
 */
class process
{
private:
    /**
     * loader object used by {@link #execute() execute}
     */
    shared_ptr<loader> _loader;
    /**
     * storage_type object used by {@link #execute() execute}
     */
    shared_ptr<storage_type> _storage;
    /**
     * writer object used by {@link #execute() execute}
     */
    shared_ptr<writer> _writer;

public:
    /**
     * defualt constructor that initializes the private attributes of the class
     */
    process() : _loader(make_shared<bin_loader>(bin_loader())), _storage(make_shared<vector_storage>(vector_storage())), _writer(make_shared<screen_writer>(screen_writer())){};
    /**
     * destructor function
     */
    virtual ~process(){};
    /**
     * This function processes data by:<br>
     * 1) Asking the user which loader, storage type, calculation and writer they would like to use<br>
     * 2) initializing the loader, storage type, calculation and writer according to the input from the user<br>
     * 3) loading the data<br>
     * 4) calculating data<br>
     * 5) outputing the calculated data
     */
    virtual void execute();

private:
    /**
     * This function takes care of step 1 and 2 of the {@link #execute() execute function} i.e:
     * 1) Asking the user which loader, storage type, calculation and writer they would like to use<br>
     * 2) initializing the loader, storage type, calculation and writer according to the input from the user
     */
    virtual void choose_how_to_process();
};

#endif // PROCESS_H