/*
 * Completare il programma C che, dato un file di testo contente una sequenza di stringhe,
 * determini quante stringhe, quanti caratteri consonanti, vocali, maiuscoli e minuscoli 
 * appaiono nel file.

Esempio di un file di input:
 
vi troverete Bene col fruTTo della Vita se ne eviterete  ogni abuso nella Vita

Un esempio di esecuzione e':

Digitare il nome del file di input: in.txt
Digitare il nome del file di output: out.txt
 
Dopo l'esecuzione del programma, il file out.txt conterrà:

Occorrenze delle vocali: 30
Occorrenze delle consonanti: 34
Occorrenze delle maiuscole: 5
Occorrenze delle minuscole: 59
Numero stringhe: 14
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define NCAR 64

FILE *ApriFile(char mode[]);
void Statistics(char stringa[], int *c, int *v, int *m, int *M);
void ScriviRisultato(FILE *fpout, int c, int v, int m, int M, int n_stringhe);

int main(int argc, char** argv) {
    FILE *fp;
    int n_occ = 0, voc = 0, cons = 0, min = 0, Mai = 0;
    int v, c, m, M;
    char str[NCAR];

    fp = ApriFile("r");
    while (fscanf(fp, "%s", str) != EOF) {
        n_occ++;
        Statistics(str, &v, &c, &m, &M);
        voc += v;
        cons += c;
        min += m;
        Mai += M;

    }


    fclose(fp);

    fp = ApriFile("w");

    ScriviRisultato(fp, voc, cons, min, Mai, n_occ);
    fclose(fp);

    return (EXIT_SUCCESS);
}

/*
 La funzione ApriFile apre il file il cui nome e' fornito in input
 dall'utente nella modalità specificata dal parametro formale mode
 e ritorna il puntatore al file
 */
FILE *ApriFile(char mode[]) {
    FILE *fpin;
    char PATH[NCAR + 1];
    printf("Inserisci nome file: ");
    scanf("%s", PATH);
    fpin = fopen(PATH, mode);
    if (fpin == NULL)
    {
        printf("Errore nell'apertura del file. Chiudo il programma.\n");
        exit(EXIT_FAILURE);
    }
    return fpin;
}

/*
 * La funzione statistics prende in input una stringa (letta dal file) e restituisce nei parametri passati alla funzione, 
 * il numero di caratteri consonanti, vocali, minuscoli e maiuscoli  che appaiono nel file.
 */
void Statistics(char stringa[], int *c, int *v, int *m, int *M) {
    int i = 0;
    *c = 0;
    *v = 0;
    *m = 0;
    *M = 0;
    while(stringa[i] != '\0'){
        if(stringa[i] >= 65 && stringa[i] <= 90) {
            *M = *M + 1;
            if(stringa[i] == 65 || stringa[i] == 69 || stringa[i] == 73 || stringa[i] == 79 || stringa[i]== 85) *v = *v + 1;
            else *c = *c + 1;
        }
        else if(stringa[i] >= 97 && stringa[i] <= 122) {
            *m = *m + 1;
            if(stringa[i] == 97 || stringa[i] == 101 || stringa[i] == 105 || stringa[i]== 111 || stringa[i]==117) *v = *v + 1;
            else *c = *c + 1;
        }
        i++;
    }
}

/*
 La funzione ScriviRisultato scrive su file l'ouput come descritto nella traccia.
 * Ha i parametri: nome del file su cui salvare il risultato, tutti i dati calcolati nella funzione precedente:  
 * il numero di caratteri consonanti, il numero delle vocali, il numero di caratteri maiuscoli e minuscoli che appaiono nel file 
 * e infine il numero totale di stringhe trovate nel file.
 */
void ScriviRisultato(FILE *fpout, int c, int v, int m, int M, int n_stringhe) {
    fprintf(fpout, "Occorrenze delle vocali: %d;\n", v);
    fprintf(fpout, "Occorrenze delle consanti: %d;\n", c);
    fprintf(fpout, "Occorrenze delle maiuscole: %d;\n", M);
    fprintf(fpout, "Occorrenze delle minuscole: %d;\n", m);
    fprintf(fpout, "Stringhe lette: %d.", n_stringhe);
}