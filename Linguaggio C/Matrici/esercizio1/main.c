/*
Scrivere un programma che inizializzi e visualizzi una matrice 10x10 con i dati della tavola pitagorica
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int matrice[10][10], i = 0, j = 0;
    for(i = 1; i <= 10; i++){
        for(j = 1; j <= 10; j++){
            matrice[i][j] = j * i;
        }
    }
    for(i = 1; i <= 10; i++){
        for(j = 1; j <= 10; j++){
            printf("%4d", matrice[i][j]);
            }
        printf("\n");
        }
    system("PAUSE");
    return 0;
}