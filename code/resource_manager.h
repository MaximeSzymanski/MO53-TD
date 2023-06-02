#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "shared_enum.h"
#include "loader.h"
#include "storage_type.h"
#include "writer.h"
#include "calculation.h"
#include <memory>

/**
 * This class represents a resource manager that creates various resources.
 */
class resource_manager
{
public:
    /**
     * Creates a loader object based on the specified input type.
     *
     * @param input The input type to create the loader for.
     * @param load_file The file to load data from.
     * @return A shared pointer to the newly created loader object.
     */
    static std::shared_ptr<loader> make_loader(shared_enum::input, std::string load_file);

    /**
     * Creates a storage object based on the specified storage type.
     *
     * @param storage The storage type to create the storage object for.
     * @return A shared pointer to the newly created storage object.
     */
    static std::shared_ptr<storage_type> make_storage(shared_enum::storage);

    /**
     * Creates a writer object based on the specified output type.
     *
     * @param output The output type to create the writer for.
     * @return A shared pointer to the newly created writer object.
     */
    static std::shared_ptr<writer> make_writer(shared_enum::output);

    /**
     * Creates a calculation object based on the specified calculation type and window width.
     *
     * @param calculation The calculation type to create the calculation object for.
     * @param window_width The window width to use for the calculation (defaults to 0 if not specified).
     *                     This parameter is only used if the calculation type is shared_enum::calculation::MOVING_AVG
     * @return A shared pointer to the newly created calculation object.
     */
    static std::shared_ptr<calculation> make_calculation(shared_enum::calculation, int window_width = 0);
};

#endif
