#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;
char s[MAXN], b[MAXN];
int main()
{
    while (scanf("%s%s", s, b) != EOF)
    {
        int j = 0, l1 = strlen(s), l2 = strlen(b);
        bool flag = true;
        for (int i = 0; i < l1; ++i)
        {
            while ((j < l2) && (s[i] != b[j])) ++j;
            if (s[i] != b[j]){
                flag = false;
                break;
            }
            ++j;
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
