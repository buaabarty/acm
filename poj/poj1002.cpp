#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#define MAXN 100010

using namespace std;
string str;
map<string, int> res;
char ss[256];
int d[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};
int dat(char c)
{
    return d[c - 'A'] + '0';
}
string change(string s)
{
    string a = "--------";
    int len = s.length(), k = 0;
    for (int i = 0; i < len; ++i)
    {
        if ((s[i] >= '0') && (s[i] <= '9'))
            a[k++] = s[i];
        else if ((s[i] >= 'A') && (s[i] <= 'Z'))
            a[k++] = dat(s[i]);
        if (k == 3) ++k;
    }
    return a;
}
void print(string s, int l)
{
    for (int i = 0; i <= 2; ++i) printf("%c", s[i]);
    printf("-");
    for (int i = 3; i < 7; ++i) printf("%c", s[i]);
    printf(" %d\n", l);

}
int ans[MAXN];
int main()
{
    map<string, int>::iterator iter;
    ios::sync_with_stdio(false);
    int n, cnt = 0;
    string a;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
            cin >> str;
            string a = "--------";
            int len = str.length(), k = 0;
            for (int j = 0; j < len; ++j)
                {
                    if ((str[j] >= '0') && (str[j] <= '9'))
                        a[k++] = str[j];
                    else if ((str[j] >= 'A') && (str[j] <= 'Z'))
                        a[k++] = dat(str[j]);
                    if (k == 3) ++k;
                }
            iter = res.find(a);
            if (iter == res.end())
            {
                res[a] = cnt;
                ans[cnt++] = 1;
            }
            else
            {
                ans[iter->second]++;
            }
    }
    bool flag = false;
    for (iter = res.begin(); iter != res.end(); ++iter)
        if (ans[iter->second] > 1)
        {
            flag = true;
            cout << iter -> first << " " << ans[iter -> second] << endl;
        }
    if (!flag) cout << "No duplicates." << endl;
    return 0;
}
