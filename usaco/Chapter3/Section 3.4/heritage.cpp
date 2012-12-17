/*
ID:ybojan2
LANG:C++
TASK:heritage
*/

#include <iostream>
#include <fstream>

using namespace std;

    char str[30],a[27],b[27];
    ifstream fin("heritage.in");
    ofstream fout("heritage.out");
    
void go(int s1,int s2,int len)
{
     if (len<=0) return;
     if (len==1){
                 fout<<a[s1];
                 return ;
                 }
     int i;
     for (i=s1;i<=s1+len-1;i++)
         if (b[s2]==a[i]) break;
     go(s1,s2+1,i-s1);
     go(i+1,s2+i-s1+1,s1+len-1-i);
     fout<<b[s2];
}

int main()
{
    fin>>str;
    int l=strlen(str);
    l=strlen(str);
    for (int i=0;i<l;i++)
        a[i+1]=str[i];
    fin>>str;
    for (int i=0;i<l;i++)
        b[i+1]=str[i];
    go(1,1,l);
    fout<<endl;
    return 0;
}
