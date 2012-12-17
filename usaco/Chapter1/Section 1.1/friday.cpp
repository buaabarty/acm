/*
ID:ybojan2
LANG:C++
TASK:friday
*/
#include <iostream>
#include <fstream>
using namespace std;

bool ryun(int x)
{
    return (((x%4==0)&&(x%100!=0))||(x%400==0));
}

int main()
{
    ifstream fin("friday.in");
    ofstream fout("friday.out");
    int n,md[12]={31,31,28,31,30,31,30,31,31,30,31,30},res[8]={0},now=3;
    fin>>n;
    for (int i=1900;i<=1900+n-1;i++)
    {
        if (ryun(i)) md[2]=29;
        else md[2]=28;
        for (int j=0;j<12;j++)
        {
            now+=md[j];
            now=((now-1)%7)+1;
            res[now]++;
        }
    }
    int k[7]={6,7,1,2,3,4,5};
    for (int i=0;i<6;i++)
    {
        fout<<res[k[i]]<<" ";
    }
    fout<<res[5]<<endl;
    return 0;
}
