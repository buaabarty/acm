#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int stack[100010], n, top = 0;
char now[10];
bool first = true;
int getd(char s[])
{
    if (strcmp(s, "pair") == 0) return 1;
    else if (strcmp(s, "int") == 0) return 2;
    else return 0;
}
char res[50000010];
int len = 0;
int main()
{
    scanf("%d", &n);
    bool flag = true;
    while (~scanf("%s", now))
    {
        if ((top == 0))
        {
            if (first)
            {
                first = false;
                int x = getd(now);
                if (x == 0)
                {
                    flag = false;
                    break;
                }
                stack[++top] = getd(now);
                for (int i = 0; now[i]; ++i)
                    res[len++] = now[i];
            }
            else
            {
                flag = false;
                break;
            }
        }
        else
        {
            int x = getd(now);
            if (x == 0)
            {
                flag = false;
                break;
            }
            if (x == 2)
            {
                if ((top >= 2))
                {
                    if ((stack[top] == 2) && (stack[top - 1] == 1))
                    {
                        top--;
                        stack[top] = 2;
                        res[len++] = ',';
                        res[len++] = 'i';
                        res[len++] = 'n';
                        res[len++] = 't';
                        res[len++] = '>';
                    }
                    else if ((stack[top] == 2) && (stack[top - 1] == 2))
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        stack[++top] = 2;
                        res[len++] = '<';
                        res[len++] = 'i';
                        res[len++] = 'n';
                        res[len++] = 't';
                    }
                    while ((top >= 3) && (stack[top] == 2) && (stack[top - 1] == 2) && (stack[top - 2] == 1))
                    {
                        top -= 2;
                        stack[top] = 2;
                        res[len++] = '>';
                    }
                }
                else
                {
                    if (stack[top] == 1)
                    {
                        stack[++top] = 2;
                        res[len++] = '<';
                        res[len++] = 'i';
                        res[len++] = 'n';
                        res[len++] = 't';
                    }
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
            else
            {
                if (stack[top] == 1)
                {
                    res[len++] = '<';
                    res[len++] = 'p';
                    res[len++] = 'a';
                    res[len++] = 'i';
                    res[len++] = 'r';
                }
                else
                {
                    res[len++] = ',';
                    res[len++] = 'p';
                    res[len++] = 'a';
                    res[len++] = 'i';
                    res[len++] = 'r';
                }
                stack[++top] = 1;
            }
        }
    }
    if (top != 1) flag = false;
    res[len] = '\0';
    if (flag) printf("%s\n", res);
    else printf("Error occurred\n");
    return 0;
}
