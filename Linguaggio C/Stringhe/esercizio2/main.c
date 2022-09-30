/*
Scrivere un programma che, da una frase, rimuova gli spazi in input.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    char ch, stringaSpazi[100], stringaCompact[100];
    int i = 0, j = 0;
    printf("Immettere la stringa con gli spazi: ");
    while ((ch = getchar()) != '\n')
    {
        stringaSpazi[i] = ch;
        i++;
    }
    stringaSpazi[i] = '\0';
    i = 0;

    while (stringaSpazi[i] != '\0')
    {
        if(stringaSpazi[i] != ' '){
            stringaCompact[j] = stringaSpazi[i];
        j++;
        }
        i++;
    } 
    
    printf("%s \n", stringaCompact);
    return 0;
}