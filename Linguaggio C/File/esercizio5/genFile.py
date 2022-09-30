from os import close
from random import randint as seed

def trascrittore(numeroEstratto):
    if numeroEstratto == 0:
        numeroEstratto = 'zero'
    elif numeroEstratto == 1:
        numeroEstratto = 'uno'
    elif numeroEstratto == 2:
        numeroEstratto = 'due'
    elif numeroEstratto == 3:
        numeroEstratto = 'tre'
    elif numeroEstratto == 4:
        numeroEstratto = 'quattro'
    elif numeroEstratto == 5:
        numeroEstratto = 'cinque'
    elif numeroEstratto == 6:
        numeroEstratto = 'sei'
    elif numeroEstratto == 7:
        numeroEstratto = 'sette'
    elif numeroEstratto == 8:
        numeroEstratto = 'otto'
    elif numeroEstratto == 9:
        numeroEstratto = 'nove'
    return numeroEstratto

f = open("dati.txt", 'w')
ripetizioniSullaColonna = seed(0, 10)

for i in range(ripetizioniSullaColonna):
    ripetizioniSullaRiga = seed(0, 10)
    for j in range(ripetizioniSullaRiga):
        numeroEstratto = seed(0, 9)
        numeroEstratto = trascrittore(numeroEstratto)
        bind = str(numeroEstratto) + ' '
        f.write(bind)
    f.write("stop")
    f.write('\n')

f.close()