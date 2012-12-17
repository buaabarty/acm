#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#define MAXN 65536
using namespace std;
string str[MAXN];
int main()
{
    int l = 0, ca = 0;
    while (cin >> str[++l])
    {
        while (str[l] != "9")
        {
            cin >> str[++l];
        }
        l--;
        sort(str + 1, str + l + 1);
        bool res = true;
        for (int i = 1; i < l; ++i)
        {
            int len = str[i].length();
            bool flag = true;
            for (int j = 0; j < len; ++j)
                if (str[i][j] != str[i + 1][j]){
                    flag = false;
                    break;
                }
            if (flag){
                res = false;
                break;
            }
        }
        if (res) printf("Set %d is immediately decodable\n", ++ca);
        else printf("Set %d is not immediately decodable\n", ++ca);
        l = 0;
    }
    return 0;
}
