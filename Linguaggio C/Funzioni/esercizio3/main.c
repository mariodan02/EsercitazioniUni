#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 2

float cambioUSDtoEUR(float, float, float);
float cambioEURtoUSD(float, float, float);

int main(){
    float tassoEUR = 0.88, tassoUSD = 1.13; //USD to EUR, EUR to USD
    float importoDaConvertire, importoConvertito;
    char ch[SIZE+1] = " ";
    printf("Immetti importo da convertire: ");
    scanf("%f", &importoDaConvertire);
    while ((strcmp(ch, "$") != 0 && (strcmp(ch, "€")) != 0))
    {   
        printf("Immetti:\n* € per il cambio da USD a EUR;\n* $ per il cambio da EUR a USD.\nScelta: ");
        scanf("%s", ch);
        if(strcmp(ch, "€") == 0){
            importoConvertito = cambioUSDtoEUR(importoDaConvertire, tassoUSD, tassoEUR);
            printf("L'importo convertito è: %.2f€.\n", importoConvertito);
        } else if (strcmp(ch, "$") == 0){
            importoConvertito = cambioEURtoUSD(importoDaConvertire, tassoEUR, tassoUSD);
            printf("L'importo convertito è: %.2f$.\n", importoConvertito);
        }
        return 0;
    }
}

// tasso EUR : tasso USD = x EUR : y USD

float cambioUSDtoEUR(float importo, float tassoUSD, float tassoEUR){
    float finale;
    finale = importo * tassoEUR;
    return finale;
}

float cambioEURtoUSD(float importo, float tassoEUR, float tassoUSD){
    float finale;
    finale = importo * tassoUSD;
    return finale;
}