#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <queue>
#define MAX_N 200
using namespace std;
class node{
    public:
        int y, d;
        node(int a, int b)
        {
            y = a, d = b;
        }
};
vector<node> map[MAX_N];
queue<int> q;
int n, d[MAX_N];
bool inq[MAX_N];
void spfa(int v)
{
    for (int i = 1; i <= n; ++i)
        d[i] = 1000000000;
    d[v] = 0;
    memset(inq, false, sizeof(inq));
    inq[v] = true;
    q.push(v);
    while (!q.empty())
    {
        int x = q.front();
        for (int i = 0, l = map[x].size(); i < l; ++i)
        {
            int yy = map[x][i].y, dd = map[x][i].d;
            if (d[x] + dd < d[yy])
            {
                d[yy] = d[x] + dd;
                if (!inq[yy])
                {
                    q.push(yy);
                    inq[yy] = true;
                }
            }
        }
        q.pop();
        inq[x] = false;
    }
}
void init()
{

    for (int i = 1; i <= n; ++i) map[i].clear();
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j)
        {
            char str[100];
            cin >> str;
            if (str[0] == 'x') continue;
            int x = atoi(str);
            map[i].push_back(node(j, x));
            map[j].push_back(node(i, x));
        }
}
int main()
{
    while (cin >> n)
    {
        init();
        spfa(1);
        int res = 0;
        for (int i = 2; i <= n; ++i)
            if (d[i] < 1000000000)
                res = max(res, d[i]);
        cout << res << endl;
    }
    return 0;
}
