#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 1000010
using namespace std;
int next[MAXN];
char s[MAXN], t[MAXN];
int slen, tlen;

void getNext()
{
	int j, k;
	j = 0; k = -1; next[0] = -1;
	while(j < tlen)
		if(k == -1 || t[j] == t[k])
			next[++j] = ++k;
		else
			k = next[k];
}
/*
返回模式串t在主串S中首次出现的位置
*/
int KMP_Index()
{
	int i = 0, j = 0;
	getNext();

	while(i < slen && j < tlen)
	{
		if(j == -1 || s[i] == t[j])
		{
			i++; j++;
		}
		else
			j = next[j];
	}
	if(j == tlen)
		return i - tlen;
	else
		return -1;
}
/*
返回模式串在主串s中出现的次数
*/
int KMP_Count()
{
	int ans = 0;
	int i, j = 0;

	if(slen == 1 && tlen == 1)
	{
		if(s[0] == t[0])
			return 1;
		else
			return 0;
	}
	getNext();
	for(i = 0; i < slen; i++)
	{
		while(j > 0 && s[i] != t[j])
			j = next[j];
		if(s[i] == t[j])
			j++;
		if(j == tlen)
		{
			ans++;
			j = next[j];
		}
	}
	return ans;
}
int main()
{
    while (gets(t) != NULL)
    {
        if (t[0] == '.') break;
        tlen = strlen(t);
        getNext();
        int res = 0;
        if (tlen % (tlen - next[tlen]) == 0) printf("%d\n", tlen / (tlen - next[tlen]));
        else printf("1\n");
    }
    return 0;
}
