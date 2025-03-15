#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

bool fractionfinder_is_valid_decimal(const char *str);
Fraction fractionfinder_find_fraction(const char *search_decimal, const int iterations);
void fractionfinder_print_fraction(const Fraction *fraction);
