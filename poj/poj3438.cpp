#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t;
string str;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        cin >> str;
        char lastopr = str[0];
        int cnt = 1;
        for (int i = 1, l = str.length(); i < l; ++i)
            if (str[i] != lastopr){
                printf("%d%c", cnt, lastopr);
                lastopr = str[i];
                cnt = 1;
            }
            else cnt++;
        printf("%d%c\n", cnt, lastopr);
    }
    return 0;
}
