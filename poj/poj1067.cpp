#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define d sqrt(5)
int main(){
    int n,m;
    while(~scanf("%d%d", &n, &m))
    {
        if(n < m) swap(n,m);
        printf("%d\n", !(m==(int)((n-m)*(1+d)/2)));
    }
    return 0;
}
