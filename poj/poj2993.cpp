#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string str;
char dat[10][10];
void calc(int delta)
{
    cin >> str;
    while ((str.length() > 0) && (str[0] < 'a'))
    {
        dat['8' - str[2]][str[1] - 'a'] = str[0] + delta;
        str.erase(0, 4);
    }
    while (str.length() > 0)
    {
        dat['8' - str[1]][str[0] - 'a'] = 'P' + delta;
        str.erase(0, 3);
    }
}
int main()
{
    for (int i = 0; i <= 1; ++i)
    {
        cin >> str;
        if (str == "White:") calc(0);
        else calc('a' - 'A');
    }
    printf("+---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (!dat[i][j]) dat[i][j] = ((i + j) % 2) ? ':' : '.';
            if ((i + j) % 2) printf("|:%c:", dat[i][j]);
            else printf("|.%c.", dat[i][j]);
        }
        printf("|\n+---+---+---+---+---+---+---+---+\n");
    }
    return 0;
}
