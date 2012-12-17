#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

string get_data(string &str)
{
    int i, l;
    string temp = "";
    for (i = 0, l = str.length(); i < l; ++i)
    {
        if (str[i] == ',') break;
        temp = temp + str[i];
    }
    str.erase(0, i + 1);
    return temp;
}
int ss[26][26];
int same(int x, int y)
{
    for (int i = 0; i < 26; ++i)
        if (ss[x][i] != ss[y][i]) return false;
    return true;
}
void set_string(string str, string &a, string &b, char &c)
{
    int i = 0, l = str.length();
    for (; i < l; ++i)
        if (!isalpha(str[i])) break;
    c = str[i];
    a = str.substr(0, i);
    b = str.substr(i + 1, l - i - 1);
}
bool empty[26];
int main()
{
    string str, a, x, y;
    char c;
    int ca = 0;
    bool done[26];
    while (cin >> str)
    {
        if (str[0] == '#') break;
        memset(ss, 0, sizeof(ss));
        memset(done, 0, sizeof(done));
        memset(empty, 1, sizeof(empty));
        while (str.length() > 0)
        {
            a = get_data(str);
            set_string(a, x, y, c);
            switch (c)
            {
                case '=':
                    for (int i = 0; i < x.length(); ++i)
                    {
                        memset(ss[x[i] - 'A'], 0, sizeof(ss[x[i] - 'A']));
                        for (int j = 0; j < y.length(); ++j) ss[x[i] - 'A'][y[j] - 'a'] = 1;
                    }
                    break;
                case '+':
                    for (int i = 0; i < x.length(); ++i)
                        for (int j = 0; j < y.length(); ++j) ss[x[i] - 'A'][y[j] - 'a'] = 1;
                    break;
                case '-':
                    for (int i = 0; i < x.length(); ++i)
                        for (int j = 0; j < y.length(); ++j) ss[x[i] - 'A'][y[j] - 'a'] = 0;
                    break;
            }
        }
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                if (ss[i][j]) empty[i] = 0;
        printf("%d:", ++ca);
        for (int i = 0; i < 26; ++i)
            if (!done[i])
            {
                if (!empty[i]){
                    for (int j = i; j < 26; ++j)
                        if (same(i, j)) { printf("%c", j + 'A'); done[j] = true;}
                        else if (!empty[j]) break;
                    for (int j = 0; j < 26; ++j)
                        if (ss[i][j]) printf("%c", j + 'a');
                }
            }
        printf("\n");
    }
    return 0;
}
