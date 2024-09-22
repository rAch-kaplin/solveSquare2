//#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "SolveSquare.hpp"
#include "RunTests.hpp"

int main()
{
    // TODO: args (argc + argv), args_parse
    allTests();

    printf("#Square Solver! by rAch-kaplin\n");

    printf("#Enter a b c: ");

    double a = NAN, b = NAN, c = NAN;

    bufferScanf(&a, &b, &c);

    double x1 = NAN, x2 = NAN;

    NRoots roots_count = SolveSquare(a, b, c, &x1, &x2);
    printRoots(roots_count, x1, x2);

    return 0;
}
