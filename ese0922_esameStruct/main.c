#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exam.h"
#define STRING_LIMIT 100

int main() {
    exam * esame;
    date * data;
    int a = 1, count = 0;
    while(a != 0){
        printf("Cosa desideri fare?\nPuoi:\n");

        printf("0) Per uscire;\n");
        printf("1) Inserire un esame;\n");
        printf("2) Cancellare un esame;\n");
        printf("3) Modificare un esame;\n");
        printf("4) Stampare il libretto.\n Selezione: ");

        scanf("%d", &a);

        if (a == 1) insertExam(esame, &count);
        else if (a == 2) deleteExam(esame, &count);
        else if (a == 3) editExam(esame, count);
        else if (a == 4) printLibretto(esame, count);
        else if (a == 0) exit(EXIT_SUCCESS);
    }
    return 0;
}