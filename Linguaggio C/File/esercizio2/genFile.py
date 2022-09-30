import string    
import random
from random import randint as seed  
S = seed(0, 999)  
ran = ''.join(random.choices(string.ascii_uppercase + string.digits, k = S))
f = open("ciao.txt", 'w')
f.write(str(ran))    
f.close()