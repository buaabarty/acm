import math

f = 5 + 2 * math.sqrt(6)
a = f

for i in range(20):
    print int(math.pow(f, 1 + pow(2, i)))
