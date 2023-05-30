#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

#include "storage_type.h"
#include "calculation.h"

/**
 * The `moving_average` class calculates the moving average of data.
 */
class moving_average : public calculation
{
private:
    /**
     * Window width used in the moving average calculation
     */
    int _window_width;

public:
    /**
     * Constructor
     *
     * @param window_width Window width used in the moving average calculation
     */
    moving_average(int window_width) : _window_width(window_width) {}

    /**
     * Calculates the moving average of the data stored in `storage`.
     * The result replaces the data stored in `storage`.
     * The window width used to calculate the moving average is given
     * in the constructor of the class.
     *
     * @param storage The input data.
     */
    virtual void calculate(storage_type &storage);
};

#endif // MOVING_AVERAGE_H