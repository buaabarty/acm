/*
ID:ybojan2
LANG:C++
TASK:fence8
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 64
#define MAXR 1024
using namespace std;
int n, r, board[MAXN], rail[MAXR], sum[MAXR], bs;
int temp_board[MAXN];
void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &board[i]);
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (board[i] < board[j]) swap(board[i], board[j]);
    scanf("%d", &r);
    for (int i = 1; i <= r; ++i)
        scanf("%d", &rail[i]);
    for (int i = 1; i <= r; ++i)
        for (int j = i + 1; j <= r; ++j)
            if (rail[i] > rail[j]) swap(rail[i], rail[j]);
    while (board[n] < rail[1]) --n;
    while (rail[r] > board[1]) --r;
    bs = 0;
    for (int i = 1; i <= n; ++i) bs += board[i];
    sum[0] = 0;
    for (int i = 1; i <= r; ++i)
        sum[i] = sum[i - 1] + rail[i];
}
bool dfs(int deep, int last, int s)
{
    if (s < sum[deep]) return false;
    bool flag = false;
    if (deep == 0) return true;
    for (int i = last; i <= n; ++i)
        if (board[i] == rail[deep])
        {
            board[i] -= rail[deep];
            s -= rail[deep];
            if (board[i] < rail[1]) s -= board[i];
            if (rail[deep] == rail[deep - 1]) flag |= dfs(deep - 1, i, s);
            else flag |= dfs(deep - 1, 1, s);
            if (flag) return true;
            if (board[i] < rail[1]) s += board[i];
            s += rail[deep];
            board[i] += rail[deep];
        }
    for (int i = last; i <= n; ++i)
        if (board[i] >= rail[deep])
        {
            board[i] -= rail[deep];
            if (board[i] < rail[1]) s -= board[i];
            s -= rail[deep];
            if (rail[deep] == rail[deep - 1]) flag |= dfs(deep - 1, i, s);
            else flag |= dfs(deep - 1, 1, s);
            if (flag) return true;
            s += rail[deep];
            if (board[i] < rail[1]) s += board[i];
            board[i] += rail[deep];
        }
    return false;
}
bool okay(int limit)
{
    for (int i = 1; i <= n; ++i) board[i] = temp_board[i];
    return dfs(limit, 1, bs);
}
int solve()
{
    for (int i = 1; i <= n; ++i) temp_board[i] = board[i];
    int left = 0, right = r, mid;
    while (left < right)
    {
        if (left + 1 == right)
        {
            if (okay(right)) return right;
            else return left;
        }
        mid = (left + right + 1) / 2;
        if (okay(mid)) left = mid;
        else right = mid - 1;
    }
    return left;
}
int main()
{
    freopen("fence8.in", "r", stdin);
    freopen("fence8.out", "w", stdout);
    init();
    printf("%d\n", solve());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
