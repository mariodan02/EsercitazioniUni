//acquisire da tastiera due parole e verificare se la seconda parola equivale alla prima letta al contrario//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 1000

void controllo(char *, char *);

int main(){
    char parola1[SIZE + 1], parola2[SIZE + 1];

    printf("Immettere la prima parola: ");
    scanf("%s", parola1);
    printf("Immettere la seconda parola: ");
    scanf("%s", parola2);
    controllo(parola1, parola2);
    return 0;
}

void controllo(char parola1[], char parola2[]){
    int i, lunghezza1, lunghezza2, j;
    lunghezza1 = strlen(parola1);
    lunghezza2 = strlen(parola2);
    j = lunghezza2 - 1;
    
    if (lunghezza1 != lunghezza2){    
        printf("Le due stringhe non sono uguali.\n");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < lunghezza1; i++){
        if (parola1[i] != parola2[j])
        {
            printf("Le due stringhe non sono uguali.\n");
            exit(EXIT_FAILURE);
        }  
        j--;
    }
    printf("Le due stringhe sono uguali.\n");
}