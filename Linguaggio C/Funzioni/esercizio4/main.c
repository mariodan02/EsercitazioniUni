/*
Stampare interi di alcune lettere e il carattere spazio.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    char ch;
    printf("Immettere carattere: ");
    scanf("%c", &ch);
    printf("L'equivalente intero con spazio è: '%d '.\n", ch);
    return 0;
}