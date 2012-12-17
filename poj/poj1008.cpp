#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char name1[20][10] = { "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
char name2[21][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int s1[20];
int ord1(char *s)
{
    for (int i = 0; i < 19; ++i)
        if (strcmp(s, name1[i]) == 0) return i;
    return -1;
}
int main()
{
    s1[1] = 20;
    for (int i = 2; i <= 18; ++i) s1[i] = s1[i - 1] + 20;
    s1[19] = 365;
    int t;
    scanf("%d", &t);
    printf("%d\n", t);
    for (int ca = 1; ca <= t; ++ca)
    {
        int d, y, m, s;
        char mon[10];
        scanf("%d.%s%d", &d, mon, &y);
        m = ord1(mon);
        s = y * 365 + s1[m] + d;
        int a1, ay, a2;
        ay = s / 260;
        s %= 260;
        a1 = s % 20;
        a2 = s % 13 + 1;
        printf("%d %s %d\n", a2, name2[a1], ay);
    }
    return 0;
}
