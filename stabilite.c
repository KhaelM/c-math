#include <stdio.h>
#include <math.h>
 
double iteration();
double reccurence();
void displayResult(double phi, double phi50);
double methode1(double phi);
double methode2(double phi);

int main(int argc, char const *argv[])
{
    printf("Test de stabilité\n");
/// Données
    double phi = (sqrt(5)-1)/2, phi50 = 0;

/// Calculs
    // phi50 = methode1(phi);
    phi50 = methode2(phi);

/// Résultats
    displayResult(phi, phi50);
    return 0;
}

double iteration() {

}

double reccurence() {

}

void displayResult(double phi, double phi50) {
    printf("phi = %g, phi50 = %g\n",phi, phi50);
}

double methode1(double phi) {
    double phi50=phi;
    
    for(int i = 1; i < 50; i++)
    {
        phi50 *= phi;
        printf("boucle i = %d\tphi50 = %g\n", i, phi50);
    }
    
    return phi50;
}

double methode2(double phi)
{
    double phi50 = 0, p1 = 0, p2 =0, p3 = 0;
/*
    phi ^3 = phi^1 - phi^2
    phi^4 = phi^2 - phi^3
*/ 
    //  Initialisation
    // rang 1
    p1 = phi; p2 = phi*phi;

    for(int i = 1; i <= 50; ++i) {
        p3 = p1 - p2;
        p1 = p2;
        p2 = p3;
        printf("i = %d\t p3 = %g\n", i, p3);
    }
    phi50 = p3;
    return phi50;
}