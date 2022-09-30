/*
Denire la struttura Vector2D che descrive un vettore bidimensionale.
Scrivere quindi il corpo delle seguenti funzioni:
Vector2D *init(void); alloca dinamicamente lo spazio per la struttura, richiede
all’utente il valore dei campi e restituisce la struttura.
void toString(Vector2D* v); stampa a video il vettore
int equal(Vector2D* v1, Vector2D* v2); determina se due vettori sono uguali
double norm(Vector2D* v); calcola la norma del vettore
int dotProduct(Vector2D* v1, Vector2D* v2); calcola il prodotto scalare tra
due vettori
void destroy(Vector2D* v); libera lo spazio di memoria allocato dalla struttura
Si supponga che i campi della struttura siano interi
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "backend.h"

int main() {
    int check, prodottoScalare;
    vector2d * v1, * v2;
    v1 = init();
    v2 = init();
    printf("==========\n");
    printf("Stampo i due vettori:\n");
    printf("Vettore 1:\n");
    toString(v1);
    printf("\nVettore 2:\n");
    toString(v2);
    printf("==========\n");
    printf("I vettori sono uguali? ");
    check = equal(v1, v2);
    if(check == 1) printf("Sì\n");
    else printf("No\n");
    printf("==========\n");
    printf("La norma del vettore 1 è %f.\n", norm(v1));
    printf("La norma del vettore 2 è %f.\n", norm(v2));
    printf("==========\n");
    printf("Il prodotto scalare dei due vettori è: %d.\n", dotProduct(v1, v2));
    printf("==========\n");
    printf("Libero la memoria occupata dai due vettori.\n");
    destroy(v1);
    destroy(v2);
    printf("Missione compiuta!\n");
    return 0;
}
