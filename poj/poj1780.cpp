#include <iostream>
#include <cstring>
#include <cstdio>
#define N 100010
#define M 1000010
using namespace std;
int n, p10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};
struct edge
{
    int v, next;
    bool f;
}e[M];
int p[N], eid;
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
void insert(int x, int y)
{
    e[eid].v = y;
    e[eid].next = p[x];
    e[eid].f = true;
    p[x] = eid++;
}
int stack[M], top, len;
char res[M];
void dfs(int v)
{
    stack[++top] = v;
    while (top)
    {
        int x = stack[top];
        bool flag = true;
        for (int i = p[x]; i != -1; i = e[i].next)
            if (e[i].f)
            {
                e[i].f = false;
                stack[++top] = e[i].v;
                flag = false;
                break;
            }
        if (flag)
        {
            stack[top--] = 0;
            res[len++] = (x % 10) + '0';
        }
    }
}
int main()
{
    while (scanf("%d", &n), n)
    {
        if (n == 1) puts("0123456789");
        else
        {
            top = len = 0;
            memset(stack, 0, sizeof(stack));
            mapinit();
            for (int i = 0; i < p10[n - 1]; ++i)
                for (int k = 9; k >= 0; --k)
                    insert(i, (i * 10 + k) % p10[n - 1]);
            dfs(0);
            for (int i = 1; i <= n - 2; ++i) putchar('0');
            for (int i = len - 1; i >= 0; --i) putchar(res[i]);
            printf("\n");
        }
    }
    return 0;
}
