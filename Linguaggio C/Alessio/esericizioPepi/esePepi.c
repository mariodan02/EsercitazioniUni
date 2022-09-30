#include <stdio.h>
#include <stdlib.h>
#define lenght 10

int stampaprodotto(int righe, int prodotto[][lenght]);
int prodottomat(int righe, int prodotto[][lenght], int a[][lenght]);
int inizaprodotto(int righe, int prodotto[][lenght]);
int stampasomma(int righe, int somma[][lenght]);
int sommamat(int righe, int somma[][lenght], int a[][lenght]);
int iniziasomma(int righe, int somma[][lenght]);
int calcolatraccia(int a[][lenght], int righe);
int creamat(int a[][lenght], int righe );

int main(int argc, char** argv) {

    int a[lenght][lenght], righe, colonne, t1, t2, somma[lenght][lenght], prodotto[lenght][lenght];
    
    iniziasomma(righe, somma);
    iniziaprodotto(righe, prodotto);
    printf("Dammi una prima matrice:\n");
    creamat(a, righe);
    t1=calcolatraccia(a, righe);
    sommamat(righe, somma, a);
    prodottomat(righe, prodotto, a);
    printf("Dammi una seconda matrice:\n");
    creamat(a, righe);
    t2=calcolatraccia(a, righe);
    sommamat(righe, somma, a);
    prodottomat(righe, prodotto, a);
    printf("La matrice somma e':\n");
    stampasomma(righe, somma);
    printf("la matrice prodotto e':\n");
    stampaprodotto(righe, prodotto);
    return (EXIT_SUCCESS);
}

/*
perché chiedere due valori?
la funzione però è corretta
*/
creamat(int a[][lenght], int righe ){
    int  i, j, colonne;

    printf("Inserisci il numero di righe e colonne di una matrice quadrata\n(una matrice viene detta quadrata quando ha lo stesso numero di righe e colonne)\nRighe: ");
    scanf("%d", &righe);
    printf("Colonne: ");
    scanf("%d", &colonne);
    
    
    while(righe!=colonne){
        printf("Non hai inserito una matrice quadrata, per favore inserisci dei dati corretti\nRighe:");
        scanf("%d", &righe);
        printf("Colonne: ");
        scanf("%d", &colonne); 
    }
    
    for(i=0; i<righe; i++){
        printf("_____\nriga #%d:\n", i);
        for(j=0; j<righe; j++){
            printf("colonna #%d:\n", j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("_______\n");
}

// somma i valori con indice h & w uguali; salva in traccia, che va su tutta la matrice
calcolatraccia(int a[][lenght], int righe){
    int traccia=0, i, j;
    for(i=0; i<righe; i++){
        for(j=0; j<righe; j++){
            if(i==j){
                traccia=traccia + a[i][j];
            }
        }
    }
    return traccia;
}

// inizializza con elemento neutro somma
iniziasomma(int righe, int somma[][lenght]){
    
    int i, j;
    for(i=0; i<righe; i++){
        for(j=0; j<righe; j++){
            somma[i][j]=0;
        }
    }
}

sommamat(int righe, int somma[][lenght], int a[][lenght]){
    int i, j;
    
    for(i=0; i<righe; i++){
        for(j=0; j<righe; j++){
            somma[i][j]=somma[i][j]+a[i][j];
        }
    }
}

stampasomma(int righe, int somma[][lenght]){
    int i, j;
    for(i=0; i<righe; i++){
        for(j=0; j<righe; j++){
            printf("%d", somma[i][j]);
        }
    }
}

// inizializza con elemento neutro prodotto
iniziaprodotto(int righe, int prodotto[][lenght]){
    
    int i, j;
    for(i=0; i<righe; i++){
        for(j=0; j<righe; j++){
            prodotto[i][j]=1;
        }
    }
}

prodottomat(int righe, int prodotto[][lenght], int a[][lenght]){
    int i, j;
    
    for(i=0; i<righe; i++){
        for(j=0; j<righe; j++){
            prodotto[i][j]=prodotto[i][j]*a[i][j];
        }
    }
}

stampaprodotto(int righe, int prodotto[][lenght]){
    int i, j;
    for(i=0; i<righe; i++){
        for(j=0; j<righe; j++){
            printf("%d", prodotto[i][j]);
        }
    }
}