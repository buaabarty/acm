r=0;g=0;b=0
n = map(int, raw_input().split())[0]
str = raw_input()
for i in range(0, n) : 
	if (str[i] == 'R') :
		r = max(r, max(g, b) + 1)
	if (str[i] == 'G') :
		g = max(g, max(r, b) + 1)
	if (str[i] == 'B') :
		b = max(b, max(r, g) + 1)
print n - max(max(r, g), b)