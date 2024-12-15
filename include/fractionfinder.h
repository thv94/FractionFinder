#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************
 * CUSTOM TYPES *
 ****************/

typedef struct
{
    double num;
    double denom;
    double value;
} Fraction;

typedef enum
{
    false,
    true
} bool;

/*************************
 * FUNCTION DECLARATIONS *
 *************************/

bool fractionfinder_is_valid_decimal(const char *str);
Fraction fractionfinder_find_fractionconst (char *search_decimal, const int iterations);
void fractionfinder_print_fractionconst (Fraction *fraction);
