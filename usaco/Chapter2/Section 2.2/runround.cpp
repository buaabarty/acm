/*
ID:ybojan2
LANG:C++
TASK:runround
*/

#include <iostream>
#include <fstream>

using namespace std;

int l=0,num[10];

bool same()
{
     int use[10];
     memset(use,false,sizeof(use));
     for (int i=1;i<=l;i++)
     {
         if (!use[num[i]]) use[num[i]]=true;
         else return true;
     } 
     return false;
}

void add1()
{
     int tmp[10],i;
     memset(tmp,0,sizeof(tmp));
     for (i=1;i<=l;i++)
         tmp[i]=num[l-i+1];
     tmp[1]++;
     i=1;
     while (tmp[i]>=10)
     {
           tmp[i+1]++;
           tmp[i]%=10;
           i++;
     }
     if (i>l) l=i;
     for (i=1;i<=l;i++)
         num[i]=tmp[l-i+1];
}

void addup()
{
     add1();
     while (same()) add1();
}

int main()
{
    ifstream fin("runround.in");
    ofstream fout("runround.out");
    
    char c;
    fin>>c;
    for (;!fin.eof();)
    {
        l++;
        num[l]=c-'0';
        fin>>c;
    }
    addup();
    for (;;)
    {
        bool use[10];
        int cnt=1;
        for (int i=1;i<=l;i++) use[i]=false;
        int x=1;
        use[1]=true;
        for (;;)
        {
            x=x+num[x];
            while (x>l) x-=l;
            if (use[x]) break;
            use[x]=true;
            cnt++;
        }
        if ((x==1)&&(cnt==l))
        {
                 for (int i=1;i<=l;i++)
                     fout<<num[i];
                 fout<<endl;
                 return 0;
        }
        addup();
    }
    return 0;
}
