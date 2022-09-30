#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int prodotto, sommacfu;
	int n_esami, i;
	int voto, cfu;
	float mediapesata;
	printf("inserisci il numero di voti di cui vuoi calcolare la media: ");
	scanf("%d", &n_esami);
	sommacfu=0;
	prodotto=0;
	for(i=0;i<n_esami;i++){
		printf("inserisci voto esame: ");
		scanf("%d", &voto);
		while(voto>31 || voto< 18){
			printf("voto non valido!\n");
			printf("inserisci voto esame: ");
		    scanf("%d", &voto);
		}
		printf("inserisci i cfu relativi al voto: ");
		scanf("%d", &cfu);
		prodotto= prodotto+(voto*cfu);
		sommacfu=sommacfu+cfu;
	}
	mediapesata=(float)prodotto/sommacfu;
	printf("media pesata: %f", mediapesata);
	return 0;
}
