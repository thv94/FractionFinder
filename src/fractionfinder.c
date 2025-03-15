#include "fractionfinder.h"

#define MAX_LENGTH           50
#define MIN_ARGS              2
#define MAX_ARGS              3
#define FLOAT_ROUND_LENGTH  100
#define DEFAULT_ITERATIONS 1000

int main(int argc, char *argv[])
{
    const char* search_decimal = argv[1];
    int iterations = DEFAULT_ITERATIONS;
    Fraction answer;

    if ((argc < MIN_ARGS) || (argc > MAX_ARGS))
    {
        printf("Usage: findfraction <decimaltofind> <iterations>\n");
        return 1;
    }

    if (strlen(search_decimal) >= MAX_LENGTH)
    {
        printf("Invalid decimal input. Must be less than %d characters.\n", MAX_LENGTH);
        return 1;
    }

    if (false == fractionfinder_is_valid_decimal(search_decimal))
    {
        printf("Invalid decimal input format.\n");
        return 1;
    }

    if (NULL != argv[2])
    {
        iterations = atoi(argv[2]);

        if (iterations <= 0)
        {
            printf("Iterations must be a positive integer.\n");
            return 0;
        }
    }

    answer = fractionfinder_find_fraction(search_decimal, iterations);

    fractionfinder_print_fraction(&answer);

    return EXIT_SUCCESS;
}

bool fractionfinder_is_valid_decimal(const char *num_str)
{
    size_t i;
    unsigned int num_str_len;

    bool has_decimal_point = false;

    if ((NULL == num_str) || (*num_str == '\0'))
    {
        return false; /* Empty string is not a valid decimal */
    }

    num_str_len = (unsigned int)strlen(num_str);

    for (i = 0; i < num_str_len; i++)
    {
        char c = num_str[i];

        if (c == '.')
        {
            /* Ensure that decimal point is not at end and appears only once */
            if (has_decimal_point || (i == num_str_len - 1))
            {
                return false;
            }

            has_decimal_point = true;
        }
        else if (false == isdigit(c))
        {
            return false; /* Non-digit characters are not allowed */
        }
    }

    return true;
}

Fraction fractionfinder_find_fraction(const char *search_decimal, int iterations)
{
    int i;
    Fraction low  = { 0, 1, 0 };
    Fraction high = { 1, 1, 1 };
    Fraction mid  = { 0, 0, 0 };
    char mid_value_str[FLOAT_ROUND_LENGTH];
    const char *mid_value_digits;

    /* Split the search string to just the decimal digits */
    char *search_decimal_digits = strchr(search_decimal, '.') + 1;

    unsigned long search_decimal_num_digits = strlen(search_decimal_digits);

    double search_decimal_value = strtod(search_decimal, NULL);

    for (i = 0; i < iterations; i++)
    {
        mid.num   = low.num + high.num;
        mid.denom = low.denom + high.denom;
        mid.value = mid.num / mid.denom;

        /* Convert mid.value to a string with just the decimal digits */
        snprintf(mid_value_str, FLOAT_ROUND_LENGTH, "%.*f", (int)(search_decimal_num_digits+1), mid.value);
        mid_value_digits = strchr(mid_value_str, '.') + 1;

        if (strncmp(search_decimal_digits, mid_value_digits, search_decimal_num_digits) == 0)
        {
            break;
        }
        else if (mid.value < search_decimal_value)
        {
            low.num   = mid.num;
            low.denom = mid.denom;
        }
        else if (mid.value > search_decimal_value)
        {
            high.num   = mid.num;
            high.denom = mid.denom;
        }
    }

    return mid;
}

void fractionfinder_print_fraction(const Fraction *fraction)
{
    printf("%d / %d\n", (int)fraction->num, (int)fraction->denom);
}
