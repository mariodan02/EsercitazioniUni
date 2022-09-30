# Funzioni
## Esercizio 1
Dall'esercizio 1, si può notare una cosa abbastanza importante per comprendere la differenza tra C89 e C99:

> In C89 il tipo dati di ritorno di default, se non diversamente specificato, viene visto come ``int``.
In C99, invece, tale assunzione viene soppressa.

Questo porta il compilatore a puntare un certo warning, per le dichiarazioni delle funzioni come segue:

    main.c:31:8: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
    
    double calcoloBinomiale(n, k){
    
Tale avviso viene ripetuto anche per la variabile ``k``.

Quindi, con la specifica C89, la _best practice_ per una dichiarazione della funzione dev'essere del tipo:

    double calcoloBinomiale(int n, int k){

in modo tale da consentire il passaggio degli argomenti col corretto ``datatype``(questo non è strettamente necessario quando, per argomento, si ha una variabile di tipo ``int``, ma diviene obbligatorio quando, per argomento si ha una variabile di tipo ``double``, ``float``, ``char``, altrimenti tale argomento viene sempre passato come ``int``).


> N.B.: È essenziale notare come un _warning_ **NON È** un errore di compilazione, in quanto il programma viene correttamente compilato ed eseguito.

## Esercizio 2

*Esercizio in copia come ``esercizio1`` in ``Array``.*

L'osservazione più importante nell'esercizio è la seguente:

    // chiamata della funzione
    b[i] = calcoloQuadrato(a[i]);
    ...
    // dichiarazione della funzione
    int calcoloQuadrato(int x){
        ...
    }

Si può notare che, il valore ``a[i]`` passato come paramentro alla funzione in fase di chiamata, viene poi "rinominato" ``x`` all'interno della funzione stessa. Dunque, per riferirci al valore ``a[i]`` una volta all'interno della funzione ``calcoloQuadrato``, bisognerà adoperare ``x``.

> Va specificato che la variabile ``x`` è a visibilità locale, vale cioè solamente per lo scope (funzione) ``calcoloQuadrato``. Qualora si voglia, si può utilizzare un'altra variabile, chiamata ancora ``x``, all'interno della funzione ``calcoloCubo``, senza dimenticare che, tale variabile è **diversa** dalla ``x`` in ``calcoloQuadrato``, cioè con valori diversi, aggiornati in modi e tempoi diversi, ed in più visibili localmente solo per i rispettivi scopes. Utilizzare lo stesso nome di variabile, è una prassi che, di per sé, non porta ad errori di compilazione ed esecuzioni; ad ogni modo, è una pratica sconsigliata, in quanto può facilemente indurre all'errore.
