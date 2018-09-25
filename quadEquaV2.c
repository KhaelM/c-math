#include <stdio.h>
#include <math.h>

void computeSol(float a, float b, float c, float delta, float* x1, float* x2);
void displayResult(float a, float b, float c, float delta, float x1, float x2);
int sign(float b);

int main(int argc, char const *argv[])
{
/// Required data
    float epsilon = pow(10, -20);
    float a = epsilon, b = 1/epsilon, c = -epsilon;
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

void computeSol(float a, float b, float c, float delta, float* x1, float* x2) {
    float q = -(b+sign(b)*sqrt(delta))/2;
    *x1 = q/a;
    *x2 = c/q;
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

int sign(float b) {
    if(b >= 0)
        return 1;
    else
        return -1;
}