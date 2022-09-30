/*
Dato un file contenente una sequenza ignota di numeri interi positivi (scritti in lettere cifra per cifra e terminati dalla parola stop)
Scrivere un programmma in C che legge da tastiera il nome del file e stampa la somma dei numeri letti.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> // occorre utilizzare l'argomento "-lm" in compilazione!
#include <ctype.h>
#include <string.h>

#define SIZE 1000

int trascrizione(char *);
int compose(int *, int);

int main(){
    int i, num[SIZE], count = 0, somma = 0;
    char path[] = "dati.txt", numLit[SIZE], ch;
    FILE *fp;

    printf("Genero il file...\n");
    system("python3 genFile.py");
    // apro il file
    fp = fopen(path, "r");
    if(fp == NULL) exit(1);

    // leggo il file e trascrivo
    while((ch = getc(fp)) != EOF){
        while (strcmp(numLit, "stop") != 0){
            fscanf(fp, "%s", numLit);
            num[i] = trascrizione(numLit);
            i++;
            count++;
        }
        somma = compose(num, count) + somma;
        i = 0;
        int num[] = {0};
    }
    
    printf("La somma dei numeri nel file è: %d. \n");
    fclose(fp);
    return 0;
}

int trascrizione(char* numLit){
    if(strcmp(numLit, "zero") == 0) return 0;
    if(strcmp(numLit, "uno") == 0) return 1;
    if(strcmp(numLit, "due") == 0) return 2;
    if(strcmp(numLit, "tre") == 0) return 3;
    if(strcmp(numLit, "quattro") == 0) return 4;
    if(strcmp(numLit, "cinque") == 0) return 5;
    if(strcmp(numLit, "sei") == 0) return 6;
    if(strcmp(numLit, "sette") == 0) return 7;
    if(strcmp(numLit, "otto") == 0) return 8;
    if(strcmp(numLit, "nove") == 0) return 9;
}

int compose(int * num, int dim){
    int i, index = 0, numero = 0;
    for (i = dim; i > 0; i--)
    {
        numero = numero + (pow(10, index) * num[i]);
        index++;
    }
    numero = (int)numero;
    return numero;
}