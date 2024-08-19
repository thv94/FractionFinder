#include "fractionfinder.h"
#include <stdlib.h>

// TODO: Better precision
// TODO: Validation (inputs, string conversions)

#define MAX_LENGTH          50
#define NUM_ARGS             3
#define FLOAT_ROUND_LENGTH 100

int main(int argc, char *argv[])
{
    char search_decimal[MAX_LENGTH];
    int iterations = 0;

    if ( argc != NUM_ARGS )
    {
        printf( "Usage: findfraction <decimaltofind> <iterations>\n" );

        return EXIT_FAILURE;
    }
    else
    {
        sscanf( argv[1], "%s", search_decimal );

        if ( strlen(search_decimal) > MAX_LENGTH )
        {
            printf("Too many digits. Must be less than %d\n", MAX_LENGTH);
            return 1;
        }
        else 
        {
        
            sscanf( argv[2], "%d", &iterations );

            Fraction answer = fractionfinder_find_fraction( search_decimal, iterations );

            fractionfinder_print_fraction( answer );

            return EXIT_SUCCESS;
        }
    }
}

/******************************************************************
 *
 *  Operation: fractionfinder_find_fraction
 *
 *  This operation takes a given decimal and returns the smallest
 *  equivalent fractional value pair.
 *
 *  **************************************************************/
Fraction fractionfinder_find_fraction( const char* search_decimal, int iterations )
{
    Fraction low  = { 0, 1, 0 };
    Fraction high = { 1, 1, 1 };
    Fraction mid;

    // Split the search string to just the decimal digits
    char *search_decimal_digits = strchr(search_decimal, '.') + 1;

    // Get the number of digits
    int search_decimal_digit_count = strlen(search_decimal_digits);

    // Convert search string to decimal value for numerical comparison
    char *endptr;
    double search_decimal_value = strtod(search_decimal, &endptr);

    for ( int i = 0; i < iterations; i++ )
    {
        mid.num   = low.num + high.num;
        mid.denom = low.denom + high.denom;
        mid.value = mid.num / mid.denom;

        // Convert mid.value to a string with just the decimal digits
        char temp[FLOAT_ROUND_LENGTH];
        snprintf(temp, FLOAT_ROUND_LENGTH, "%f", mid.value);
        char *computed_decimal_digits = strchr(temp, '.') + 1;

        if ( fractionfinder_compare_result(search_decimal_digit_count, search_decimal_digits, computed_decimal_digits) )
        {
            break;
        }
        else if ( mid.value < search_decimal_value )
        {
            low.num   = mid.num;
            low.denom = mid.denom;
        }
        else if ( mid.value > search_decimal_value )
        {
            high.num   = mid.num;
            high.denom = mid.denom;
        }
    }

    return mid;
} // fractionfinder_find_fraction

/******************************************************************
 *
 *  Operation: fractionfinder_compare_result
 *
 *  Compares two decimal string to see if they are equal up to the digits of the search string.
 *
 ******************************************************************/
bool fractionfinder_compare_result(int search_length, const char* search_decimal, const char* computed_decimal)
{
    bool match = true;

    for (int i = 0; i < search_length; i++)
    {
        if ( search_decimal[i] != computed_decimal[i] )
        {
            match = false;
            break;
        }
    }

    return match;
} // fractionfinder_compare_result

/******************************************************************
 *
 *  Operation: fractionfinder_print_fraction
 *
 *  This operation prints a given Fraction value.
 *
 ******************************************************************/
void fractionfinder_print_fraction( const Fraction fraction )
{
    printf("%d / %d\n", (int)fraction.num, (int)fraction.denom);
} // fractionfinder_output_answer
