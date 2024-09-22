//#include <TXLib.h>
#include <stdio.h> // TODO: reorder include + spaces
#include <math.h>
#include "compareDoubles.hpp"

static const double inaccuracy = 1e-6; // TODO: static

int isEqual(const double a, const double b) // TODO: add const
{
    return fabs(a - b) <= inaccuracy;
}

// char*
// const char*
// char* const
//
#if 0
bool isZero(double x) // TODO: refactor
{
    if (x <= inaccuracy && x >= -inaccuracy)
        return 1;
    else
        return 0;
}
#endif
