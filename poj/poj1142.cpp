#include <iostream>
#include <cstring>
#include <cstdio>
#define MAXL 10000
#define MAXN 100000
using namespace std;
int lp = 0, p[MAXL];
bool isp[100000];
int sum[1000000];
int rsum(int x)
{
    int s = 0;
    while (x > 0)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}
void make_prime_list()
{
    for (int i = 0; i < 1000000; ++i)
        sum[i] = rsum(i);
    memset(isp, true, sizeof(isp));
    for (int i = 2; i < 100000; ++i)
        if (isp[i]){
            p[++lp] = i;
            for (int j = i + i; j < 100000; j += i)
                isp[j] = false;
        }
}
int sum1(int x)
{
    int s = 0;
    while (x > 1000000)
    {
        s += x % 10;
        x /= 10;
    }
    s += sum[x];
    return s;
}
int sum2(int x)
{
    int s = 0;
    bool change = false;
    for (int i = 1; p[i] * p[i] <= x; ++i)
        while (x % p[i] == 0){
            s += sum1(p[i]);
            x /= p[i];
            change = true;
        }
    if (!change) return -1;
    if (x != 1) s += sum1(x);
    return s;
}
int main()
{
    //freopen("smith.in", "r", stdin);
    make_prime_list();
    int x;
    while (scanf("%d", &x))
    {
        if (!x) break;
        for (int i = x + 1; i < 150000000; ++i)
            if (sum1(i) == sum2(i)){
                printf("%d\n", i);
                break;
            }
    }
    //fclose(stdin);
    return 0;
}
