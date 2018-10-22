
#include <stdio.h> 
  
int horner(int poly[], int n, int x) 
{ 
    int resultat = poly[0]; 
  
    for (int i=1; i<n; i++) 
        resultat = resultat*x + poly[i]; 
  
    return resultat; 
} 
  
int main() 
{ 
    int poly[] = {2, -6, 2, -1}; 
    int x = 3; 
    int n = sizeof(poly)/sizeof(poly[0]); 
    printf("Value of polynomial is %d" ,horner(poly, n, x)); 
    return 0; 
} 