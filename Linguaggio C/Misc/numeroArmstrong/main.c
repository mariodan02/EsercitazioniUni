/* Scrivere un programma che riceve un valore intero
in input da tastiera e verifichi se il numero è primo e
se è un numero di Armstrong.
• Numero di Armstrong: numeri per i quali la somma delle k cifre che li
costituiscono, ognuna elevata a k, equivale al numero di partenza.
Ad esempio: 153=1^{3}+5^{3}+3^{3}=1+125+27=153 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 100

void checkPrimo(int);
void checkArmstrong(int);

int main(){
    int value;
    printf("Immetti il valore: ");
    scanf("%d", &value);
    checkPrimo(value);
    checkArmstrong(value);
    return 0;
}

void checkPrimo(int valore){
    int i;
    // escludo lo zero
    if(valore == 0){
        printf("⚠ Il valore è zero.\n");
        return;
    }

    for (i = 2; i < valore; i++)
    {
        if(valore % i == 0) {
            printf("✗ Il numero non è primo.\n");
            return;
        }
    }
    printf("✔ Il numero è primo.\n");
    
}
void checkArmstrong(int valore){
    int numeroArray[100];
    int k = 0, indice = 0, a = 1, i, somma = 0, j, temp, potenza, cifre, breakpoint = 1;

    // escludo lo zero
    if(valore == 0){
        printf("⚠ Il valore è zero.\n");
        return;
    }
    
    // conto il numero delle cifre
    while(breakpoint != 0){
        breakpoint = valore / pow(10, indice);
        k++;
        indice++;
    }

    indice = 1;
    k--;

    // riempio la prima cifra
    for(i = k-1; i > 0; i--){
        a = valore % (int)(pow(10, i));
    }
    numeroArray[0] = a;

    // schematizzo il numero mediante un array
    for(i = 1; i < k; i++){
        potenza = pow(10, indice);
        a = valore / potenza;
        a = a % potenza;
        numeroArray[i] = a;
        indice++;
    }
    
    
    // effettuo la somma
    for(i = 0; i < k; i++) somma = somma + (int)(pow(numeroArray[i], k));

    // controllo se somma e numero coincidono; se vero -> value è numero di Arsmtrong
    if(valore == somma) printf("✔ Il valore immesso è un numero di Armstrong.\n");
    else printf("✗ Il valore immesso non è un numero di Armstrong.\n");
}
