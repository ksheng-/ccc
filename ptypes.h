#ifndef PTYPES_H
#define PTYPES_H

enum num_types
{
    INTEGER,
    LONG_INTEGER,
    LONGLONG_INTEGER,
    UNSIGNED_INTEGER,
    UNSIGNED_LONG_INTEGER,
    UNSIGNED_LONGLONG_INTEGER,
    FLOAT_REAL,
    DOUBLE_REAL,
    LONG_DOUBLE_REAL
} num_types;

struct num 
{
    union value
    {
        int s_int;
        long l_int;
        long long ll_int;
        unsigned int us_int;
        unsigned long ul_int;
        unsigned long long ull_int;
        double dbl;
        long double l_dbl;
        float flt;
    } value;

    int type;
};
typedef struct num num;

#endif

