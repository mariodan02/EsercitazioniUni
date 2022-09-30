#include <stdio.h>
#include <stdlib.h>

#define DIM 100

// prototipi della funzioni/procedure
int inizializzaMat(int mat[][DIM]);
int traccia(int mat[][DIM], int dimensione); // somma delle diagonali principali (START: upperLeft; END: bottomRight)
void trasponi(int mat[][DIM], int trasposta[][DIM], int grandezza); // si scambiano le righe con le colonne
void somma (int mat1[][DIM], int mat2[][DIM], int matSomma[][DIM], int g1, int g2);
void prodotto(int mat1[][DIM], int mat2[][DIM], int matProdotto[][DIM], int g1, int g2);
void stampa(int mat[][DIM], int dimensione);

int main(){
    int m1[DIM][DIM], m2[DIM][DIM], m3[DIM][DIM], m4[DIM][DIM], trasposta1[DIM][DIM], trasposta2[DIM][DIM], dimensione1, dimensione2, traccia1, traccia2;
    
    // inizializzo le due matrici
    // le stampo poi a video
    dimensione1 = inizializzaMat(m1);
    dimensione2 = inizializzaMat(m2);

    // calcolo le tracce delle due matrici
    traccia1 = traccia(m1, dimensione1);
    traccia2 = traccia(m2, dimensione2);
    printf("La traccia della matrice 1 è: %d.\n", traccia1);
    printf("La traccia della matrice 2 è: %d.\n", traccia2);

    // controllo se le tracce coincidono; qualora coincidano, traspongo entrambe le matrici;
    // altrimenti, traspongo solo quella di traccia maggiore
    if(traccia1 != traccia2){
        if(traccia1 > traccia2) trasponi(m1, trasposta1, dimensione1);
        else trasponi(m2, trasposta2, dimensione2);
    } 
    else{
        trasponi(m1, trasposta1, dimensione1);
        trasponi(m2, trasposta2, dimensione2);
    }

    // calcolo la somma delle due matrici in m3[][DIM]
    somma(m1, m2, m3, dimensione1, dimensione2);

    // calcolo il prodotto delle due matrici in m4[][DIM]
    prodotto(m1, m2, m4, dimensione1, dimensione2);

    // termino il programma
    return (EXIT_SUCCESS); 
}


/*
Dal momento in cui devo stampare diverse volte le matrici, creo una procedura dedicata alla stampa, da poter riutilizzare
*/
void stampa(int mat[][DIM], int dimensione){
    int i, j;
    for(i = 0; i < dimensione; i++){
        printf("#");
        for(j = 0; j < dimensione; j++){
            printf("%4d", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}


/*
Con la funzione inizializzaMat(), inizializzo le due matrici quadrate con valori a scelta dell'utente.
Grazie al riuso del codice, mi basta invocare la funzione, cambiando il parametro di ingresso (la mat da inizializzare).
*/
int inizializzaMat(int mat[][DIM]){
    int i, j, dimensione;
    printf("Immetti la dimensione della matrice: ");
    scanf("%d", &dimensione);
    for(i = 0; i < dimensione; i++){
        for(j = 0; j < dimensione; j++){
            printf("# Immetti il numero in posizione %d, %d: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    stampa(mat, dimensione);
    return dimensione;
}


/*
Dopo aver inizializzato le matrici, mi calcolo la traccia di entrambe;
la traccia si identifica come la somma della diagonale principale, che va dalla pozione in alto a sinistra, sino in basso a destra.
*/
int traccia(int mat[][DIM], int dimensione){
    int i, j, risultato = 0;
    for (i = 0; i < dimensione; i++){
        risultato = risultato + mat[i][i];
    }
    return risultato;
}


/*
A questo punto, calcolo la trasposizione; per tenere ordinato il codice, la trasposizione avverrà come:
    m1[][DIM] -> trasposta1
    m2[][DIM] -> trasposta2
*/
void trasponi(int mat[][DIM], int trasposta[][DIM], int grandezza){
    int i, j;
    for(i = 0; i < grandezza; i++){
        for(j = 0; j < grandezza; j++)
        trasposta[i][j] = mat[j][i];
    }
    printf("La matrice trasposta ora appare come:\n");
    stampa(trasposta, grandezza);
}


/*
Non mi resta che calolare somma e prodotto, e poi stamparli
*/
void somma(int mat1[][DIM], int mat2[][DIM], int matSomma[][DIM], int g1, int g2){
    int i, j, maggiore;

    // mi servo della variabile maggiore per calcolare la dimensione più grande
    // in modo da effettuare tutte le ripetizioni strettamente necessarie per il calcolo della somma
    if(g1 > g2) maggiore = g1;
    else maggiore = g2;
    for(i = 0; i < maggiore; i++){
        for (j = 0; j < maggiore; j++){
            matSomma[i][j] = mat1[i][j] + mat2[i][j];
        }
        
    }
    printf("La matrice somma è: \n");
    stampa(matSomma, maggiore);
}

void prodotto(int mat1[][DIM], int mat2[][DIM], int matProdotto[][DIM], int g1, int g2){
    // mi servo della variabile maggiore per calcolare la dimensione più grande
    // in modo da effettuare tutte le ripetizioni strettamente necessarie per il calcolo della somma
    int i, j, maggiore;
    if(g1 > g2) maggiore = g1;
    else maggiore = g2;
    for(i = 0; i < maggiore; i++){
        for(j = 0; j < maggiore; j++){
            matProdotto[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
    printf("La matrice prodotto è: \n");
    stampa(matProdotto, maggiore);
}
