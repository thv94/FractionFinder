#include <stdio.h>

typedef struct Fraction 
{
    double num;
    double denom;
    double value;
} Fraction;

Fraction findFraction(double searchnum);

void outputAnswer(Fraction answer);
