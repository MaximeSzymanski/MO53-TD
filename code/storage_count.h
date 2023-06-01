#ifndef STORAGE_COUNT_H
#define STORAGE_COUNT_H

#include "storage_type.h"
#include "calculation.h"

/**
 * The `storage_count` class counts the amount of data members stored in
 * a storage_type object.
 *
 * @see storage_type
 */
class storage_count : public calculation
{
public:
    /**
     * Constructor
     */
    storage_count() {}

    /**
     * Counts the amount of data stored in `storage`.
     * The result replaces the data stored in `storage`.
     *
     * @param storage The input data.
     */
    virtual void calculate(storage_type &storage);
};

#endif // STORAGE_COUNT_H