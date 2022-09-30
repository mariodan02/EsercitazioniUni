/*
Input: due stringhe (nome del file + stringa da scrivere nel file)
Il messaggio è stampato a video in caso di insuccesso
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000

int main(){
    FILE *fp;
    
    char percorso[SIZE], messaggio[SIZE];
    int i = 0;
    printf("Immettere percorso al file: ");
    scanf("%s", percorso);
    strcat(percorso, ".txt");

    fp = fopen(percorso, "w");

    if(fp == NULL)
    {
        printf("Si è verificato un errore con l'apertura del file. Il progrmma si chiuderà.\n");
        exit(1);
    }

    printf("File creato con successo!\n"
            "Inserire la stringa da inserire nel file:\n");
    scanf("%s", messaggio);
    
    fprintf(fp, "%s", messaggio);
    int fclose(FILE *);
    return 0;
}