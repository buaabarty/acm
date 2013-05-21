n,t=map(int, raw_input().split())
str=raw_input()
for i in range(0, t) :
	tmp = str
	for j in range(0, n-1) :
		if str[j]=='B' and str[j+1]=='G' :
			tmp[j] = 'G'
			tmp[j+1] = 'B'
	str = tmp
print str