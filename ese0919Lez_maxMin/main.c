#include <stdio.h>
#include <stdlib.h>

void calcolo(int *, int *, int, int);

int main() {
    int a, b, min, max;
    printf("Inserisci due valori, separati da uno spazio: ");
    scanf("%d %d", &a, &b);
    calcolo(&min, &max, a, b);
    printf("* Il max è: %d;\n* Il min è: %d.\n=======================", max, min);
    return 0;
}

void calcolo(int * min, int * max, int aValue, int bValue){
    if(aValue > bValue){
        * max = aValue;
        * min = bValue;
    }
    else{
        * max = bValue;
        * min = aValue;
    }
}