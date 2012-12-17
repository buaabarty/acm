#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[5000010], b[5000010];
int n;
int next[5000010], i, j;
int main()
{
    memset(next, 0, sizeof(next));
    scanf("%s", b);
    n = strlen(b);
    for (int i = 0; i < n; ++i)
        a[i] = b[n - i - 1];
    a[n] = '\0';
    next[0] = -1;
    i = -1;
    j = 0;
    while (j < n)
    {
        if ((i == -1) || (b[i] == b[j]))
        {
            ++i; ++j;
            if (b[i]!= b[j]) next[j] = i;
            else next[j] = next[i];
        }
        else i = next[i];
    }
    i = 0;
    j = 0;
    while (i < n)
    {
        if ((j == -1) || (a[i] == b[j]))
        {
            ++i, ++j;
        }
        else j = next[j];
    }
    printf("%d\n", j);
    return 0;
}
