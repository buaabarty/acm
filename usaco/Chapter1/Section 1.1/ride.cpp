/*
ID:ybojan2
LANG:C++
TASK:ride
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("ride.in");
    ofstream fout("ride.out");
    char a[7],b[7];
    int sa=1,sb=1;
    fin>>a;
    fin>>b;
    for (int i=0;a[i]!='\0';i++)
    {
        sa*=(int(a[i]-'A')+1);
        sa%=47;
    }
    for (int i=0;b[i]!='\0';i++)
    {
        sb*=(int(b[i]-'A')+1);
        sb%=47;
    }
    (sa==sb)?fout<<"GO":fout<<"STAY";
    fout<<endl;
    return 0;
}
