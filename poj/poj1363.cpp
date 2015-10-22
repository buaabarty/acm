#include <iostream>
#include <cstdio>
using namespace std;
int s[1001], top = 0;
int n, dat[1001];
int main() {
    while (scanf("%d", &n), n) {
        int x;
        while (scanf("%d", &x), x) {
            dat[1] = x;
            int j = 1;
            bool flag = true;
            for (int i = 2; i <= n; ++i) scanf("%d", &dat[i]);
            for (int i = 1; i <= n; ++i) {
                s[++top] = i;
                while (s[top] == dat[j]) {
                    top--;
                    j++;
                }
            }
            while (j <= n) {
                if (s[top] != dat[j]) {
                    flag = false;
                    break;
                }
                top--;
                ++j;
            }
            puts(flag?"Yes":"No");
        }
        puts("");
    }
    return 0;
}
