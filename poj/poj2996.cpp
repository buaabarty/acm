#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[100], dat[8][8];
bool flag = false;
void loop(int i, char c1, char c2)
{
    for (int j = 0; j < 8; ++j)
        if (dat[i][j] == c1)
        {
            if (flag) printf(",");
            flag = true;
            if (c2 != '\0') printf("%c", c2);
            printf("%c%c", j + 'a', 8 - i + '0');
        }
}
void print(char c1, char c2, bool dir)
{
    if (dir) for (int i = 7; i >= 0; --i) loop(i, c1, c2);
    else for (int i = 0; i < 8; ++i) loop(i, c1, c2);
}
void print_all(char* s, char c1, char c2, char c3, char c4, char c5, char c6, bool dir)
{
    flag = false;
    printf("%s: ", s);
    print(c1, 'K', dir);
    print(c2, 'Q', dir);
    print(c3, 'R', dir);
    print(c4, 'B', dir);
    print(c5, 'N', dir);
    print(c6, '\0', dir);
    printf("\n");
}
int main()
{
    scanf("%s", str);
    for (int i = 0; i < 8; ++i)
    {
        scanf("%s", str);
        for (int j = 0; j < 8; ++j)
            dat[i][j] = str[j * 4 + 2];
        scanf("%s", str);
    }
    print_all("White", 'K', 'Q', 'R', 'B', 'N', 'P', true);
    print_all("Black", 'k', 'q', 'r', 'b', 'n', 'p', false);
    return 0;
}
