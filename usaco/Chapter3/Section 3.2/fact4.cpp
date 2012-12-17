/*
ID:ybojan2
LANG:C++
TASK:fact4
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("fact4.in");
    ofstream fout("fact4.out");
    
    int n,s2=0,s5=0,res=1;
    fin>>n;
    for (int i=2;i<=n;i++)
    {
        int tmp=i;
        while (tmp%2==0) 
        {
              s2++;
              tmp/=2;
        }
        while (tmp%5==0)
        {
              s5++;
              tmp/=5;
        }
        while ((s2>0)&&(s5>0))
        {
              s2--;
              s5--;
        }
        res*=tmp;
        res%=10;   
    }
    for (int i=1;i<=s2;i++)
    {
        res*=2;
        res%=10;
    }
    for (int i=1;i<=s5;i++)
    {
        res*=5;
        res%=10;
    }
    fout<<res<<endl;
    return 0;
}
