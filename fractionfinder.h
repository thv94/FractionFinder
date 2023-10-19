#include <stdio.h>

/***********
 * GLOBALS *
 ***********/

#define ITERATIONS 1000

/****************
 * CUSTOM TYPES *
 ****************/

typedef struct
{
    double num;
    double denom;
    double value;
} Fraction;

/*************************
 * FUNCTION DECLARATIONS *
 *************************/

Fraction fractionfinder_find_fraction( double search_decimal );

void fractionfinder_print_fraction( Fraction fraction );
