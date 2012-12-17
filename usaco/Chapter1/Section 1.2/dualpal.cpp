/*
ID:ybojan2
LANG:C++
TASK:dualpal
*/
#include <iostream>
#include <fstream>

using namespace std;

bool huiwen(int n,int x)
{
    int len=0,num[50]={0};
    for (;n>0;)
    {
        len++;
        num[len]=n%x;
        n/=x;
    }
    for (int i=1;i<=len;i++)
    {
        if (num[i]!=num[len-i+1]) return false;
    }
    return true;
}

int main()
{
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int n,s;
    fin>>n>>s;
    for (int i=s+1;n>0;i++)
    {
        int count=0;
        for (int j=2;j<=10;j++)
        {
            if (huiwen(i,j)) count++;
        }
        if (count>=2) 
        {
                      fout<<i<<endl;
                      n--;
                      }
    }
    return 0;
}
