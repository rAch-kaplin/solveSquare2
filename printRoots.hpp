#ifndef _HPRINTROOTS
#define _HPRINTROOTS // TODO: _H

enum NRoots
{
    ZERO_ROOT    =  0,
    ONE_ROOT     =  1,
    TWO_ROOT     =  2,
    SS_INF_ROOTS = -1
};

void printRoots(NRoots roots_count, double x1, double x2);

void skipLine();

void bufferScanf (double *a, double *b, double *c);

#endif // _HPRINTROOTS

