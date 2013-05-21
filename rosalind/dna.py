str = raw_input()
a = 0; c = 0; g = 0; t = 0
for i in range(0, len(str)) :
	if str[i] == 'A' :
		a = a + 1
	if str[i] == 'T' :
		t = t + 1
	if str[i] == 'C' :
		c = c + 1
	if str[i] == 'G' :
		g = g + 1
print a,c,g,t