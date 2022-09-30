#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);

int main() {
    int a, b;
    int * pointA = &a, * pointB = &b;
    printf("Inserisci i due valori a e b, separati da uno spazio: ");
    scanf("%d %d", &a, &b);
    printf("Eseguo lo swap...\n");
    swap(pointA, pointB);
    printf("=================\n");
    printf("I valori swappati sono: %d %d", *pointA, *pointB);
    return 0;
}

void swap(int * valueA, int * valueB){
    int tmp = *valueA;
    *valueA = *valueB;
    *valueB = tmp;
}