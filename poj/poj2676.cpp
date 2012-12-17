#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
char str[10];
int dat[9][9], a[9], b[9], d[3][3];
int i, l, j;
int find_next(int k)
{
    while (k < 81){
        if (dat[k / 9][k % 9]) k++;
        else return k;
    }
    return -1;
}
void print()
{
    for (int i = 0; i < 9; ++i, printf("\n"))
        for (int j = 0; j < 9; ++j)
            printf("%d", dat[i][j]);
}
bool dfs(int now)
{
//    print();
//    printf("%d\n", now);
    int nowx = now / 9, nowy = now % 9;
    for (int i = 1; i <= 9; ++i)
        if ((((1 << i) & a[nowx]) == 0) && (((1 << i) & b[nowy]) == 0) && (((1 << i) & d[nowx / 3][nowy / 3]) == 0)){
            dat[nowx][nowy] = i;
            d[nowx / 3][nowy / 3] |= (1 << i);
            a[nowx] |= (1 << i);
            b[nowy] |= (1 << i);
            if (find_next(now) > 0)
            {
                if (dfs(find_next(now))) return true;
            }
            else{
                print();
                return true;
            }
            dat[nowx][nowy]= 0;
            d[nowx / 3][nowy / 3] -= (1 << i);
            a[nowx] -= (1 << i);
            b[nowy] -= (1 << i);
        }
    return false;
}
int main()
{
    int ca;
    int x, y;

    scanf("%d", &ca);
    while (ca--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(d, 0, sizeof(d));
        for (i = 0; i < 9; ++i)
        {
            scanf("%s", str);
            l = strlen(str);
            for (j = 0; j < l; ++j)
            {
                dat[i][j] = str[j] - '0';
                if (dat[i][j])
                {
                    a[i] |= (1 << dat[i][j]);
                    b[j] |= (1 << dat[i][j]);
                    d[i / 3][j / 3] |= (1 << dat[i][j]);
                }
            }
        }
        if (find_next(0) >= 0){
            dfs(find_next(0));
        }
        else print();
    }
    return 0;
}
