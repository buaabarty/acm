/*
ID:ybojan2
LANG:C++
TASK:fence9
*/

#include <iostream>
#include <fstream>

using namespace std;

int gcd(int x,int y)
{
    if (x>y) swap(x,y);
    if (x==0) return y;
    return gcd(y%x,x);
}

int main()
{
    ifstream fin("fence9.in");
    ofstream fout("fence9.out");
    
    int n,m,p,b=0,s;
    fin>>n>>m>>p;
    s=(m*p)/2;
    b+=gcd(n,m);
    if (n!=p) b+=gcd(abs(n-p),m);
    else b+=m;
    b+=p;
    fout<<s+1-(b/2)<<endl;
    return 0;
}
