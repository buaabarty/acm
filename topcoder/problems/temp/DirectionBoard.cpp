#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXM = 20000;
const int MAXN = 500;
struct edge{
    int x, y, f, c, next;
}e[MAXM];
int eid, p[MAXN];//邻接表数据结构
int N, M, source, sink;//source标记源点，sink标记汇点
int d[MAXN], pre[MAXN], path[MAXN];//pre标记最短路径上节点的前驱，path记录是有哪条边扩展过来的
queue<int> q;//SPFA使用的队列
bool use[MAXN];//标记是否在队列内
void insert(int x, int y, int f, int c)
{
    e[eid].x = x;
    e[eid].y = y;
    e[eid].f = f;
    e[eid].c = c;
    e[eid].next = p[x];
    p[x] = eid++;
}
void insert1(int x, int y, int f, int c)
{
    //cout << x << " " << y << endl;
    insert(x, y, f, c);
    insert(y, x, 0, -c);
}
void insert2(int x, int y, int f, int c)
{
    insert1(x, y, f, c);
    insert1(y, x, f, c);
}
void mapinit()
{
    memset(p, -1, sizeof(p));
    eid = 0;
}
bool spfa(int s)
{
    memset(use, false, sizeof(use));
    int u, v;
    for (int i = 1; i <= N; ++i) d[i] = 1000000000;
    while (!q.empty()) q.pop();
    q.push(s);
    d[s] = 0;
    pre[s] = -1;
    use[s] = true;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int i = p[u]; i != -1; i = e[i].next)
        {
            v = e[i].y;
            if ((e[i].f != 0) && (d[u] + e[i].c < d[v])){
                d[v] = d[u] + e[i].c;
                pre[v] = u;
                path[v] = i;
                if (!use[v]){
                    use[v] = true;
                    q.push(v);
                }
            }
        }
        use[u] = false;
    }
    return (d[sink] != 1000000000);
}
int argument()
{
    int delta = 1000000000, res = 0;
    for (int i = sink; pre[i] != -1; i = pre[i])
        delta = min(delta, e[path[i]].f);
    for (int i = sink; pre[i] != -1; i = pre[i])
    {
        e[path[i]].f -= delta;
        e[path[i] ^ 1].f += delta;
        res += e[path[i]].c * delta;
    }
    return res;
}
int maxcostflow()
{
    //cout << "W";
    int sum = 0;
    while (spfa(source)) {
        sum += argument();
        //cout << "WFT" << endl;
    }
    return sum;
}

const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char str[10] = "RDLU";
int ord(char x) {
    for (int i = 0; i < 4; ++i)
        if (str[i] == x) return i;
}
class DirectionBoard {
public:
    int getMinimum(vector <string> board) {
        mapinit();
        int n = board.size(), m = board[0].length();
        int src = n*m*2+1, sk = n*m*2+2;
        int rd[20][20], cd[20][20];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                insert1(src, i*m+j+1, 1, 0);
                insert1(i*m+j+1+n*m, sk, 1, 0);
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                for (int k = 0; k < 4; ++k) {
                    int x = (i + dx[k] + n) % n;
                    int y = (j + dy[k] + m) % m;
                    insert1(i*m+j+1, x*m+y+1+n*m, 1, str[k] != board[i][j]);
                }
        N = sk;
        source = src, sink = sk;
        return maxcostflow();
    }

};
