#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#define MAX_N 200
using namespace std;
string str;
string dat[MAX_N];
int cnt[MAX_N], s[MAX_N], link[MAX_N], n;
vector<int> map[MAX_N];
bool vst[MAX_N];
int ord(char c)
{
    switch (c)
    {
        case 'S': return 1; break;
        case 'M': return 2; break;
        case 'L': return 3; break;
        case 'X': return 4; break;
        case 'T': return 5; break;
        default : return 0;
    }
}
bool dfs(int v)
{
    for (int i = 0, l = map[v].size(); i < l; ++i)
    {
        int u = map[v][i];
        if (!vst[u])
        {
            vst[u] = true;
            if (link[u] == 0 || dfs(link[u]))
            {
                link[u] = v;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while (cin >> str)
    {
        for (int i = 1; i < 200; ++i)
            map[i].clear();
        if (str == "ENDOFINPUT") break;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> dat[i];
        s[0] = 0;
        for (int i = 1; i <= 5; ++i)
        {
            cin >> cnt[i];
            s[i] = s[i - 1] + cnt[i];
        }
        int ks = 0;
        for (int i = 1; i <= n; ++i)
        {
            int st = ord(dat[i][0]);
            int ed = ord(dat[i][1]);
            for (int j = s[st - 1] + 1; j <= s[ed]; ++j)
                map[i].push_back(j);
        }
        memset(link, 0, sizeof(link));
        int res = 0;
        /*for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < map[i].size(); ++j)
                printf("%d ", map[i][j]);
            printf("\n");
        }*/
        for (int i = 1; i <= s[5]; ++i)
        {
            memset(vst, false, sizeof(vst));
            if (dfs(i)) res++;
        }
        //printf("%d\n", res);

        if (res == n) printf("T-shirts rock!\n");
        else printf("I'd rather not wear a shirt anyway...\n");
        cin >> str;
    }
    return 0;
}
