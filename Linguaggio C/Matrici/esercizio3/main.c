/*
Realizzare un programma che permetta il caricamento di una matrice A quadrata di interi.
– Il programma caricherà un vettore B di interi nel seguente modo:
ogni elemento alla posizione i-esima del vettore B sarà uguale
al prodotto di tutti i valori della matrice A alla riga i-esima
divisibili per 3. Se non ci sono valori divisibili per 3 il prodotto è
0.
– Calcolare e visualizzare il valore massimo del vettore B.
– Visualizzare la matrice A ed il vettore B.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int main(){
    int a[SIZE][SIZE];
    int b[SIZE];
    int i, j;
    int prodotto = 1;
    int max = 0;
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("Scegli i valori della matrice \n");
            scanf("%d" ,&a[i][j]);
            if(a[i][j] % 3 == 0)
                prodotto = prodotto * a[i][j];
        }
        if(prodotto == 1)
            b[i] = 0;
        else {
            b[i] = prodotto;
            prodotto = 1;

            if(b[i] > max)
                max = b[i];
        }
    }

    printf("La matrice è: \n");
    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("%4d" ,a[i][j]);
        }
        printf("\n");
    }
    printf("L'array è: \n");
    for(i = 0; i < SIZE; i++){
        printf("%4d " ,b[i]);
    }
    printf("\n");

    printf("Il massimo è: %d.\n" ,max);

    

    //system("PAUSE");
    return 0;
}   