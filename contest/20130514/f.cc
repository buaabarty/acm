#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int gao(char c, int x, int y) {
    if (c == '+') return (x|y);
    else if (c == '-') return (x^(x&y));
    else return (x&y);
}
void printn(int a[], int l) {
    printf("NUM:\t");
    for (int i = 1; i <= l; ++i)
        printf("%d%c", a[i], " \n"[i==l]);
}
void printc(char a[], int l) {
    printf("CHAR:\t");
    for (int i = 1; i <= l; ++i)
        printf("%c%c", a[i], " \n"[i==l]);
}
char str[1000];
int d[1000];
char opr[1000];
int dtop, otop;
int main() {
    while (scanf("%s", str) == 1) {
        int i = 0;
        memset(d, 0, sizeof(d));
        memset(opr, 0, sizeof(opr));
        dtop = otop = 0;
        while (str[i]) {
            //cout << "NOW:  " << str[i] << endl;
            if (str[i] == '{') {
                ++i;
                int now = 0;
                while (str[i] != '}') now |= (1<<(str[i++]-'A'));
                d[++dtop] = now;
            } else if (str[i] == '(') {
                opr[++otop] = str[i];
            } else if (str[i] == ')') {
                while (otop && opr[otop] != '(') {
                    d[dtop-1] = gao(opr[otop--], d[dtop-1], d[dtop]);
                    dtop--;
                }
                otop--;
            } else if (str[i] == '*') {
                while (otop && opr[otop] != '(' && opr[otop] != '+' && opr[otop] != '-') {
                    d[dtop-1] = gao(opr[otop--], d[dtop-1], d[dtop]);
                    dtop--;
                }
                opr[++otop] = str[i];
            } else if (str[i] == '+' || str[i] == '-') {
                while (otop && opr[otop] != '(') {
                    d[dtop-1] = gao(opr[otop--], d[dtop-1], d[dtop]);
                    dtop--;
                }
                opr[++otop] = str[i];
            }
            //printn(d, dtop);
            //printc(opr, otop);
            //printf("\n\n");
            ++i;
        }
        while (otop) {
            d[dtop-1] = gao(opr[otop--], d[dtop-1], d[dtop]);
            dtop--;
        }
        printf("{");
        for (int i = 0; i < 26; ++i)
            if ((d[1]>>i)&1) printf("%c", 'A'+i);
        printf("}\n");
    }
    return 0;
}
