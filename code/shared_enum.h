#ifndef SHARED_ENUM_H
#define SHARED_ENUM_H

namespace shared_enum
{
    enum input
    {
        INPUT_TEXT,
        INPUT_BIN
    };
    enum storage
    {
        LIST,
        VECTOR
    };
    enum output
    {
        OUTPUT_TEXT,
        OUTPUT_BIN,
        OUTPUT_SCREEN
    };
    enum calculation
    {
        MOVING_AVG,
        AVG,
        SUM,
        COUNT
    };
}

#endif