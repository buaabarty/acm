#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
#define zero(x) ((x>0? x:-x)<1e-15)

int const MAXN = 100;

double a[MAXN][MAXN];
double b[MAXN][MAXN];

int g[53][53];
int n,k;

double det(double a[MAXN][MAXN],int n) {
    int i, j, k, sign = 0;
    double ret = 1, t;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            b[i][j] = a[i][j];
    for (i = 0; i < n; i++) {
        if (zero(b[i][i])) {
            for (j = i + 1; j < n; j++)
                if (!zero(b[j][i]))
                    break;
            if (j == n)
                return 0;
            for (k = i; k < n; k++)
                t = b[i][k], b[i][k] = b[j][k], b[j][k] = t;
            sign++;
        }
        ret *= b[i][i];
        for (k = i + 1; k < n; k++)
            b[i][k] /= b[i][i];
        for (j = i + 1; j < n; j++)
            for (k = i + 1; k < n; k++)
                b[j][k] -= b[j][i] * b[i][k];
    }
    if (sign & 1)
        ret = -ret;
    return ret;
}
void build(){
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i/k!=j/k) g[i][j] = 1;
}
int main() {
    int cas;
    //scanf("%d", &cas);
    while (true) {
        scanf("%d%d", &n, &k);
        n *= k;
        memset(g,0,sizeof(g));
        build();
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++) {
            int d=0;
            for (int j=0;j<n;j++)
                if (g[i][j])
                    d++;
            a[i][i]=d;
        }
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (g[i][j])
                    a[i][j]=-1;
        double ans = det(a, n-1);
        printf("%.0f\n", ans);
        long long dat = (long long)(ans/pow(n/k, n/k-2)+1e-6);
        /*cout << dat << endl;
        for (long long i = 2; i <= dat; ++i)
            if (dat % i == 0) {
                printf("%d^", (int)i);
                int cnt = 0;
                while (dat%i==0) {
                    ++cnt;
                    dat /= i;
                }
                printf("%d\t", cnt);
            }
        printf("\n");*/
    }
    return 0;
}
