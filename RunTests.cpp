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
                                          //{1,   2,   3, NAN, NAN,  ZERO_ROOT},
                                          {1,   0,  -4,  -2,   2,   TWO_ROOT},
                                          {1,   0,   0,   0,  -0,  ONE_ROOT}};

    const int nTests = sizeof(data) / sizeof(data[0]);

    for (int i = 0; i < nTests; i++)
        runTest(&data[i], i);
}

// TODO: add pointer
int runTest (const struct UNIT_variables *ptr_data, int test_number)
{
    double x1 = NAN, x2 = NAN;
    NRoots roots_count = SolveSquare(ptr_data->a, ptr_data->b, ptr_data->c, &x1, &x2);
    if (!isEqual(roots_count, ptr_data->rootsCountCorrect) || !isEqual(x1, ptr_data->x1Correct) ||
        !isEqual(x2, ptr_data->x2Correct))
    {
        printf("ERROR: test № %d, a = %lg, b = %lg, c = %lg, x1 = %lg, x2 = %lg, rootsCount = %d\n"
                "x1Correct = %lg, x2Correct = %lg, rootsCountCorrect = %d\n", test_number,
        ptr_data->a, ptr_data->b, ptr_data->c, x1, x2, roots_count, ptr_data->x1Correct, ptr_data->x2Correct,
        ptr_data->rootsCountCorrect);
    }
    return 1;
}
