#include <math.h>

#define m 11

int h1(int k)
{
    return k % m;
}

int h2(int k)
{
    return floor(m * ((k * 0.9) - floor(k * 0.9)));
}