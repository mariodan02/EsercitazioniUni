/*
Realizzare un programma che permetta il
caricamento di una matrice A quadrata di interi.
– Il programma verificherà se la matrice è di tipo simmetrico.
– Visualizzare la matrice A.


UNA MATRICE È SIMMETRICA SE MAT[A][B] È UGUALE A MAT[B][A]
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int main(){
    int a[SIZE][SIZE];
    int i, j;
    int simmetrico = 1;

    for(i = 0; i < SIZE; i++){
        for(j = 0; j < SIZE; j++){
            printf("Inserisci i valori della matrice \n");
            scanf("%d", &a[i][j]);
        }
    }
    
    while(simmetrico != 0){
        for(i = 0; i < SIZE; i++){
            for(j = 0; j < SIZE; j++){
                if(a[i][j] != a[j][i]) simmetrico = 0;
            }
        }
    }
 
    if (simmetrico == 0) printf("La matrice non è simmetrica \n");
    else printf("la matrice è simmetrica \n");
    system("PAUSE");
    return 0;
}
