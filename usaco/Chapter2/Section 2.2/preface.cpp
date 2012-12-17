/*
ID:ybojan2
LANG:C++
TASK:preface
*/

#include <iostream>
#include <fstream>

using namespace std;

int od(char c)
{
    switch (c)
    {
         case 'I':return 0;
         case 'V':return 1;
         case 'X':return 2;
         case 'L':return 3;
         case 'C':return 4;
         case 'D':return 5;
         case 'M':return 6;
    }
}

int main()
{
    ifstream fin("preface.in");
    ofstream fout("preface.out");
    
    char g[10][5]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
    char s[10][5]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    char b[10][5]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    char q[4][5]={"","M","MM","MMM"};
    
    int n,num[7];
    fin>>n;
    memset(num,0,sizeof(num));
    for (int i=1;i<=n;i++)
    {
        int x=i;
        for (int j=0;j<strlen(g[x%10]);j++)
        {
            num[od(g[x%10][j])]++;
        }
        x/=10;
        for (int j=0;j<strlen(s[x%10]);j++)
        {
            num[od(s[x%10][j])]++;
        }
        x/=10;
        for (int j=0;j<strlen(b[x%10]);j++)
        {
            num[od(b[x%10][j])]++;
        }
        x/=10;
        for (int j=0;j<strlen(q[x%10]);j++)
        {
            num[od(q[x%10][j])]++;
        }        
    }
    if (num[0]!=0) fout<<"I "<<num[0]<<endl;
    if (num[1]!=0) fout<<"V "<<num[1]<<endl;
    if (num[2]!=0) fout<<"X "<<num[2]<<endl;
    if (num[3]!=0) fout<<"L "<<num[3]<<endl;
    if (num[4]!=0) fout<<"C "<<num[4]<<endl;
    if (num[5]!=0) fout<<"D "<<num[5]<<endl;
    if (num[6]!=0) fout<<"M "<<num[6]<<endl;
    return 0;
}
