#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50000 + 9;
int n, T;
struct Node{
    int mkey, akey;//mkeyÂú×ãÅÅĞòĞÔ£¬akeyÂú×ã¶ÑĞÔ
    bool operator < (Node b) const {
        return mkey < b.mkey;
    }
} a[maxn];

int s1[maxn], s2[maxn];

int stack[maxn];
int fa[maxn], ch[maxn][2];
int q[maxn], l, r;
int tot1, tot2;
void bfs(int v) {
    memset(q, 0, sizeof(q));
    l = 1, r = 1;
    q[1] = v;
    s1[v] = 2;
    s2[v] = 1;
    while (l <= r) {
        int now = q[l++];
        if (ch[now][0]) {
            q[++r] = ch[now][0];
            s1[q[r]] = s1[now] + 1;
            s2[q[r]] = s2[now];
        }
        if (ch[now][1]) {
            q[++r] = ch[now][1];
            s1[q[r]] = s1[now] + 1;
            s2[q[r]] = s2[now] + 1;
        }
    }
    tot1 = 2, tot2 = 1;
    for (int i = 1; i <= n; ++i)
        tot1 += s1[i], tot2 += s2[i];
}
void gao() {
    int i, k, top = 0;
    memset(ch, 0, sizeof(ch));
    memset(fa, 0, sizeof(fa));
    memset(stack, 0, sizeof(stack));
    stack[0] = 0; // As the father of root;
    for(i = 1; i <= n; ++i) {
        k = top;
        while( k > 0 && a[stack[k]].akey > a[i].akey ) --k;
        if( top == k ){
            fa[i]= stack[k];
            stack[++k]= i;
        }
        else if( top > k ){
            fa[ stack[k+1] ] = i;
            fa[i] = stack[k];
            stack[++k] = i;
        }
        top = k;
    }
    for(i = 1; i <= n; ++i) ch[i][0] = ch[i][1] = 0;
    for(i = 1; i <= n; ++i) {
        if( a[ fa[i] ].mkey > a[i].mkey ) ch[ fa[i] ][0] = i;
        else ch[ fa[i] ][1] = i;
    }
    int root = 0;
    for (int i = 1; i <= n; ++i)
        if (!fa[i]) {
            bfs(i); break;
        }
}



int main() {
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i].mkey);
            a[i].akey = i;
        }
        sort(a + 1, a + n + 1);
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        gao();
        printf("Case #%d: %d %d\n", ca, tot1, tot2);
    }
    return 0;
}
