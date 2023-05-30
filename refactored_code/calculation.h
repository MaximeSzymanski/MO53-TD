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
     * Calculates the result of the calculation.
     *
     * @param storage The input data.
     * @return new storage_type object that contains the result of the calculation
     */
    virtual storage_type calculate(const storage_type &storage) = 0;
};

#endif // CALCULATION_H