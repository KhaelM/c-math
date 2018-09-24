#include <stdio.h>
#include <math.h>

void displayResult(float a, float b, float delta, float c, float x1, float x2);
void computeSol(float a, float b, float c, float delta, float *x1, float *x2);

int main(int argc, char const *argv[])
{
    printf("Solving a quadratic equation whose form is ax² + bx + c = 0\n");
/// Required data
    float a = 1, b = 4, c = 5;
    float x1 = 0, x2 = 0.;
    float delta = 0;

/// Discriminant calculation
    delta = b*b-4*a*c;

/// Roots calclulation
    computeSol(a, b, c, delta, &x1, &x2);

/// Results output
    displayResult(a, b, c, delta, x1, x2);
    return 0;
}

void displayResult(float a, float b, float c, float delta, float x1, float x2) {
    printf("Equation : %gx² + %gx + %g = 0\n", a, b, c );
    printf("a = %g, b = %g, c = %g\ndelta = %g\n", a, b, c, delta);
    if (delta  >= 0) {
        printf("Real roots : x1 = %g, x2 = %g\n", x1, x2);
    }
    else {
        printf("Complex roots :\n");
        printf("x1 = %g/%g + %g/%g*i, x2 = %g/%g - %g/%g*i\n", -b, 2*a, sqrt(-delta), 2*a, -b, 2*a, sqrt(-delta), 2*a);
        printf("or also \nc1 = %g + %g*i, c2 = %g - %g*i\n", -b/2*a, sqrt(-delta)/2*a, -b/2*a, sqrt(-delta)/2*a);
    }
}

void computeSol(float a, float b, float c, float delta, float *x1, float *x2) {
/// Test of delta's sign
    if(delta < 0) {
        printf("The discriminant is negative : no real roots");
    } else {
/// Calculation of roots if they exist
        *x1 = (-b + sqrt(delta))/(2*a);
        *x2 = (-b - sqrt(delta))/(2*a);
    }
}