#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int getid(char *str)
{
    int n = strlen(str);
    if ((n >= 4) && (str[n - 4] == 'l') && (str[n - 3] == 'i') && (str[n - 2] == 'o') && (str[n - 1] == 's')) return 0;
    else if ((n >= 5) && (str[n - 5] == 'l') && (str[n - 4] == 'i') && (str[n - 3] == 'a') && (str[n - 2] == 'l') && (str[n - 1] == 'a')) return 1;
    else if ((n >= 3) && (str[n - 3] == 'e') && (str[n - 2] == 't') && (str[n - 1] == 'r')) return 2;
    else if ((n >= 4) && (str[n - 4] == 'e') && (str[n - 3] == 't') && (str[n - 2] == 'r') && (str[n - 1] == 'a')) return 3;
    else if ((n >= 6) && (str[n - 6] == 'i') && (str[n - 5] == 'n') && (str[n - 4] == 'i') && (str[n - 3] == 't') && (str[n - 2] == 'i') && (str[n - 1] == 's')) return 4;
    else if ((n >= 6) && (str[n - 6] == 'i') && (str[n - 5] == 'n') && (str[n - 4] == 'i') && (str[n - 3] == 't') && (str[n - 2] == 'e') && (str[n - 1] == 's')) return 5;
    return -1;
}
char str[100010];
int main()
{
    int gender = -1, laststate = -1, id, cnt = 0;
    bool flag = true;
    char c;
    while (scanf("%s", str))
    {
        cnt++;
        id = getid(str);
        //printf("%d\n", id);
        if (id == -1) flag = false;
        if (gender == -1) gender = id & 1;
        else if (gender != (id & 1)) flag = false;
        id >>= 1;
        if (id < laststate) flag = false;
        else if ((id == laststate) && (laststate == 1)) flag = false;
        else if ((laststate < 1) && (id == 2)) flag = false;
        laststate = id;
        scanf("%c", &c);
        if (c == '\n') break;
    }
    //printf("%d\n", cnt);
    if (flag && (laststate >= 1) || ((cnt == 1) && (id != -1))) puts("YES");
    else puts("NO");
    return 0;
}
