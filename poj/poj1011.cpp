#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 128
using namespace std;
int n, num[MAXN], sum = 0;
bool init()
{
    scanf("%d", &n);
    if (n == 0) return false;
    sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    sort(num + 1, num + n + 1);
    /*for (int i = 1; i <= n; ++i)
        printf("%d ", num[i]);
    printf("\n");*/
    return true;
}

int limit;
bool use[MAXN];

bool dfs(int nows, int lasts, int lastk)
{
//    printf("%d %d %d\n", nows, lasts, lastk);
//    for (int i = 1; i <= n; ++i) printf("%3d", use[i]);printf("   :   %d %d %d\n", nows, lasts, lastk);
    if (lasts == 0) return true;
    if (nows == limit){
        for (int i = lastk - 1; i >= 1; --i)
            if (!use[i]){
                if (nows < num[i]) return false;
                if (nows == num[i]){
                    use[i] = true;
                    if (dfs(limit, lasts - num[i], n + 1)) return true;
                    else{
                        use[i] = false;
                        return false;
                    }
                }
                use[i] = true;
                if (dfs(nows - num[i], lasts - num[i], i)) return true;
                else {
                    use[i] = false;
                    return false;
                }
            }
    }
    for (int i = lastk - 1; i >= 1; --i)
        if ((num[i] == nows) && (!use[i]))
        {
            use[i] = true;
            if (dfs(limit, lasts - num[i], n + 1)) return true;
            else{
                use[i] = false;
                return false;
            }
        }
    for (int i = lastk - 1; i >= 1; --i)
        if ((num[i] < nows) && (!use[i]) && (nows - num[i] >= num[1]) && (use[i + 1] || (num[i] != num[i + 1])))
        {
            use[i] = true;
            if (dfs(nows - num[i], lasts - num[i], i)) return true;
            use[i] = false;
        }
    return false;
}

bool okay(int x)
{
//    for (int i = 1; i <= n; ++i) printf("%d ", num[i]);
//    printf("\n");
    if (num[n] > x) return false;
    limit = x;
    memset(use, false, sizeof(use));
    return dfs(x, sum, n + 1);
}

int main()
{
    while (init())
    {
//        for (int i = 1; i <= n; ++i) printf("%3d", num[i]);printf("\n");
//        printf("%d\n", okay(20));
        for (int i = 1; i <= sum; ++i)
            if ((sum % i == 0) && (okay(i))){
                printf("%d\n", i);
                break;
            }
    }
    return 0;
}
