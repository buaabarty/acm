#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#define MAXN 32
using namespace std;
int x, d[MAXN], n, m, sum = 0, fa[MAXN];
int father(int v)
{
    if (fa[v] != v) fa[v] = father(fa[v]);
    return fa[v];
}
int main()
{

    stringstream ss;
    string str;
    while (cin >> str)
    {
        sum = 0;
        memset(d, 0, sizeof(d));
        if (str == "ENDOFINPUT") break;
        cin >> m >> n;
        for (int i = 0; i < n; ++i)
            fa[i] = i;
        getline(cin, str);
        for (int i = 0; i < n; ++i)
        {
            getline(cin, str);
            ss << str;
            while (ss >> x)
            {
                d[i]++, d[x]++, sum++;
                int fx = father(i), fy = father(x);
                if (fx != fy) fa[fx] = fy;
            }
            ss.clear();
        }
        getline(cin, str);
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (d[i] & 1) cnt++;
        if ((cnt == 0) || (cnt == 2))
        {
            if (cnt == 2){
                bool flag = true;
                for (int i = 0; i < n; ++i)
                    if ((d[i]) && (father(i) != father(0))){
                        flag = false;
                        break;
                    }
                if (!flag) cout << "NO" << endl;
                else{
                    int x, y;
                    for (int i = 0; i < n; ++i)
                        if (d[i] & 1){
                            x = i;
                            break;
                        }
                    for (int i = x + 1; i < n; ++i)
                        if(d[i] & 1){
                            y = i;
                            break;
                        }
                    if ((x == 0) && (y == m) && (father(0) == father(m))) cout << "YES " << sum << endl;
                    else cout << "NO" << endl;
                }
            }
            else if (father(0) == father(m)) cout << "YES " << sum << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}
