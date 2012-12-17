/*
ID:ybojan2
LANG:C++
TASK:ratios
*/

#include <iostream>
#include <fstream>

using namespace std;

int gcd(int x,int y)
{
    if (x<y) swap(x,y);
    if (x==0) return y;
    return gcd(y%x,x);
}

int main()
{
    ifstream fin("ratios.in");
    ofstream fout("ratios.out");
    
    int a[4],b[4],c[4],x,y,z,d;
    
    for (int i=0;i<=3;i++)
        fin>>a[i]>>b[i]>>c[i];
    
    for (int i=0;i<100;i++)  
        for (int j=0;j<100;j++)
            for (int k=0;k<100;k++)
                {
                     x=a[1]*i+a[2]*j+a[3]*k;
                     y=b[1]*i+b[2]*j+b[3]*k;
                     z=c[1]*i+c[2]*j+c[3]*k;
                     if (((a[0]!=0)&&(x==0))||((b[0]!=0)&&(y==0))||((c[0]!=0)&&(z==0))) continue;
                     if (((x!=0)&&(x%a[0]!=0))||((y!=0)&&(y%b[0]!=0))||((z!=0)&&(z%c[0]!=0))) continue;
                     if ((x*b[0]==y*a[0])&&(y*c[0]==z*b[0])){
                                                             if (x!=0) d=x/a[0];
                                                             else if (y!=0) d=y/b[0];
                                                             else if (z!=0) d=z/c[0];
                                                             fout<<i<<" "<<j<<" "<<k<<" "<<d<<endl;
                                                             return 0;
                                                             }
                 }
    fout<<"NONE"<<endl;
    return 0;
}
