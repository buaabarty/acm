/*
ID:ybojan2
LANG:C++
TASK:cryptcow
*/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#define MAXN 1000
#define mod 1000003
using namespace std;
const char dest[50] = "Begin the Escape execution at the Break of Dawn";
const int dest_len = 47;
char str[80], temp[80];
int pos_c[MAXN], pos_o[MAXN], pos_w[MAXN];
int cl, ol, wl;
bool use_c[MAXN], use_o[MAXN], use_w[MAXN];
bool app[mod];
int st[256][100], l[256];
void swap(int x, int y, int z, char *s)
{
    int len = strlen(s);
    memset(temp, 0, sizeof(temp));
    int l = 0;
    for (int i = 0; i < x; ++i) temp[l++] = s[i];
    for (int i = y + 1; i < z; ++i) temp[l++] = s[i];
    for (int i = x + 1; i < y; ++i) temp[l++] = s[i];
    for (int i = z + 1; i < len; ++i) temp[l++] = s[i];
    temp[l] = '\0';
    strcpy(s, temp);
}
// BKDR Hash Function
unsigned int BKDRHash(char *s)
{
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    int len = strlen(s);
    for (int i = 0; i < len; ++i)
    {
        hash = hash * seed + s[i];
    }
    return (hash & 0x7FFFFFFF) % mod;
}
bool init()
{
    gets(str);
    int len = strlen(str);
    int cnt[256];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < dest_len; ++i)
        cnt[dest[i]]++;
    cl = ol = wl = 0;
    memset(pos_c, 0, sizeof(pos_c));
    memset(pos_o, 0, sizeof(pos_o));
    memset(pos_w, 0, sizeof(pos_w));
    memset(app, false, sizeof(app));
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == 'C') pos_c[++cl] = i;
        else if (str[i] == 'O') pos_o[++ol] = i;
        else if (str[i] == 'W') pos_w[++wl] = i;
        else cnt[str[i]]--;
    }
    memset(l, 0, sizeof(l));
    for (int i = 0; i < dest_len; ++i)
        st[dest[i]][++l[dest[i]]] = i;
    memset(use_c, false, sizeof(use_c));
    memset(use_o, false, sizeof(use_o));
    memset(use_w, false, sizeof(use_w));
    return ((cl == ol) && (cl == wl));
}
bool is_ex(char c)
{
    return (c == 'C') || (c == 'O') || (c == 'W');
}
bool dfs(int deep)
{
    if (app[BKDRHash(str)]) return false;
    app[BKDRHash(str)] = true;
    if (deep == 0)
    {
        if (strcmp(str, dest) == 0) return true;
        else return false;
    }
    char ttemp[80];
    int len = strlen(str);
    for (int i = 0; i < len; ++i)
        if (is_ex(str[i]))
        {
            if (str[i] != 'C') return false;
            break;
        }
    for (int i = len - 1; i >= 0; --i)
        if (is_ex(str[i]))
        {
            if (str[i] != 'W') return false;
            break;
        }
    int last = 0;
    for (int i = 0; i < len; ++i)
        if (is_ex(str[i]))
        {
            bool find = false;
            for (int j1 = 1; j1 <= l[str[last]]; ++j1)
                {
                    int j = st[str[last]][j1];
                    bool same =true;
                    for (int k = 0; k < i - last; ++k)
                        if (str[last + k] != dest[j + k])
                        {
                            same = false;
                            break;
                        }
                    if (same) find = true;
                }
            if (!find && (i != last))
            {
                return false;
            }
            last = i + 1;
        }
    for (int i = 0; i < len; ++i)
        if (str[i] == 'O')
            for (int j = 0; j < i; ++j)
                if (str[j] == 'C')
                    for (int k = len - 1; k > i; --k)
                        if (str[k] == 'W')
                        {
                            strcpy(ttemp, str);
                            swap(j, i, k, str);
                            if (dfs(deep - 1)) return true;
                            strcpy(str, ttemp);
                        }
    return false;
}
void error()
{
    printf("0 0\n");
}
int main()
{
    freopen("cryptcow.in", "r", stdin);
    freopen("cryptcow.out", "w", stdout);
    if (!init()) error();
    else if (!dfs(cl)) error();
    else printf("1 %d\n", cl);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
