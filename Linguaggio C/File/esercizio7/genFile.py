from random import randint as seed

valoreDominanteStr = str(seed(0, 9))
altezzaStr = str(seed(0, 100))
larghezzaStr = str(seed(0, 100))

larghezza = int(larghezzaStr)
altezza = int(altezzaStr)

check = int(((larghezza * altezza)/2) - 1)

f = open('lettura.txt', 'w')
f.write(altezzaStr)
f.write(' ')
f.write(larghezzaStr)
f.write(' ')
f.write(valoreDominanteStr)
f.write('\n')

for i in range (check):
    f.write(str(seed(0, altezza)))
    f.write(' ')
    f.write(str(seed(0, larghezza)))
    f.write(' ')
    f.write(str(seed(0, 9)))
    f.write('\n')

f.close
