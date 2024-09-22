 #ifndef _HRUN_TEST
 #define _HRUN_TEST
 #include "SolveSquare.hpp"

struct UNIT_variables
{
    double a;
    double b;
    double c;
    double x1Correct;
    double x2Correct;
    enum NRoots rootsCountCorrect;

};

void allTests();

int runTest(struct UNIT_variables data, int test_number);

#endif //_HRUN_TEST
