# Array
## Esercizio 1

*Esercizio in copia come ``esercizio2`` in ``Funzioni``.*

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