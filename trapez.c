#include <stdio.h>
#include <math.h>

float f(float x);
void display(float a, float b, unsigned int n, float A);
float trapez(float a, float b, unsigned int n);
float trapezAutoDiscretisation(float a, float b, unsigned int* discretisationBuffer,float epsilon, unsigned int step);
unsigned int getNbIntervals();
float simpson(float a, float b, unsigned int n);
float simpsonAutoDiscretisation(float a, float b, unsigned int* discretisationBuffer, float epsilon, unsigned int step);



int main(int argc, char const *argv[])
{
/// Description
    printf("==== Integral computing by trapez method ====\n");

/// Data
    float a = 0, b = 1, // integration borns
          A = 1246.;    // the integral to be calculated
          
    const float EPSILON = powf(10,-6);
    const unsigned int STEP = 10;
    unsigned int n = 2; // Discretisation number
    // n = getNbIntervals();
    float test = f(5.0);

/// Computing
    // Here we choose the discretisation number
    // A = trapez(a,b,n);
    // Here the program choose the most suitable discretisation for us depending on a given epsilon
    A = trapezAutoDiscretisation(a, b, &n, EPSILON, STEP);
    // A = simpson(a,b,n);

/// Results
    display(a,b,n,A);

    return 0;
}

void display(float a, float b, unsigned int n, float A) {
    printf("f integral between %g and %g = %g\n", a, b, A);
    printf("By discrediting %d intervals\n", n);
}

float f(float x) {
    return exp(sin(5*x));
}

unsigned int getNbIntervals() {
    int n=5;
    printf("Enter n: ");
    scanf("%d",&n);
    return n;
}

float trapez(float a, float b, unsigned int n) {
    float A = 0.;
    float h = (b-a) /n;
    float xi = a;
    float sum = 0;
    
    for(int i = 1; i < n; i++)
    {
        xi += h;
        sum += f(xi);
    }
    A = (h/2)*(f(a) + (2*sum) + f(b));
    return A;
}

float trapezAutoDiscretisation(float a, float b, unsigned int* n, float epsilon, unsigned int step) {
    unsigned int discretisation = 1;
    float I1 = trapez(a,b,discretisation);
    float I2 = trapez(a,b,discretisation+step);
    float difference = fabs(I2-I1);
    
    while(difference > epsilon){
        I1 = trapez(a, b, discretisation);
        I2 = trapez(a, b, discretisation + step);
        difference = fabs(I2-I1);
        discretisation+=step;
    }

    *n = discretisation - step;
    return I1;
}

float simpson(float a, float b, unsigned int n) {
    float A = 0.;
    float h = (b-a) /n;
    float xi = a;

    float sum1 = 0;
    float sum2 = 0;
    
    for(int i = 1; i <= n-1; i++)
    {
        sum2 += f((2*xi+h)/2);
        xi += h;
        sum1 += f(xi);
    }
    sum2 += f((2*xi+h)/2);    
    A = h/6*(f(a)+ 2*sum1+4*sum2+f(b));
    return A;
}

float simpsonAutoDiscretisation(float a, float b, unsigned int* n, float epsilon, unsigned int step) {
    unsigned int discretisation = 1;
    float I1 = simpson(a,b,discretisation);
    float I2 = simpson(a,b,discretisation+step);
    float difference = fabs(I2-I1);
    
    while(difference > epsilon){
        I1 = simpson(a, b, discretisation);
        I2 = simpson(a, b, discretisation + step);
        difference = fabs(I2-I1);
        discretisation+=step;
    }

    *n = discretisation - step;
    return I1;
}