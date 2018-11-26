#include <stdio.h>
#include <math.h>

void displayResult(float a, float b, float ksi, float epsilon, unsigned int nbLoop);
float newton(float a, float b, float epsilon, int* nbLoopAdress);
float f(float x);
float fDerivate(float x);
void chooseInterval(float* a, float* b);

int main() {
    printf("====Find solution of f(x)= 0 by Newton method====\n");
/// Data
    float a = 0.1, b = 0.2; // Intervals
    chooseInterval(&a, &b);
    float epsilon = 1e-6; // Precision
    float ksi = 1234; // Result
    unsigned int nbLoop = 0;
/// Computing
    ksi = newton(a,b,epsilon,&nbLoop);
/// Display results
    displayResult(a,b,ksi,epsilon,nbLoop);
    return 0;
}

void chooseInterval(float* a, float* b) {
    printf("Enter a:");
    scanf("%g", a);
    printf("Enter b:");
    scanf("%g", b);
}

float newton(float a, float b, float epsilon, int* nbLoopAdress) {
    float ksi = 0;
    float x0 = a;
    float x1 = a - (f(a)/fDerivate(a));

    // Test if we should begin with a or b
    if((x1-a)*(x1-b) > 0) {
        x0 = b;
        x1 = b - (f(b)/fDerivate(b));
    }

    while(fabs(x1-x0) > epsilon) {
        x0 = x1;
        x1 = x0 - (f(x0)/fDerivate(x0));
        ++*(nbLoopAdress+0);
    }
    ksi = x1;

    return ksi;
}

void displayResult(float a, float b, float ksi, float epsilon, unsigned int nbLoop) {
    printf("the solution in the interval [%g;%g] is ksi = %g with a margin of %g \n",a,b,ksi,epsilon);
    printf("Done with a loop number equals to %d\n", nbLoop);
}

float f(float x) {
    return x-2-log(x);
}

float fDerivate(float x) {
    return 1 - (1/x);
}