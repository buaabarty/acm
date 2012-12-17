/*
ID:ybojan2
LANG:C++
TASK:gift1
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin ("gift1.in");
    ofstream fout("gift1.out");
    
    string name[10];
    int n,res[10]={0};
    fin>>n;
    for (int i=0;i<n;i++)
    {
        fin>>name[i];
    }


    for (int s=0;s<n;s++)
    {
        string now;
        int tmoney,tpp;
        fin>>now;
        fin>>tmoney>>tpp;
        if (tpp==0) continue;
        int k;
        for (int i=0;i<n;i++)
        {
            if (name[i]==now) 
            {
                              k=i;
                              break;
            }
        }
        res[k]+=(tmoney%tpp);
        res[k]-=tmoney;
        for (int i=0;i<tpp;i++)
        {
            string know;
            fin>>know;
            int t;
            for (int j=0;j<n;j++)
            {
                if (name[j]==know) 
                {
                                   t=j;
                                   break;
                }
            }
            res[t]+=(tmoney/tpp);
        }
    }
    for (int i=0;i<n;i++)
    {
        fout<<name[i]<<" "<<res[i]<<endl;
    }
    return 0;
}
