#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
bool readword(string &a)
{
    a = ""; char c;
    if (scanf("%c", &c) == EOF) return false;
    while (!isalpha(c))
        if (scanf("%c", &c) == EOF) return false;
    while (isalpha(c))
    {
        a = a + (char)tolower(c);
        if (scanf("%c", &c) == EOF) return false;
    }
    return true;
}
string now, dat[1024];
int cnt1, cnt2, nowc, len;
bool push(string s)
{
    for (int i = 1; i <= len; ++i)
        if (s == dat[i]) return false;
    dat[++len] = s;
    return true;
}
int gcd(int x, int y)
{
    return (x) ? gcd(y % x, x) : y;
}
int main()
{
    cnt1 = cnt2 = nowc = len = 0;
    while (readword(now))
    {
        if (now == "bullshit")
        {
            len = 0;
            cnt1++;
            cnt2 += nowc;
            nowc = 0;
        }
        else nowc += push(now);
    }
    int g = gcd(cnt1, cnt2);
    cnt1 /= g, cnt2 /= g;
    printf("%d / %d\n", cnt2, cnt1);
    return 0;
}
