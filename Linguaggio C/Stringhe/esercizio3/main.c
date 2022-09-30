/*
Acquisire due parole, verificare se la seconda è la prima al contrario
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    char parola1[20], parola2[20];
    int i = 0; j = 0;
    printf("Immetti la prima parola: ");
    scanf("%s", parola1);

    printf("Immetti la seconda parola: ");
    scanf("%s", parola2);

    while(parola2[j] != '\0')
    {
        j++;
    }
    

    while (parola1[i] != '\0')
    {
        if (parola1[i] == parola2[j]){
            i++;
            j++;
        } else {
            printf("Le due stringhe non sono l'una l'inversa dell'altra.'n");
            break;
        }        
    printf("Le due stringhe sono l'una l'inverso dell'altra.\n");
    }
    

    return 0;
}