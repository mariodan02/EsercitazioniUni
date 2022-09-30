# Stringhe
## Esercizio 1
*Con questo programma si notano alcune best-practices sulla gestione basilare delle stringhe.*

Svolgimento:``30-11-2021``.

### Dai commenti:
* Con l'istruzione ``getchar()`` si raccolgono in input **tutti** i caratteri, ivi inclusi gli spazi; tale precisazione è necessaria dal momento in cui l'espressione ``scanf("%s", <nome della stringa>)`` cessa di prendere in input al raggiungimento del primo spazio;
* In più, l'utilizzo dell'espressione ``ch = getchar()`` come termine di evalutazione (``while(ch = getchar())``) vada posta tra parentesi, in quanto membro unico dell'evalutazione:
    * evalutare con la forma ``while(ch = getchar() != '<carattere>')`` comporta la mancata evalutazione dell'espressione;
    * la forma corretta è, dunque: ``while((ch = getchar()) != '<carattere>')``;
* Con l'evalutazione di caratteri costanti, si usi il singolo apice ( ``'`` ) anziché il doppio apice ( ``"`` );
* Utilizzando il placeholder ``%s``, non è neccessario:
    1. Indicare la dimensione della stringa, cioè della collezione di caratteri;
    2. Non c'è la necessità di usare alcun ciclo per performare l'attività di stampa.