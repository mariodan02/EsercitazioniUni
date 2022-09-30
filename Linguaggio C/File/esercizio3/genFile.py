from random import randint as seed, random

path = 'input.txt'

f = open(path, 'w')
for i in range(10):
    f.write(str(seed(-567890876, 65678908)))
    f.write('\n')

f.close()