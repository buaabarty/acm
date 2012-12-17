/*
ID:ybojan2
LANG:C++
TASK:namenum
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char str[6000][15],nn[6000][15];

char ord(char c)
{
    if ((c=='A')||(c=='B')||(c=='C')) return '2';
    if ((c=='D')||(c=='E')||(c=='F')) return '3';
    if ((c=='G')||(c=='H')||(c=='I')) return '4';
    if ((c=='J')||(c=='K')||(c=='L')) return '5';
    if ((c=='M')||(c=='N')||(c=='O')) return '6';
    if ((c=='P')||(c=='R')||(c=='S')) return '7';
    if ((c=='T')||(c=='U')||(c=='V')) return '8';
    if ((c=='W')||(c=='X')||(c=='Y')) return '9';
}

bool same(char a[],char b[])
{
     if (strlen(a)!=strlen(b)) return false;
     for (int i=0;i<strlen(a);i++)
     {
         if (a[i]!=b[i]) return false;
     }
     return true;
}

int main()
{
    ifstream ff("dict.txt");
    int count=0;
    while (!ff.eof())
    {
          count++;
          ff>>str[count];
          for (int j=0;j<strlen(str[count]);j++)
          {
              nn[count][j]=ord(str[count][j]);
          }
    }
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    char check[15];
    fin>>check;
    bool find=false;
    for (int i=1;i<=count;i++)
    {
        if (same(check,nn[i])) 
        {
                               fout<<str[i]<<endl;
                               find=true;
        }
    }
    if (!find) fout<<"NONE"<<endl;
    return 0;
}
