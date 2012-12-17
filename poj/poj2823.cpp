#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define N 1000010
using namespace std;
struct node
{
    int pos, val;
    node(int _pos, int _val)
    {
        pos = _pos, val = _val;
    }
    node(){}
}q[N];
int head, tail, num[N], n, k;
void format_queue()
{
    memset(q, 0, sizeof(q));
    head = tail = 1;
    q[1] = node(1, num[1]);
    for (int i = 2; i <= k && i <= n; ++i)
    {
        while ((num[i] <= q[tail].val) && (tail > head)) tail--;
        if (num[i] <= q[tail].val) q[tail] = node(i, num[i]);
        else q[++tail] = node(i, num[i]);
    }
}
int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        if (!n) continue;
        for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
        format_queue();
        printf("%d", q[head].val);
        for (int i = k + 1; i <= n; ++i)
        {
            while ((num[i] <= q[tail].val) && (tail > head)) tail--;
            if (num[i] <= q[tail].val) q[tail] = node(i, num[i]);
            else q[++tail] = node(i, num[i]);
            while ((q[head].pos <= i - k) && (head < tail)) head++;
            printf(" %d", q[head].val);
        }
        puts("");
        for (int i = 1; i <= n; ++i) num[i] = -num[i];
        format_queue();
        printf("%d", -q[head].val);
        for (int i = k + 1; i <= n; ++i)
        {
            while ((num[i] <= q[tail].val) && (tail > head)) tail--;
            if (num[i] <= q[tail].val) q[tail] = node(i, num[i]);
            else q[++tail] = node(i, num[i]);
            while ((q[head].pos <= i - k) && (head < tail)) head++;
            printf(" %d", -q[head].val);
        }
        puts("");
    }
    return 0;
}
