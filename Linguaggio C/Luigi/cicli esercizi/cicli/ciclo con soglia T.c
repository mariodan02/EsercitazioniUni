#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int val,somma, T;
	somma=0;
	printf("inserisci il valore soglia: ");
	scanf("%d",&T);
	printf("inserisci i valori della sequenza: ");
	scanf("%d",&val);
	somma=somma+val;
	while(somma<T){
	    printf("inserisci i valori della sequenza: ");
	    scanf("%d",&val);
	    somma=somma+val;
	    
	}
	return 0;
}
