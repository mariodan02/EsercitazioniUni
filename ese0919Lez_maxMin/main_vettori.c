#include <stdlib.h>
#include <stdio.h>

void calcolo(int *, int *, int *);

int main(){
    int vett[10], max, min, i;
    for(i = 0; i < 10; i++){
        printf("Immetti il valore %d dell'array: ", i+1);
        scanf("%d", &vett[i]);
    }
    calcolo(vett, &max, &min);
    printf("* Il massimo è: %d;\n* Il minimo è: %d\n==================", max, min);
    return 0;
}

void calcolo(int vettore[], int * acciughina, int * minimo){
    int i;
    * acciughina = 0;
    * minimo = vettore[0];
    for(i = 0; i < 10; i++){
        if(vettore[i] > * acciughina) * acciughina = vettore[i];
        if(vettore[i] < * minimo) * minimo = vettore[i];
    }
}