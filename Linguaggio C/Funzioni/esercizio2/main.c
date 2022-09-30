/*
Scrivere un programma che legge una sequenza di n interi e li memorizza
in un array a, ne calcola il quadrato di ciascuno e lo memorizza 
in un array b, ne calcola il cubo, e lo memorizza in un array c, infine
visulazizza il contenuto di b e di c.
*/


#include <stdio.h>
#include <stdlib.h>
#define N 5

int calcoloQuadrato(int);
int calcoloCubo(int);

int main(){
    int a[N], b[N], c[N], i, j;

    for (i = 0; i < N; i++)
    {
        printf("inserisci il %d numero: ", i+1); 
        scanf("%d", &a[i]);
        b[i] = calcoloQuadrato(a[i]);
        c[i] = calcoloCubo(a[i]);
    }

    for (i = 0; i < N; i++)
    {
        printf("* Il valore dell'elemento è %d, il cui quadrato è %d e il cubo %d.\n", a[i], b[i], c[i]);
    }
    

    system("PAUSE");    
    return 0;
}

int calcoloQuadrato(int x){
    int risultato;
    risultato = x * x;
    return risultato;
}

int calcoloCubo(int y){   //si può usare anche x
    int risultato; 
    risultato = y * y * y;
    return risultato; 
}