#ifndef CALCULATION_H
#define CALCULATION_H

#include "storage_type.h"

/**
 * The `calculation` class represents a generic calculation.
 */
class calculation
{
public:
    /**
     * Calculates a result from the data stored in `storage`.
     * The result replaces the data stored in `storage`.
     *
     * @param storage The input data.
     */
    virtual void calculate(storage_type &storage) = 0;
};

#endif // CALCULATION_H