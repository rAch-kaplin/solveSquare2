//#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "SolveSquare.hpp"
#include "compareDoubles.hpp"

NRoots SolveSquare(double a, double b, double c, double *x1, double *x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (isEqual(a, 0))
    {
        return solveLinearSquare(b, c, x1);
    }

    double discriminant = b * b - 4 * a * c;

    if (isEqual(discriminant, 0))
    {
        *x1 = *x2 = -b / (2 * a);
        return ONE_ROOT;
    }

    if (discriminant > 0)
    {
        double sqrt_discriminant = sqrt(discriminant);
        *x1 = (-b - sqrt_discriminant) / (2 * a);
        *x2 = (-b + sqrt_discriminant) / (2 * a);
        return TWO_ROOT;
    }

    return ZERO_ROOT;
}

NRoots solveLinearSquare(double b, double c, double *x1)
{
    if (isEqual(b, 0))
    {
        return isEqual(c, 0) ? SS_INF_ROOTS : ZERO_ROOT;
    }

    *x1 = -c / b;
    return ONE_ROOT;
}

