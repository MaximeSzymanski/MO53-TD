#ifndef STORAGE_SUM_H
#define STORAGE_SUM_H

#include "storage_type.h"
#include "calculation.h"

/**
 * The `moving_average` class calculates the moving average of data.
 */
class storage_sum : public calculation
{
public:
    /**
     * Constructor
     */
    storage_sum() {}

    /**
     * Calculates the sum of the data stored in `storage`.
     * The result replaces the data stored in `storage`.
     *
     * @param storage The input data.
     */
    virtual void calculate(storage_type &storage);
};

#endif // STORAGE_SUM_H