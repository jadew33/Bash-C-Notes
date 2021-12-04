#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// IMPORTANT -- Must compile: gcc math_demo.c -lm -o math_demo

void normpdf(double x, double *pdf)
{
    *pdf = 1 / (sqrt(2 * M_PI)) * exp((-pow(x, 2) / 2));
}

void add(double x, double y, double *result)
{
    *result = x + y;
}

void main(int argc, char *argv[])
{
    double pdf, res;
    if (argc == 2)
    {
        normpdf(atof(argv[1]), &pdf);
        printf("phi(x) = %0.8f\n", pdf);
    }
    else if (argc == 3)
    {
        add(atof(argv[1]), atof(argv[2]), &res);
        printf("%6.2f+%6.2f = %6.2f\n",atof(argv[1]),atof(argv[2]),res);
    }
    else
    {
        fprintf(stderr, "Usage: math_demo num1 [num2]\n");
        exit(1);
    }
}
