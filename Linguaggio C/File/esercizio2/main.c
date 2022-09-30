/*
Scrivere un programma che conta i caratteri all'interno di un file.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int main(){
    FILE *fp;
    int count = 0;
    char fileDaAprire[] = "ciao.txt", ch, messaggioAperto;
    printf("Genero un file causale...\n");
    system("python3 genFile.py");
    fp = fopen(fileDaAprire, "r");
    if(fp == NULL){
        printf("Si è verificato un errore nell'apertura del file. Chiusura del programma...\n");
        exit(1);
    }
    
    while((messaggioAperto = fgetc(fp)) != EOF) count++;
    printf("Il file contiene %d caratteri.\n", count);
    fclose(fp);
    return 0;
}