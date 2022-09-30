//
// Created by alessio on 22/09/22.
//

#ifndef ESE0922_ESAMESTRUCT_EXAM_H
#define ESE0922_ESAMESTRUCT_EXAM_H
#define STRING_LIMIT 100

struct data{
    int giorno, mese, anno;
};
typedef struct data date;

struct esame{
    char nome[STRING_LIMIT + 1];
    int voto;
    date * dataSuperamento;
};
typedef struct esame exam;

void printLibretto(exam * esame, int count){
    /*
     La funzione printLibretto() consente di stampare il
     libretto, completo di tutti gli esami.
     */
    int i = 0;
    printf("========================= Riepilogo libretto =========================\n");
    for (i = 0; i < count; i++){
        printf("( %d )\n", count);
        printf("Esame: %s;\n", esame->nome);
        printf("Valutazione: %d;\n", esame->voto);
        printf("Data conseguimento: %d/%d/%d.\n", esame->dataSuperamento->giorno, esame->dataSuperamento->mese, esame->dataSuperamento->anno);
        printf("---\n");
    }
    esame = esame + count;
};

void insertExam(exam * esameStruct, int * count){
    /* la funzione insertExam() dovrebbe:
     * allocare la memoria necessaria per aggiungere l'esame;
     * scritturare i campi dell'esame
     Eventualmente:
     * stampare riepilogo trasact
    */
    esameStruct = malloc(sizeof(exam));
    printf("Inserisci il nome dell'esame: ");
    scanf("%s", &esameStruct->nome);
    printf("Inserisi il voto conseguito: ");
    scanf("%d", &esameStruct->voto);
    printf("Inserire data di conseguimento, formato GG MM AAAA: ");
    scanf("%d %d %d", &esameStruct->dataSuperamento->giorno, &esameStruct->dataSuperamento->mese, &esameStruct->dataSuperamento->anno);
    printf("\n\n\n========================= Riepilogo transazione: =========================\n");
    printf("Esame:            %s\n", esameStruct->nome);
    printf("Conseguito il:    %d/%d/%d\n", esameStruct->dataSuperamento->giorno, esameStruct->dataSuperamento->mese, esameStruct->dataSuperamento->anno);
    printf("Votazione:        %d\n", esameStruct->voto);
    * count++;
}

void deleteExam(exam * esame, int * count){
    /*
     Il compito della funzione deleteExam() è quello di liberare
     la memoria occupata dall'esame.
    */
    printLibretto(esame, *count);
    int offset;
    printf("Quale esame vuoi modificare?\nScelta: ");
    scanf("%d", &offset);
    esame = esame - offset;
    free((void *) esame);
    esame = esame + *count;
    count--;
};


void editExam(exam * esame, int count){
    /*
     La funzione editExam consente di cambiare alcuni parametri
     di un determinato esame.
     */
    int offset, choice;
    printLibretto(esame, count);
    printf("Quale esame vuoi modificare?\nScelta: ");
    scanf("%d", &offset);
    esame = esame - offset;
    printf("Cosa vuoi modificare?\n");
    printf("1) Nome;\n");
    printf("2) Valutazione;\n");
    printf("3) Data;\n");
    printf("4) Inizializza campi data e voto.\n");
    printf("Scelta: ");
    scanf("%d", &choice);
    if (choice == 1){
        printf("Inserisci nuovo nome: ");
        scanf("%s", esame->nome);
        printf("Modifica effettuata! Ritorno alla home...\n");
    }
    else if (choice == 2){
        printf("Immetti nuova valutazione: ");
        scanf("%d", esame->voto);
        printf("Modifica effettuata! Ritorno alla home...\n");
    }
    else if (choice == 3){
        printf("Immetti nuova data (formato GG MM AAAA): ");
        scanf("%d %d %d", esame->dataSuperamento->giorno, esame->dataSuperamento->mese, esame->dataSuperamento->anno);
        printf("Modifica effettuata! Ritorno alla home...\n");
    }
    else if (choice == 4){
        esame->voto = 0;
        esame->dataSuperamento->giorno = 0;
        esame->dataSuperamento->mese = 0;
        esame->dataSuperamento->anno = 0;
        printf("Modifica effettuata! Ritorno alla home...\n");
    }
    esame = esame + offset;
};


#endif //ESE0922_ESAMESTRUCT_EXAM_H
