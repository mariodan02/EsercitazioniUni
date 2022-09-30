#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int somma, val, min,max, n_val, i;
	float media;
	somma=0,
	printf("inserisci iol numero di valori: ");
	scanf("%d",&n_val);
	printf("inserisci il valore: ");
	scanf("%d",&val);
	min=val;
	max=val;
	i=0;
	while(i<n_val){
		somma=somma+val;
		if(val<min){
			min=val;
		}else if(val>max){
			max=val;
		}
	    printf("inserisci il valore: ");
	    scanf("%d",&val);
	    i++;
	}
	media=(float)somma/n_val;
	printf("media: %.2f\n", media);
	printf("massimo: %d\n", max);
	printf("minimo: %d", min);
	return 0;
}
