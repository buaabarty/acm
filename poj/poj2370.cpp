#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX_N 10010
using namespace std;
int n, res;
int num[MAX_N];
void sort(int l, int r)
{
    int i = l, j = r, mid = num[(i + j) / 2];
    do{
        while (num[i] < mid) i++;
        while (num[j] > mid) j--;
        if (i <= j)
        {
            swap(num[i], num[j]);
            i++; j--;
        }
    }while (i <= j);
    if (l < j) sort(l, j);
    if (i < r) sort(i, r);
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &num[i]);
        sort(1, n);
        res = 0;
        for (int i = 1; i <= (n + 1) / 2; i++)
            res += (num[i] + 1) / 2;
        printf("%d\n", res);
    }
    return 0;
}
