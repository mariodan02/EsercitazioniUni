/*
Formattazione del file:

PRIMA RIGA: numRighe(dimW), numColonne(dimH), dominante
RIGA nESIMA: valoreNonDominante, posH, posW

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

FILE *apri(char *, char *);

int main(){
    int altezza, larghezza, dominante, valNonDominante, posH, posW, i, j;
    int mat[MAXSIZE][MAXSIZE];
    char ch;
    char pathReading[] = "lettura.txt";
    char pathWriting[] = "scrittura.txt"; 
    FILE *reading;
    FILE *writing;
    printf("Genero file casuale...\n");
    system("python3 genFile.py");
    reading = apri("r", pathReading);
    fscanf(reading, "%d", &altezza);
    fscanf(reading, "%d", &larghezza);
    fscanf(reading, "%d", &dominante);
    for (i = 0; i < altezza; i++){
        for (j = 0; j < larghezza; j++)
        {
            mat[i][j] = dominante;
        }
        
    }
    writing = apri("w", pathWriting);
    while ((ch = getc(reading)) != EOF){
        fscanf(reading, "%d %d %d",&posW, &posH, &valNonDominante);
        mat[posW][posH] = valNonDominante;
    }

    for (i = 0; i < altezza; i++){
        for(j = 0; j < larghezza; j++){
            fprintf(writing, "%d ", mat[i][j]);
        }
        fprintf(writing, "\n");
    }
    
    fclose(writing);
    fclose(reading);    
    return 0;
}


FILE *apri(char *mode, char *path){
    FILE *fpoint;
    fpoint = fopen(path, mode);
    return fpoint;
}