/*
ID:ybojan2
LANG:C++
TASK:beads
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    
    int n,max=0;
    string str;
    fin>>n;
    fin>>str;
    str+=str;
    
    char a[701];
    
    for (int i=1;i<=n*2;i++)
        a[i]=str[i-1];

    for (int i=n;i>=1;i--)
    {
        int j,now=0;
        char ca='w',cb='w';
        for (j=n+i-1;j>=i;j--)
        {
            if (a[j]=='w'){
                           now++;
                           continue;
            }
            if (((a[j]=='r')&&(ca=='b'))or((a[j]=='b')&&(ca=='r'))) break;
            ca=a[j];
            now++;
        }
        for (j=i;j<=n+i-1;j++)
        {
            if (a[j]=='w'){
                           now++;
                           continue;
            }
            if (((a[j]=='b')&&(cb=='r'))or((a[j]=='r')&&(cb=='b'))) break;
            cb=a[j];
            now++;
        }
        if (now>n) now=n;
        if (now>max) max=now;
    }
    fout<<max<<endl;
    return 0;
}
