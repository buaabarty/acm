#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
int gcd(int a,int b,int& x,int& y){
	int t,ret;
	if (!b){
		x=1,y=0;
		return a;
	}
	ret=gcd(b,a%b,x,y);
	t=x,x=y,y=t-a/b*y;
	return ret;
}
int iabs(int x)
{
    return (x > 0) ? x : -x;
}
main()
{
    int x, y, m, n, l, a, b, delta;
    while (cin >> x >> y >> m >> n >> l)
    {
        //x %= l, y %= l, m %= l, n %= l;
        int g = gcd(iabs(m - n), l, a, b);
        if (m > n) delta = (y - x + l) % l;
        else delta = (x - y + l) % l;
        //printf("%lld %lld %lld %lld\n", g, delta, a, b);
        if ((delta % g) == 0){
            a = a * delta / g;
            l /= g;
            a = (l + a % l) % l;
            cout << a << endl;
        }
        else cout << "Impossible\n";
    }
}
