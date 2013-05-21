#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#define N 1000010
using namespace std;
int next[N], dat[N];
char s[N], t[N], n, m;
void getnext()
{
    next[0] = -1;
    for (int j = 0, k = -1; j < m;)
        if ((k == -1) || (t[j] == t[k])) next[++j] = ++k;
        else k = next[k];
}
char temp[N];
char* solve(char *s, char *t)
{
    n = strlen(s);
    m = strlen(t);
    getnext();
    int i = 0, j = 0, res = 0;
    for ( ; i < n; ++i)
    {
        while ((j >= 0) && (s[i] != t[j])) j = next[j];
        if ((j == -1) || (s[i] == t[j])) ++j;
        if (i == n - 1) {res = j; break; }
        if (j == m) j = next[j];
    }
    strcpy(temp, s);
    for (int i = n; i < n + m - res; ++i)
        temp[i] = t[i - n + res];
    temp[n + m - res] = '\0';
    return temp;
}
char a[N], b[N];
int main()
{
    while (~scanf("%s%s", s, t))
    {
        strcpy(a, solve(s, t));
        strcpy(b, solve(t, s));
        int la = strlen(a), lb = strlen(b);
        if (la != lb)
        {
            if (la < lb) puts(a);
            else puts(b);
        }
        else if (strcmp(a, b) < 0) puts(a);
        else puts(b);
    }
    return 0;
}
