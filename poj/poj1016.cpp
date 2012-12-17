#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#define MAXL 32768
using namespace std;
char temp[MAXL];
char* next(char* s)
{
    int cnt[10];
    memset(cnt, 0, sizeof(cnt));
    memset(temp, 0, sizeof(temp));
    int tl = 0;
    for (int i = 0, l = strlen(s); i < l; ++i)
        ++cnt[s[i] - '0'];
    for (int i = 0; i < 10; ++i)
    {
        if (cnt[i])
        {
            if (cnt[i] > 9){
                temp[tl++] = (cnt[i] / 10) + '0';
                cnt[i] %= 10;
                temp[tl++] = cnt[i] + '0';
            }
            else{
                temp[tl++] = cnt[i] + '0';
            }
            temp[tl++] = i + '0';
        }
    }
    temp[tl] = '\0';
    return temp;
}
void my_strcpy(char *s1, char *s2)
{
    int l = strlen(s2);
    for (int i = 0; i < l; ++i)
        s1[i] = s2[i];
    s1[l] = '\0';
}
int main()
{
//    freopen("prob.in", "r", stdin);
//    freopen("prob.out", "w", stdout);
    char str[16][MAXL];
    while (scanf("%s", str[0]))
    {
        if (str[0][0] == '-') break;
        int loop = -1, start;
        for (int i = 1; i <= 15; ++i)
        {
            my_strcpy(str[i], next(str[i - 1]));
            //printf("%s\n", str[i]);
            for (int j = 0; j < i; ++j)
                if (strcmp(str[j], str[i]) == 0){
                    loop = i - j - 1;
                    start = i;
                    break;
                }
            if (loop >= 0) break;
        }
        if (loop == -1) printf("%s can not be classified after 15 iterations\n", str[0]);
        else if (loop == 0){
            if (start == 1) printf("%s is self-inventorying\n", str);
            else printf("%s is self-inventorying after %d steps\n", str, start - 1);
        }
        else printf("%s enters an inventory loop of length %d\n", str, loop + 1);
    }
    return 0;
}
