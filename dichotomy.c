#include <stdio.h>
#include <math.h>

float f(float x);
void displayResult(float a, float b, float ksi, float epsilon);
float dichotomy(float a, float b, float epsilon);
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
/// Computing
    enterData(&a, &b);
    ksi = dichotomy(a, b, epsilon);
/// Output
    displayResult(a, b, ksi, epsilon);
    return 0;
}

void enterData(float* a, float* b) {
    printf("Enter a: ");
    scanf("%g", a);
    printf("Enter b: ");
    scanf("%g",b);
}

float dichotomy(float a, float b, float epsilon) {
    float an = a;
    float bn = b;
    float xn = (an+bn)/2;

    while(fabs(an-bn) > epsilon) {
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

void displayResult(float a, float b, float ksi, float epsilon) {
    printf("the solution in the interval [%g;%g] is ksi = %g with a margin of %g \n",a,b,ksi,epsilon);
}

float f(float x) {
    return x-2-log(x);
}

