/*
ID:ybojan2
LANG:C++
TASK:palsquare
*/

#include <iostream>
#include <fstream>

using namespace std;

char nn[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

int main()
{
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");
    int n;
    fin>>n;
    for (int i=1;i<=300;i++)
    {
        int tmp=i*i,len=0,num[100];
        for (;tmp>0;)
        {
            len++;
            num[len]=tmp%n;
            tmp/=n;
        }
        bool pal=true;
        for (int j=1;j<=len;j++)
        {
            if (num[j]!=num[len-j+1]) 
            {
                                      pal=false;
                                      break;
                                      }
        }
        if (pal) 
        {
                 int tmp=i,lk=0,k[100];
                 for (;tmp>0;)
                 {
                     lk++;
                     k[lk]=tmp%n;
                     tmp/=n;
                 }
                 for (int j=lk;j>=1;j--)
                 {
                     fout<<nn[k[j]];
                 }
                 fout<<" ";
                 for (int j=len;j>=1;j--)
                 {
                     fout<<nn[num[j]];
                 }
                 fout<<endl;
        }
    }
    return 0;
}
