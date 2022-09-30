/*
scrivere un programma che dato in input un numero N, stampi il suo corrispettivo triangolo di floyd composto da N #righe e che stampi le N righe di quest'ultimo.
si noti che il triangolo di floyd è costituito dalla seguente struttura:


n=6

1
2 3
4 5 6
7 8 9 10 
11 12 13 14 15
16 17 18 19 20 21 
*/ 

#include <stdio.h>
#include <stdlib.h>


int main(){
    int N, i = 1, numeroInStampa = 1, numeroPerRigaPrecedente = 1, valoriStampati = 0;
    printf("Inserisci il numero di righe del triangolo di Floyd: ");
    scanf("%d", &N);

    while (i <= N)
    {
        while (valoriStampati < numeroPerRigaPrecedente)
        {
            printf("%-4d", numeroInStampa);
            valoriStampati++;
            numeroInStampa++;
        }
        numeroPerRigaPrecedente++;
        valoriStampati = 0;
        i++;
        printf("\n");
    }
    
    system("PAUSE");
    return 0;
}