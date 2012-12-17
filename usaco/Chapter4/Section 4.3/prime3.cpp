/*
ID:ybojan2
LANG:C++
TASK:prime3
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 1024
#define MAXR 10000
#define MAXS 64
using namespace std;
int dat[MAXS][10][MAXN], l[MAXS][10];
bool has0[100000], has2[100000];
int bit_sum(int x)
{
    int s = 0;
    for (; x > 0; s += x % 10, x /= 10);
    return s;
}
bool got_zero(int x)
{
    while (x > 0)
    {
        if (x % 10 == 0) return true;
        x /= 10;
    }
    return false;
}
bool got2(int x)
{
    while (x > 0)
    {
        if (x % 2 == 0) return true;
        x /= 10;
    }
    return false;
}
int got_bit(int x, int k)
{
    k = 5 - k;
    int y = 1;
    while (k--) y *= 10;
    return (x / y) % 10;

}
bool is_prime[100000];
void pre_do()
{
    memset(is_prime, true, sizeof(is_prime));
    memset(dat, 0, sizeof(dat));
    memset(l, 0, sizeof(l));
    int s;
    for (int i = 2; i <= 99999; ++i)
        if (is_prime[i])
        {
            if (i >= 10000)
            {
                s = bit_sum(i);
                ++l[s][i / 10000];
                dat[s][i / 10000][l[s][i / 10000]] = i;
            }
            for (int j = 2; i * j < 100000; ++j)
                is_prime[i * j] = false;
        }
    for (int i = 10000; i <= 99999; ++i)
    {
        has0[i] = got_zero(i);
        has2[i] = got2(i);
    }
}
int map[8][8];
void fillx(int x, int d)
{
    int j = 5;
    while (d > 0)
    {
        map[x][j--] = d % 10;
        d /= 10;
    }
}
void filly(int y, int d)
{
    int j = 5;
    while (d > 0)
    {
        map[j--][y] = d % 10;
        d /= 10;
    }
}
string res[MAXR];
int resl = 0;
void save_map()
{
    res[++resl] = string(' ', 25);
    for (int i = 1; i <= 5; ++i)
        for (int j = 1; j <= 5; ++j)
            res[resl][(i - 1) * 5 + j - 1] = map[i][j] + '0';
}
int main()
{
    freopen("prime3.in", "r", stdin);
    freopen("prime3.out", "w", stdout);
    pre_do();
    int s, t;
    scanf("%d%d", &s, &t);
    bool found = false;
    for (int a = 1; a <= l[s][t]; ++a)
    {
        if (has0[dat[s][t][a]]) continue;
        fillx(1, dat[s][t][a]);
        for (int b = 1; b <= l[s][t]; ++b)
        {
            if (has0[dat[s][t][b]]) continue;
            filly(1, dat[s][t][b]);
            for (int c = 1; c <= l[s][map[1][5]]; ++c)
            {
                if (has2[dat[s][map[1][5]][c]]) continue;
                filly(5, dat[s][map[1][5]][c]);
                for (int d = 1; d <= l[s][map[5][1]]; ++d)
                {
                    if (has2[dat[s][map[5][1]][d]]) continue;
                    if ((dat[s][map[5][1]][d] % 10) != (dat[s][map[1][5]][c] % 10)) continue;
                    fillx(5, dat[s][map[5][1]][d]);

                    int x = map[1][2] + map[1][4] + map[2][1] + map[2][5] + map[4][1] + map[4][5] + map[5][2] + map[5][4] - s;
                    if (x % 3) continue;
                    map[3][3] = x / 3;
                    if ((map[3][3] < 0) || (map[3][3] > 9)) continue;
                    for (int y = 0; y <= 9; ++y)
                    {
                        map[2][2] = y;
                        for (int z = 0; z <= 9; ++z)
                        {
                            map[2][3] = z;
                            map[2][4] = s - map[2][1] - map[2][2] - map[2][3] - map[2][5];
                            if ((map[2][4] < 0) || (map[2][4] > 9)) continue;
                            if (!is_prime[map[2][1] * 10000 + map[2][2] * 1000 + map[2][3] * 100 + map[2][4] * 10 + map[2][5]]) continue;
                            map[4][2] = s - map[1][5] - map[2][4] - map[3][3] - map[5][1];
                            if ((map[4][2] < 0) || (map[4][2] > 9)) continue;
                            map[4][3] = s - map[1][3] - map[2][3] - map[3][3] - map[5][3];
                            if ((map[4][3] < 0) || (map[4][3] > 9)) continue;
                            map[4][4] = s - map[1][1] - map[2][2] - map[3][3] - map[5][5];
                            if ((map[4][4] < 0) || (map[4][4] > 9)) continue;
                            if (!is_prime[map[4][1] * 10000 + map[4][2] * 1000 + map[4][3] * 100 + map[4][4] * 10 + map[4][5]]) continue;
                            map[3][4] = s - map[1][4] - map[2][4] - map[4][4] - map[5][4];
                            if ((map[3][4] < 0) || (map[3][4] > 9)) continue;
                            map[3][2] = s - map[3][1] - map[3][3] - map[3][4] - map[3][5];
                            if ((map[3][2] < 0) || (map[3][2] > 9)) continue;
                            if (!is_prime[map[3][1] * 10000 + map[3][2] * 1000 + map[3][3] * 100 + map[3][4] * 10 + map[3][5]]) continue;
                            if (!is_prime[map[1][1] * 10000 + map[2][2] * 1000 + map[3][3] * 100 + map[4][4] * 10 + map[5][5]]) continue;
                            if (!is_prime[map[5][1] * 10000 + map[4][2] * 1000 + map[3][3] * 100 + map[2][4] * 10 + map[1][5]]) continue;
                            if (!is_prime[map[1][2] * 10000 + map[2][2] * 1000 + map[3][2] * 100 + map[4][2] * 10 + map[5][2]]) continue;
                            if (!is_prime[map[1][3] * 10000 + map[2][3] * 1000 + map[3][3] * 100 + map[4][3] * 10 + map[5][3]]) continue;
                            if (!is_prime[map[1][4] * 10000 + map[2][4] * 1000 + map[3][4] * 100 + map[4][4] * 10 + map[5][4]]) continue;
                            found = true;
                            save_map();
                        }
                    }
                }
            }
        }
    }
    if (!found) printf("NONE\n");
    else{
        sort(res + 1, res + resl + 1);
        for (int i = 1; i <= resl; ++i)
        {
            for (int x = 0; x < 5; ++x)
            {
                for (int y = 0; y < 5; ++y)
                    printf("%c", res[i][x * 5 + y]);
                printf("\n");
            }
            if (i != resl) printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
