/* 
calcolare il binomiale di due valori
coefficiente binomiale:
n! / (k!(n-k)!)
*/

#include <stdio.h>
#include <stdlib.h>

double calcoloBinomiale(int, int);
int fattoriale(int);

int main() {
    int n, k;
    double binomiale;
    int fattoriale;
    
    printf("Scegli il valore di n: \n");
    scanf("%d", &n);

    printf("scegli il valore di k: \n");
    scanf("%d", &k);

    binomiale = calcoloBinomiale(n, k);

    printf("il risultato del binomiale è: %f \n" ,binomiale);
    system("PAUSE");
    return 0;
}

double calcoloBinomiale(int n, int k){
    double binomiale;
    int a, b, c;
    a = fattoriale(n);
    b = fattoriale(k);
    c = fattoriale(n - k);

    binomiale = a / (b * c);
    return binomiale;
}

int fattoriale(int x){
    int fattoriale = 1;
    for(int i = 1; i <= x; i++){
        fattoriale = fattoriale * x;
    }
    return fattoriale;
}