/*
Scrivere una funzione che restituisce il numero degli alberghi che hanno il servizio richiesto e il numero di stelle pari o superiore

Posta (****), 2 garage giardino
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 30

int main(){
    int n; // numero di stelle
    char s[SIZE]; // servizio
    int numServizi, i, count = 0, stelleNum;
    char stelleRead[SIZE+1], nomeHotel[SIZE+1], sRead[SIZE+1]; 
    char path[]="list.dat", ch;
    FILE *fp;

    printf("Immetti numero stelle e nome servizio: ");
    scanf("%d %s", &n, s);
    fp = fopen(path, "r");
    if (fp == NULL) exit(1);
    
    while ((ch = fgetc(fp)) != EOF)
    {
        fscanf(fp, "%s", nomeHotel);        
        fscanf(fp, "%s", stelleRead);
        stelleNum = strlen(stelleRead) - 3;
        if (stelleNum > n) {
            fscanf(fp, "%d", &numServizi);
            for (i = 0; i < numServizi; i++)
            {
                fscanf(fp, "%s", sRead);
                if (strcmp(s, sRead) == 0)
                {
                    count++;
                }
                
            }
            
        }
    }
    
    fclose(fp);
    printf("Il numero di alberghi con le caratteristiche richieste è %d.\n", count);
    return 0;
}
