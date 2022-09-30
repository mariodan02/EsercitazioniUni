/*
Dato un file con 10 interi, uno per riga:
Scrivere un file che:
    * acquisisca l'array e lo stampi a video;
    * stampi max e min, restituiti dalle funzioni:
        * int max(int a[], int dim);
        * int min(int a[], int dim).   
*/

#include <stdlib.h>
#include <stdio.h>
#define DIM 10

int max(int *, int);
int min(int *, int);


int main(){
    FILE *fp;
    int a[DIM], i, massimo, minimo;
    char path[] = "input.txt";

    printf("Genero un file casuale...\n");
    system("python3 genFile.py");
    
    fp = fopen(path, "r");

    if(fp == NULL){
        printf("Si è verificato un errore imprevisto nell'apertura del file. Termino il programma.\n");
        exit(1);
    }

    for (i = 0; i < DIM; i++){
        fscanf(fp, "%d\n", &a[i]);
    }
    massimo = max(a, DIM);
    minimo = min(a, DIM);

    printf("I valori dell'array: \n");
    for (i = 0; i < DIM; i++)
    {
        printf("* %d;\n", a[i]);
    }

    printf("=========================\n");
    printf("Il valore massimo è: %d;\n", massimo);
    printf("Il valore minimo è: %d.\n", minimo);
    
    return 0;
}

int max(int * a, int size){
    int i, massimo;
    massimo = a[0];
    for(i = 1; i < size; i++){
        if(a[i] > massimo) massimo = a[i];
    }
    return massimo;
}

int min(int * a, int size){
    int minimo, i;
    minimo = a[0];
    for (i = 1; i < size; i++)
    {
        if(a[i] < minimo) minimo = a[i];
    }
    
    return minimo;
}