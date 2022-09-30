#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int vett[SIZE];
	int i, crescente, decrescente, N;
	crescente=0;
	decrescente=0;
	printf("inserisci il numero di valori: ");
	scanf("%d",&N);
	while(N>SIZE){
		printf("valore troppo grande!\n");
		printf("inserisci il numero di valori: ");
	    scanf("%d",&N);
	}
	for(i=0;i<N;i++){
		printf("inserisci valore nella sequenza\n");
		scanf("%d", &vett[i]);
	}
	for(i=0;i<N;i++){
		if(vett[i]<vett[i+1]){
			crescente=1;
		}else if(vett[i]>vett[i+1]){
			decrescente=1;
		}
	}
	if(crescente==1 && decrescente==0){
		printf("la serie di valori e crescente");
	}else if(crescente==0 && decrescente==1){
		printf("la serie di valori e decrescente");
	}else if(crescente==1 && decrescente==1){
		printf("la serie non e ne crescente ne decrescente");
	}
	return 0;
}
