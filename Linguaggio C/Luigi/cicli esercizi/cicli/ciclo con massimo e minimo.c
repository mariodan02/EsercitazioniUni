#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int val, min,max;
	printf("inserisci il valore\n");
	scanf("%d",&val);
	min=val;
	max=val;
	while(val>=0){
		if(val>max){
			max=val;
		}else if(val<min){
			min=val;
		}
		printf("inserisci il valore\n");
		scanf("%d",&val);
	}
	printf( "minimo: %d\n", min);
	printf("massimo: %d", max);
	return 0;
}
