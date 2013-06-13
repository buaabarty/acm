#include <cstdio>
#include <algorithm>
using namespace std;
int n, k, x[100000], y[100000], g[100000][4], o[100000];
char s[100001];
bool cmp1(int i, int j)
{
  if(x[i] + y[i] == x[j] + y[j])
    return x[i] <= x[j];
  return x[i] + y[i] <= x[j] + y[j];
}
bool cmp2(int i, int j)
{
  if(x[i] - y[i] == x[j] - y[j])
    return x[i] <= x[j];
  return x[i] - y[i] <= x[j] - y[j];
}
int main()
{
  freopen("jump.in", "r", stdin);
  freopen("jump.out", "w", stdout);
  scanf("%d%d%s", &n, &k, &s);
  for(int i = 0; i < n; ++ i)
  {
    scanf("%d%d", &x[i], &y[i]);
    o[i] = i;
  }
  memset(g, 255, sizeof(g));
  sort(o, o + n, cmp1);
  for(int i = 1; i < n; ++ i)
    if(x[o[i - 1]] + y[o[i - 1]] == x[o[i]] + y[o[i]])
    {
      g[o[i]][2] = o[i - 1];
      g[o[i - 1]][1] = o[i];
    }
  sort(o, o + n, cmp2);
  for(int i = 1; i < n; ++ i)
    if(x[o[i - 1]] - y[o[i - 1]] == x[o[i]] - y[o[i]])
    {
      g[o[i]][3] = o[i - 1];
      g[o[i - 1]][0] = o[i];
    }
  int now = 0;
  for(int i = 0; i < k; ++ i)
  {
    int way = s[i] - 'A';
    if(g[now][way] != -1)
    {
      g[g[now][0]][3] = g[now][3];
      g[g[now][1]][2] = g[now][2];
      g[g[now][2]][1] = g[now][1];
      g[g[now][3]][0] = g[now][0];
      now = g[now][way];
    }
  }
  printf("%d %d\n", x[now], y[now]);
  return 0;
}
