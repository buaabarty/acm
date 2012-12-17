/*
ID:ybojan2
LANG:C++
TASK:lgame
*/
#include <fstream>
#include <string>
using namespace std;

ifstream cin1("lgame.in");
ifstream cin2("lgame.dict");
ofstream cout("lgame.out");
int main()
{
    string str,dat[40001];
    int maxr=0,num[26],temp[26],tt=0,sc[26]={2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
    memset(num,0,sizeof(num));
    cin1>>str;
    for (int i=0;i<str.length();i++) num[str[i]-'a']++;
    cin2>>str;
    while (str!=".")
    {
          bool okay=true;
          memset(temp,0,sizeof(temp));
          for (int i=0;i<str.length();i++) temp[str[i]-'a']++;
          for (int i=0;i<26;i++) if (temp[i]>num[i]){
              okay=false;break;
          }
          if (okay) dat[++tt]=str;
          cin2>>str;
    }
    dat[++tt]="";
    for (int i=1;i<tt;i++)
        for (int j=i+1;j<=tt;j++)
        {
            memset(temp,0,sizeof(temp));
            for (int k=0;k<dat[i].length();k++)
                temp[dat[i][k]-'a']++;
            for (int k=0;k<dat[j].length();k++)
                temp[dat[j][k]-'a']++;
            bool okay=true;
            int sum=0;
            for (int k=0;k<26;k++)
                if (temp[k]>num[k]){
                                    okay=false;
                                    break;
                                    }
            if (!okay) continue;
            for (int k=0;k<26;k++)
                sum+=sc[k]*temp[k];
            if (sum>maxr) maxr=sum;
        }
    cout<<maxr<<endl;
    for (int i=1;i<tt;i++)
        for (int j=i+1;j<=tt;j++)
        {
            memset(temp,0,sizeof(temp));
            for (int k=0;k<dat[i].length();k++)
                temp[dat[i][k]-'a']++;
            for (int k=0;k<dat[j].length();k++)
                temp[dat[j][k]-'a']++;
            bool okay=true;
            int sum=0;
            for (int k=0;k<26;k++)
                if (temp[k]>num[k]){
                                    okay=false;
                                    break;
                                    }
            if (!okay) continue;
            for (int k=0;k<26;k++)
                sum+=sc[k]*temp[k];
            if (sum==maxr) {
                           cout<<dat[i];
                           if (dat[j]!="") cout<<" "<<dat[j];
                           cout<<endl;
                           }
        }    
    return 0;
}
