//#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include "RunTests.hpp"
#include "compareDoubles.hpp"
#include "SolveSquare.hpp"

void allTests()
{
    // TODO: const
    const struct UNIT_variables data[] = {{1,  -3,   2,   1,   2,   TWO_ROOT},
                                          {1,  -5,   6,   2,   3,   TWO_ROOT},
                                          {1,   2,   1,  -1,  -1,   ONE_ROOT},
                                          {1,   0,  -9,  -3,   3,   TWO_ROOT},
                                          {1,   0,   0,   0,   0,   ONE_ROOT},
                                          {1,   2,   3, NAN, NAN,  ZERO_ROOT},
                                          {1,   0,  -4,  -2,   2,   TWO_ROOT},
                                          {1,   0,   0,   0,  -0,  ONE_ROOT}};

    const int nTests = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < nTests; i++)
        runTest(data[i], i);
}

// TODO: add pointer
int runTest (struct UNIT_variables data, int test_number)
{
    double x1 = NAN, x2 = NAN;
    NRoots roots_count = SolveSquare(data.a, data.b, data.c, &x1, &x2);
    if (!isEqual(roots_count, data.rootsCountCorrect) || !isEqual(x1, data.x1Correct) ||
        !isEqual(x2, data.x2Correct))
    {
        printf("ERROR: test ¹ %d, a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, rootsCount = %d\n"
                "x1Correct = %lg, x2Correct = %lg, rootsCountCorrect = %d\n", test_number,
        data.a, data.b, data.c, x1, x2, roots_count, data.x1Correct, data.x2Correct,
        data.rootsCountCorrect);
    }
    return 1;
}
