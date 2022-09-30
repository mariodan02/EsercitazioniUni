/*
Leggi; scrivi su "prova.txt"
Leggi finché non si inserisce " $"; verifica chiusura del file
*/

//    ==============
// || NON FUNIONANTE ||
//    ==============


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 1000

FILE *ApriFile(char *);

int main(){
    FILE *fp;
    char messaggio[SIZE + 1];
    fp = ApriFile("w");
    printf("Inserisci caratteri da scrivere. Termina con \" $\".\n ");
    scanf("%s", messaggio);
    fprintf(fp, "%s", messaggio);
    while ((strcmp(messaggio, " $")) != 0){
        scanf("%s", messaggio);
        fprintf(fp, "%s", messaggio);
    }
    fclose(fp);
    if (fp == 0) printf("File chiuso correttamente. Termino il programma.\n");
    else {
        printf("FIle non chiuso correttamente. Errore.\n");
        exit(1);
    }
    
    return 0;
}


FILE *ApriFile(char* mode){
    FILE *fptr;
    char path[SIZE + 1];
    printf("Immetti nome file: ");
    scanf("%s", path);
    fptr = fopen(path, mode);
    if (fptr == NULL) exit (1);
    return fptr;
}