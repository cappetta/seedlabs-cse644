import random
s = "abcdefghijklmnopqrstuvwxyz"
list = random.sample(s, len(s)) 
it = ''.join(list)
print it
