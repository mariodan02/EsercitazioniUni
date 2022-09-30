//
// Created by alessio on 27/09/22.
//

#include "math.h"

#ifndef ESE0927_BACKEND_H
#define ESE0927_BACKEND_H

struct vec{
    int x, y;
};
typedef struct vec vector2d;

vector2d * init (void){
    int a, b;
    vector2d * vecPtr;
    vecPtr = malloc(sizeof(vector2d));
    printf("Inserisci le componenti del vettore, formato x y: ");
    scanf("%d %d", &a, &b);
    vecPtr -> x = a;
    vecPtr -> y = b;
    return vecPtr;
}

void toString(vector2d * v){
    printf("* La componente x del vettore è: %d;\n", v -> x);
    printf("* La componente y del vettore è: %d.\n", v -> y);
}

int equal(vector2d * v1, vector2d * v2){
    if((v1 -> x == v2 -> x) && (v1 -> y == v2 -> y)) return 1;
    else return 0;
}

double norm(vector2d* v){
// // norma = sqrt(x²+y²)
    double norm;
    norm = sqrt((pow((double) v -> x, 2) + pow((double)v -> y, 2)));
    return norm;
}

int dotProduct(vector2d* v1, vector2d* v2){
    // x1x2+y1y2;
    int scalProd;
    scalProd = ((v1 -> x * v2 -> x) + (v1 -> y * v2 -> y));
    return scalProd;
}

void destroy(vector2d* v){
    free(v);
}

#endif //ESE0927_BACKEND_H
