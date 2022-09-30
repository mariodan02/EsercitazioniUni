/*
Scrivere un programma che, dati nome e cognome, stampi il nominativo completo.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    char nome[50], cognome[50], ch;
    printf("Immetti il nome: ");
    // fare attenzione all'evalutazione della condizione: porre assegnazione ch = getchar() tra parentesi
    // si corre il rischio di non eseguire tale evalutazione.

    // inoltre, si preferisca getchar() a scanf("%s", stringa) per raccogliere anche spazi
    while((ch = getchar()) != '\n'){
        nome[i] = ch;
        i++;
    }
    nome[i] = '\0';
    i = 0;
    printf("Immetti il cognome: ");
    while((ch = getchar()) != '\n'){
        cognome[i] = ch;
        i++;
    }
    cognome[i] = '\0';

    // notare che la printf col placeholder %s non richiede la dimensione della collezione dei caratteri e/o cicli.
    printf("Nominativo: %s %s.\n", nome, cognome);
    return 0;
}