#include <stdio.h>
#include <stdlib.h>

int main() {
    int dim, i;
    int * point;
    printf("Inserisci dimensione dell'array: ");
    scanf("%d", &dim);
    point = (int *) malloc(dim * sizeof(int));
    if (point == NULL) exit(EXIT_FAILURE);
    printf("Riempi l'array\n");
    for(i = 0; i < dim; i++) {
        printf("* inserisci il %d-esimo elemento: ", i+1);
        scanf("%d", point+i);
    }
    printf("=============\n");
    printf("L'array inserito: ");
    for(i = 0; i < dim; i++) printf("%d ", * (point + i));
    free((void *) point);
    return 0;
}
