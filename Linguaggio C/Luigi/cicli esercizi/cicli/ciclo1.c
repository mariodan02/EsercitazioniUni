#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int val, somma;
	somma=0;
	printf("inserisci il valore\n");
	scanf("%d",&val);
	while(val!=0){
		somma=somma+val;
		printf("inserisci il valore\n");
		scanf("%d",&val);
	}
	printf("valore della somma:%d", somma);
	return 0;
}
