#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#define MAX_N 50

using namespace std;

int n, m;
bool map[MAX_N][MAX_N];
string str;
bool use[MAX_N];

bool insert(int x, int y)
{
    if (map[y][x]) return false;
    if (x == y) return false;
    map[x][y] = true;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k)
                map[i][j] = map[i][j] || (map[i][k] && map[k][j]);
    return true;
}

bool topsort(int index)
{
    int res[MAX_N], len = 0;
    int rd[MAX_N];
    bool temp[MAX_N][MAX_N];
    bool tuse[MAX_N];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            temp[i][j] = map[i][j];
    for (int i = 1; i <= n; i++)
        tuse[i] = use[i];
    memset(rd, 0, sizeof(rd));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (map[i][j]) rd[j]++;
    while (1)
    {
        int k = 0;
        for (int i = 1; i <= n; i++)
            if (rd[i] == 0 && !use[i])
            {
                if (k == 0) k = i;
                else k = -1;
            }
        if (k <= 0) break;
        res[++len] = k;
        use[k] = true;
        for (int i = 1; i <= n; i++)
            if (map[k][i])
            {
                rd[i]--;
                map[k][i] = false;
            }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            map[i][j] = temp[i][j];
    for (int i = 1; i <= n; i++)
        use[i] = tuse[i];
    if (len != n) return false;
    else
    {
        printf("Sorted sequence determined after %d relations: ", index);
        for (int i = 1; i <= len; i++)
            printf("%c", 'A' + res[i] - 1);
        printf(".\n");
        return true;
    }
}

int main()
{
    while (scanf("%d%d", &n, &m))
    {
        if (n + m == 0) break;
        int flag = 0;
        memset(use, true, sizeof(use));
        memset(map, false,sizeof(map));
        for (int i = 1; i <= m; i++)
        {
            cin >> str;
            if (flag != 0) continue;
            int x = str[0] - 'A' + 1;
            int y = str[2] - 'A' + 1;
            use[x] = false;
            use[y] = false;
            if (!insert(x, y))
            {
                flag = i;
                //break;
            }
            else if (topsort(i))
            {
                flag = m + 1;
                //break;
            }
        }
        if (flag == 0) printf("Sorted sequence cannot be determined.\n");
        else if (flag <= m) printf("Inconsistency found after %d relations.\n", flag);
    }
    return 0;
}
