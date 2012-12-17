#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 32768
#define eps 1e-8
#define read(x) scanf("%d", &(x))
#define longint long long
using namespace std;
longint s[MAXN], a[MAXN];
void pre_do()
{
    s[1] = a[1] = 1;
    for (int i = 2; i < 32000; ++i)
    {
        a[i] = a[i - 1] + (longint)(log(i) / log(10) + 1 + eps);
        s[i] = s[i - 1] + a[i];
    }
    //for (int i = 1; i <= 20; ++i) printf("%3d", s[i]);
}
int solve(int n)
{
    int l = 0, r = 31999;
    while (l < r){
        if (l + 1 == r){
            if (n > s[r]) l = r;
            break;
        }
        if (n > s[(l + r + 1) / 2]) l = (l + r + 1) / 2;
        else r = (l + r + 1) / 2 - 1;
    }
    n -= s[l];
    //printf("%d %d\n", n, l);
    r = l, l = 0;
    while (l < r){
        if (l + 1 == r){
            if (n > a[r]) l = r;
            break;
        }
        if (n > a[(l + r + 1) / 2]) l = (l + r + 1) / 2;
        else r = (l + r + 1) / 2 - 1;
    }
    n -= a[l];
    //printf("%d %d\n", n, l);
    l++;
    while (l >= (longint)(exp(n * log(10)) + eps)) l /= 10;
    return l % 10;
}
int main()
{
    pre_do();
    int t, n;
    read(t);
    while (t--)
    {
        read(n);
        printf("%d\n", solve(n));
    }
    return 0;
}
