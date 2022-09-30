#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main() {
    int a, b;
    printf("Inserisci i due valori a e b, separati da uno spazio: ");
    scanf("%d %d", &a, &b);
    printf("Eseguo lo swap...\n");
    swap(&a, &b);
    printf("=================\n");
    printf("I valori swappati sono: %d %d", a, b);
    return 0;
}

void swap(int * valueA, int * valueB){
    int tmp = *valueA;
    *valueA = *valueB;
    *valueB = tmp;
}