# EsercizioPepi

Rapida panoramica sulle best practices da applicare, in realzione al sorgente già scritto.

N.b.: il sorgente di partenza è ``esePepi.C``, mentre la riscrittura è in ``main.C``.


## Prototipi delle funzioni
Benché i prototipi siano stati creati in modo formalmente corretto, concettualmente non tutti sono corretti.

Alcune procedure, specie quelle che modificano le funzioni, non ritornano nulla, nessun tipo di valore. Sarebbe dunque opportuno implementarle con un tipo ``void``, non avendo valore di ritorno (su array e matrici, passati come parametri, operi direttamente). Inoltre, puoi ritornare un solo valore per volta, non un array intero.

Quindi, nel caso in cui vada calcolata la traccia o la dimensione, è okay prototipare con tipo ``int``; ma, calcolando la somma, questa resterà scritturata in una matrice che non potrai ritornare, e dovrai prototipare con tipo ``void``.

Attenzione anche alla dichiarazione/inizializzazione delle funzioni: ti ricordo che il tipo di funzione dev'essere sempre esplicitato. Se nel prototipo hai ``void funzione();``, anche la dichiarazione sarà del tipo ``void funzione(){// codice all'interno};``.

## Funzione ``creaMat()``
Osservazione: *dal momento in cui ma matrice è quadrata, perché chiedere due valori per le righe e per le colonne?*

In un certo senso, la traccia è auto - esemplificativa; sebbene non venga richiesto esplicitamente di lavorare su una matrice quadrata, lo si ricava dal calcolo della traccia, in quanto è un'operazione che, nel footer, viene riferita ad una matrice quadrata.

A questo punto, basta semplicemente chiedere un unico valore in input, che sarà impiegato sia come numero di righe, che come numero di colonne (CFR: *definizione di matrice quadrata*.)

## Funzione ``calcolaTraccia()``
Osservando la schematizzazione grafica di una matrice:

![matQ](assets/matQ.svg)

La diagonale principale è quella linea immaginaria che congiunge gli elementi 3, 5, 1.

Osserviamo la posizione di questi elementi. Con indice per le righe ``i`` e indice per le colonne ``j``, in ``i = 0`` e ``j = 0`` abbiamo il 3. Il 5, sarà in posizione ``1; 1``; l'1 sarà in posizone ``2; 2``.

Si nota, quindi, che gli elementi della diagonale principale hanno indice di riga e colonna coincidenti. Quindi, si può utilizzare un solo ciclo ``for``, utilizzando un indice soltanto, sia per la riga, che per la colonna:

    // elementi diagonale princ.:
    for(i = 0; i < dimensioneMatrice; i++){
        matrice[i][i];
    }

La traccia corrisponderà, dunque, alla somma degli elementi in posizione ``i; i-esima``, dino all'ultima riga della matrice:

    // traccia:
    int traccia = 0;
    for(i = 0; i < dimensioneMatrice; i++){
        traccia += matrice[i][i];
    }


## Funzione ``stampaSomma()`` & ``stampaProdotto()``
Citando una risposta della prof. ssa De Maio:
> Le ricordo che le funzioni ci danno il vantaggio di ridurre il codice (una funzione può essere scritta una sola volta ed usata tante volte) invocando la stessa con parametri diversi per fare cose diverse. 

Dunque, perché avere due funzioni che, concettualmente, fanno la stessa cosa, quando puoi avere un'unica funzione e riutilizzarla più volte?

### Side notes
Volevo, infine, ricordarti due cose: 
- quando dichiari una costante, la best practice sarebbe di dichiarla con un nome ``ALLUPPERCASE``, cioè tutto maiuscolo:
    
        #define NOMECOSTANTE <value>

- la best practice per il C prevede la nomenclatura di variabili e funzioni utilizzando lo ``snake_casing``, in cui le singole parole vengono divise mediante il carattere ``underscore`` ('``_``'):
        
        void questa_è_una_procedura();
    In taluni casi, si utilizza anche il ``camelCasing``, in cui l'iniziale di ciascuna parola è maiuscola (CFR: ``main.c``).