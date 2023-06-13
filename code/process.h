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
#include "calculation.h"

using namespace std;

/**
 * Class used to process data
 */
class process
{
private:
    /**
     * loader object used
     */
    shared_ptr<loader> _loader;
    /**
     * storage_type object
     */
    shared_ptr<storage_type> _storage;
    /**
     * Calculate object
     */
    shared_ptr<calculation> _calculation;

    /**
     * writer object
     */
    shared_ptr<writer> _writer;

public:
    /**
     * Constructor of a process
     * @param loader loads data
     * @param storage stores the data during the process
     * @param calculation applies a calculation function on the loaded data
     * @param writer writes the results of calculation
     */
    process(shared_ptr<loader> loader, shared_ptr<storage_type> storage, shared_ptr<calculation> calculation, shared_ptr<writer> writer) : _loader(loader), _storage(storage), _calculation(calculation), _writer(writer) {}

    /**
     * destructor function
     */
    virtual ~process(){};
    /**
     * This function processes data by:<br>
     * 1) loading data by using a loader object into a storage_type object <br>
     * 2) calculating a result by using a calculation object and the loaded data <br>
     * 3) writing the result by using a writer object<br>
     * The objects used to process the data are given in the constructor of the process class.
     */
    virtual void execute();
};

#endif // PROCESS_H