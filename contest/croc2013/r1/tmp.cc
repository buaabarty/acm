#include <iostream>
#include <cstdio>
#include <cstring>
#define clr(x) memset(x, 0,sizeof(x))
using namespace std;
const int maxn = 100010;
struct Aho_Corasick {
    int ch[maxn][26], d[maxn], sz, fail[maxn], q[maxn], l, r;
    void init() {
        sz = 1;
        memset(ch[0], 0, sizeof(ch[0]));
    }
    void insert(char *str) {
        int p = 0;
        for (; *str; ++str) {
            int x = (*str) - 'a';
            if (!ch[p][x]) {
                ch[p][x] = sz++;
                memset(ch[sz-1], 0, sizeof(ch[sz-1]));
                fail[sz-1] = 0;
                d[sz-1] = 0;
            }
            p = ch[p][x];
        }
        ++d[p];//同一个模式串可能出现多次
    }
    void build_automation() {
        clr(q); l = 1; r = 0;
        for (int i = 0; i < 26; ++i)
            if (ch[0][i]) q[++r] = ch[0][i];
        while (l <= r) {
            int now = q[l++];
            for (int i = 0; i < 26; ++i)
                if (ch[now][i]) {
                    q[++r]= ch[now][i];
                    fail[ch[now][i]] = ch[fail[now]][i];
                } else ch[now][i] = ch[fail[now]][i];
        }
    }
    int count(char *str) {
        int p = 0, ret = 0, q;
        for (; *str; ++str) {
            while (!ch[p][(*str)-'a'] && p) p = fail[p];
            if (ch[p][(*str)-'a']) p = ch[p][(*str)-'a'];
            q = p;
            while (q && ~ d[q]) {
                ret += d[q];
                d[q] = -1;//同一个模式串只计算一次
                q = fail[q];
            }
        }
        return ret;
    }
}ac;
char str[1000010];
int main() {
    int n;
    char a[200];
    scanf("%s%d", str, &n);
    ac.init();
    for (int i = 1; i <= n; ++i) {
        scanf("%s", a);
        ac.insert(a);
    }
    ac.build_automation();
    printf("%d\n", ac.count(str));
    return 0;
}
