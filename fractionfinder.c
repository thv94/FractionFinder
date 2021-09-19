#include "fractionfinder.h"

int main() 
{
    const double searchnum = 0.314159;

    Fraction answer = findFraction(searchnum);

    outputAnswer(answer);

    return 0;
}

Fraction findFraction(double searchnum)
{
    const int ITERATIONS = 1000;
    Fraction low = {0, 1, 0};
    Fraction high = {1, 1, 1};
    Fraction mid;

    for (int i = 0; i < ITERATIONS; i++) 
    {
        mid.num = low.num + high.num;
        mid.denom = low.denom + high.denom;
        mid.value = mid.num / mid.denom;

        if (mid.value < searchnum) {
            low.num = mid.num;
            low.denom = mid.denom;
        } else if (mid.value > searchnum) {
            high.num = mid.num;
            high.denom = mid.denom;
        } else {
            break;
        }
    }

    return mid;
}

void outputAnswer(Fraction answer) 
{
    printf("%f\n", answer.value);
    printf("%f\n", answer.num);
    printf("%f\n", answer.denom);
}