/*
ID:ybojan2
LANG:C++
TASK:humble
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("humble.in");
    ofstream fout("humble.out");
    
    int k,n,p[101],num[100001],s[101];
    fin>>k>>n;
    for (int i=1;i<=k;i++)
        fin>>s[i];
    for (int i=1;i<=k;i++)
        p[i]=-1;
    num[0]=1;
    for (int i=1;i<=n;i++)
    {

        for (;;)
        {
            int min=2147483647,x;
            for (int j=1;j<=k;j++)
                if (num[p[j]+1]*s[j]<min){
                                         min=num[p[j]+1]*s[j];
                                         x=j;
                                         }
            p[x]++;
            num[i]=min;
            if (num[i]!=num[i-1]) break;
        }
    }
    fout<<num[n]<<endl;
    return 0;
}
