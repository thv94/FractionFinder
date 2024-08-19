#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

Fraction fractionfinder_find_fraction( const char* search_decimal, const int iterations );
bool fractionfinder_compare_result(const int search_length, const char* search_decimal, const char* computed_decimal);
int fractionfinder_count_decimal_digits( const char* search_decimal );
void fractionfinder_print_fraction( const Fraction fraction );
