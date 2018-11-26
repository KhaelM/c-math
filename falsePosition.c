#include <stdio.h>
#include <math.h>

void displayResult(float a, float b, float eps, float ksi, unsigned int nbLoop);
float falsePosition(float a, float b, float eps, unsigned int* nbLoop);
float f(float x);

int main()
{
    printf("==== Find f(x)=0 by false position method ====\n ");
/// Data
    float   a = 0.1, b = 1, // Interval limits
            ksi = 0, // Result
            eps = 1e-6; // Precision
    
    unsigned int nbLoop = 0;

/// Computing
    ksi = falsePosition(a,b,eps, &nbLoop);

/// Display result
    displayResult(a, b, eps, ksi, nbLoop);
    return 0;
}

void displayResult(float a, float b, float eps, float ksi, unsigned int nbLoop) {
    printf("Resolution of f(x) = 0\n");
    printf("Solution in [%g; %g] is ksi = %g with a precision of eps = %g\n", a, b, ksi, eps);
    printf("Done with a loop number equals to : %d\n", nbLoop);
}

float falsePosition(float a, float b, float eps, unsigned int* nbLoop) {
    float ksi = 0.42;
    float x0 = a;
    float x1 = a - ((b-a)*f(a))/(f(b)-f(a));

    
    while(fabs(x1-x0) > eps){
        ++*(nbLoop+0);
        if(f(a)*f(x1) <= 0) {
            b = x1;
        } else {
            a = x1;
        }
        x0 = x1;
        x1 = a - (b-a)*f(a)/(f(b)-f(a));
    }
    ksi = x1;
    return ksi;
}

float f(float x) {
    return x - 2 - log(x);
}