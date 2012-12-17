#include <cstdio>
#include <cstring>
using namespace std;
int stack[1000010], n, top;
int mxl, mxc;
int tot, now;
char str[1000010];
void print_stack()
{
    for (int i = 1; i <= top; ++i)
        printf("%d\t", stack[i]);
    puts("");
}
int main()
{
    scanf("%s", str);
    n = strlen(str);
    now = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((!top) || (str[i] == '('))
        {
            stack[++top] = i;
            if (str[i] == '(') tot++;
            else tot--;
            if (tot < 0)
            {
                top = 0;
                tot = 0;
                now = 0;
            }
        }
        else
        {
            tot--;
            if (tot < 0)
            {
                top = 0;
                tot = 0;
                now = 0;
            }
            else
            {
                if (top == 1)
                {
                    if (now + (i - stack[top] + 1) > mxl)
                    {
                        mxl = now + (i - stack[top] + 1);
                        mxc = 1;
                    }
                    else if (now + (i - stack[top] + 1) == mxl)
                    {
                        mxc++;
                    }
                    now += (i - stack[top] + 1);
                }
                else
                {
                    if (i - stack[top] + 1 > mxl)
                    {
                        mxl = (i - stack[top] + 1);
                        mxc = 1;
                    }
                    else if ((i - stack[top] + 1) == mxl)
                    {
                        mxc++;
                    }
                }
                top--;
            }
        }
        //printf("%d(%d) %c :", i, tot, str[i]);print_stack();
    }
    if (mxl) printf("%d %d\n", mxl, mxc);
    else printf("%d %d\n", 0, 1);
    return 0;
}
