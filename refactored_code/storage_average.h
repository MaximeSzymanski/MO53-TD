#ifndef STORAGE_AVERAGE_H
#define STORAGE_AVERAGE_H

#include "storage_type.h"
#include "calculation.h"

/**
 * The `storage_average` class calculates the average of data.
 */
class storage_average : public calculation
{
public:
    /**
     * Constructor
     */
    storage_average() {}

    /**
     * Calculates the average of the data stored in `storage`.
     * The result replaces the data stored in `storage`.
     *
     * @param storage The input data.
     */
    virtual void calculate(storage_type &storage);
};

#endif // STORAGE_AVERAGE_H