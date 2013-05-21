#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
#define N 75010
using namespace std;
int Next[N];
char s[N], t[N];
int slen, tlen;
void getNext()
{
	int j, k;
	j = 0; k = -1; Next[0] = -1;
	while(j < tlen)
		if(k == -1 || t[j] == t[k])
			Next[++j] = ++k;
		else
			k = Next[k];
}
/*
返回模式串t在主串S中首次出现的位置
*/
int dat[N];
bool calc()
{
	int i = 0, j = 0;
	getNext();
	while(i < slen && j < tlen)
	{
	    if (j == -1) return false;
		if(j == -1 || s[i] == t[j])
		{
		    dat[i] = j;
			i++; j++;
			if (j == tlen) j = Next[j];
		}
		else
			j = Next[j];
	}
	return true;
}
bool f[N];
int main()
{
    while (~scanf("%s%s", &t, &s))
    {
        memset(dat, 0, sizeof(dat));
        slen = strlen(s);
        tlen = strlen(t);
        if (calc())
        {
            printf("No\n");
            memset(f, false, sizeof(f));
            bool flag = false;
            int j = slen - 1, res[N], resl = 0;
            while (j > 0)
            {
                j = j - dat[j];
                if (j > 1) f[j--] = true;
            }
            dat[slen] = INT_MAX;
            for (int i = 0; i < slen; ++i)
            {
                if (f[i]) printf(" ");
                printf("%c", s[i]);

            }
            printf("\n");
        }
        else printf("Yes\n");
    }
    return 0;
}
