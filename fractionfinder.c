#include "fractionfinder.h"

int main(int argc, char *argv[])
{
    double search_decimal;

    if ( argc != 2 )
    {
        printf( "Usage: findfraction <num>\n" );

        return -1;
    }
    else
    {
        sscanf( argv[1], "%lf", &search_decimal );

        printf( "Decimal to Search = %f\n", search_decimal );

        Fraction answer = fractionfinder_find_fraction( search_decimal );

        fractionfinder_print_fraction( answer );

        return 0;
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
Fraction fractionfinder_find_fraction( double search_decimal )
{
    Fraction low  = { 0, 1, 0 };
    Fraction high = { 1, 1, 1 };
    Fraction mid;

    for ( int i = 0; i < ITERATIONS; i++ )
    {
        mid.num   = low.num + high.num;
        mid.denom = low.denom + high.denom;
        mid.value = mid.num / mid.denom;

        if ( mid.value < search_decimal )
        {
            low.num   = mid.num;
            low.denom = mid.denom;
        }
        else if ( mid.value > search_decimal )
        {
            high.num   = mid.num;
            high.denom = mid.denom;
        }
        else
        {
            break;
        }
    }

    return mid;
} // fractionfinder_find_fraction

/******************************************************************
 *
 *  Operation: fractionfinder_print_fraction
 *
 *  This operation prints a given Fraction value.
 *
 ******************************************************************/
void fractionfinder_print_fraction( Fraction fraction )
{
    printf("%f\n", fraction.value);
    printf("%f\n", fraction.num);
    printf("%f\n", fraction.denom);
} // fractionfinder_output_answer
