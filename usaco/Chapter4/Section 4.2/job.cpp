/*
ID:ybojan2
LANG:C++
TASK:job
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <climits>
#define MAXN 1024
using namespace std;
void mfill(int num[], int time[], int cost[], int m, int n)
{
    memset(time, 0, sizeof(time));
    memset(cost, 0, sizeof(cost));
    for (int i = 1; i <= n; ++i)
    {
        int x = INT_MAX, y = 0;
        for (int j = 1; j <= m; ++j)
            if (num[j] + time[j] < x)
            {
                x = num[j] + time[j];
                y = j;
            }
        time[y] += num[y];
        cost[i] = x;
    }
}
int n, s1, s2, n1[MAXN], n2[MAXN], t1[MAXN], t2[MAXN], c1[MAXN], c2[MAXN];
int main()
{
    freopen("job.in", "r", stdin);
    freopen("job.out", "w", stdout);
    scanf("%d%d%d", &n, &s1, &s2);
    for (int i = 1; i <= s1; ++i) scanf("%d", &n1[i]);
    for (int i = 1; i <= s2; ++i) scanf("%d", &n2[i]);
    mfill(n1, t1, c1, s1, n);
    int resa = 0, resb = 0;
    for (int i = 1; i <= n; ++i) resa = max(resa, c1[i]);
    mfill(n2, t2, c2, s2, n);
    for (int i = 1; i <= n; ++i) resb = max(resb, c1[i] + c2[n - i + 1]);
    printf("%d %d\n", resa, resb);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
