#include <stdio.h>
#include <math.h>

float f(float x);
void displayResult(float a, float b, float ksi, float epsilon, unsigned int nbLoop);
float dichotomy(float a, float b, float epsilon, unsigned int* nbLoop);
void enterData(float* a, float* b);

int main(int argc, char const *argv[])
{
/// Presentation
    printf("===Solving f(x)=0 by dichotomy\n===");
/// Data
    float a = 0.1, b = 1;
    float epsilon = 1e-6; // the precision
    float ksi = 1234; // the solution to find
    float f = -36.5f;
    unsigned int nbLoop = 0;
/// Computing
    enterData(&a, &b);
    ksi = dichotomy(a, b, epsilon, &nbLoop);
/// Output
    displayResult(a, b, ksi, epsilon, nbLoop);
    return 0;
}

void enterData(float* a, float* b) {
    printf("Enter a: ");
    scanf("%g", a);
    printf("Enter b: ");
    scanf("%g",b);
}

float dichotomy(float a, float b, float epsilon, unsigned int* nbLoop) {
    float an = a;
    float bn = b;
    float xn = (an+bn)/2;

    while(fabs(an-bn) > epsilon) {
        ++*(nbLoop);
        xn = (an+bn)/2;
        // if ksi belongs to [an, xn]
        if(f(an)*f(xn) < 0) {
            bn = xn;
        } else {
            an = xn;
        }
    }
    return xn;
}

void displayResult(float a, float b, float ksi, float epsilon, unsigned int nbLoop) {
    printf("the solution in the interval [%g;%g] is ksi = %g with a margin of %g \n",a,b,ksi,epsilon);
    printf("Done with a loop number equals to %d\n", nbLoop);
}

float f(float x) {
    return x-2-log(x);
}