#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 26
using namespace std;
int n, rd[MAXN], cd[MAXN];
char str[1024];
int fa[MAXN];
int father(int v)
{
    if (fa[v] != v) fa[v] = father(fa[v]);
    return fa[v];
}
int main()
{
    int __;
    scanf("%d", &__);
    while (__--)
    {
        scanf("%d", &n);
        memset(rd, 0, sizeof(rd));
        memset(cd, 0, sizeof(cd));
        for (int i = 0; i < 26; ++i) fa[i] = i;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", str);
            int x = str[0] - 'a', y = str[strlen(str) - 1] - 'a';
            ++cd[x];
            ++rd[y];
            if (father(x) != father(y)) fa[father(x)] = father(y);
        }
        for (int i = 0; i < 26; ++i) fa[i] =father(i);
        int temp;
        for (int i = 0; i < 26; ++i)
            if (rd[i] + cd[i]) temp = fa[i];
        bool okay = true;
        for (int i = 0; i < 26; ++i)
            if ((rd[i] + cd[i]) && (fa[i] != temp)) okay = false;
        int cnt = 0;
        for (int i = 0; i < 26; ++i)
            if (rd[i] - cd[i]) ++cnt;
        if ((cnt == 1) || (cnt > 2)) okay = false;
        else if (cnt == 2){
            bool flag1 = false, flag2 = false;
            for (int i = 0; i < 26; ++i)
            {
                flag1 |= (rd[i] == cd[i] + 1);
                flag2 |= (rd[i] == cd[i] - 1);
            }
            if (!flag1 || !flag2) okay = false;
        }
        if (okay) printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }
    return 0;
}
