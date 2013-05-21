#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int got;

int main() {
    scanf("%d", &n);
    got = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        got |= (1<<x);
    }
    int ans = 0;
    for (int i = 0; i < 256; ++i) {
        int bit = 0;
        if (i >= 100) bit |= (1<<((i/100)%10));
        if (i >= 10) bit |= (1<<(i/10)%10);
        bit |= (1<<(i%10));
        if ((bit|got)!=got) continue;
        for (int j = 0; j < 256; ++j) {
            int bitx = 0;
            if (i >= 100) bitx |= (1<<((i/100)%10));
            if (i >= 10) bitx |= (1<<(i/10)%10);
            bitx |= (1<<(i%10));
            if ((bitx|got)!=got) continue;
            for (int v = 0; v < 256; ++v) {
                int l = 0, num[20];
                if (i >= 100) num[++l] = (i/100)%10;
                if (i >= 10) num[++l] = (i/10)%10;
                num[++l] = i % 10;

                if (j >= 100) num[++l] = (j/100)%10;
                if (j >= 10) num[++l] = (j/10)%10;
                num[++l] = j % 10;

                if (v >= 100) num[++l] = (v/100)%10;
                if (v >= 10) num[++l] = (v/10)%10;
                num[++l] = v % 10;
                int nowg = 0;
                for (int k = 1; k <= l; ++k)
                    nowg |= (1<<num[k]);
                if ((nowg|got)!=got) continue;

                for (int s = 1; s <= 3; ++s) {
                    int totl = l + s;
                    for (int k = l + 1; k <= totl; ++k)
                        num[k] = -1;
                    bool flag = true;
                    for (int k = totl; k >= 1; --k)
                        if (num[k] == -1) num[k] = num[totl - k + 1];
                        else if (num[k] != num[totl - k + 1]) {
                            flag = false;
                            break;
                        }
                    if (s > 1 && !num[l + 1]) flag = false;
                    if (flag) {
                        int x = 0;
                        for (int k = l + 1; k <= totl; ++k)
                            x = x * 10 + num[k];
                        int nowb = 0;
                        for (int k = 1; k <= totl; ++k)
                            nowb |= (1<<num[k]);
                        if (nowb==got && x>=0 && x<=255) {
                            //for (int k = 1; k <= totl; ++k)
                            //    printf("%d", num[k]); puts("");
                            ++ans;
                            //printf("%d.%d.%d.%d\n", i, j, v, x);
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    if (!ans) return 0;
    for (int i = 0; i < 256; ++i) {
        int bit = 0;
        if (i >= 100) bit |= (1<<((i/100)%10));
        if (i >= 10) bit |= (1<<(i/10)%10);
        bit |= (1<<(i%10));
        if ((bit|got)!=got) continue;
        for (int j = 0; j < 256; ++j) {
            int bitx = 0;
            if (i >= 100) bitx |= (1<<((i/100)%10));
            if (i >= 10) bitx |= (1<<(i/10)%10);
            bitx |= (1<<(i%10));
            if ((bitx|got)!=got) continue;
            for (int v = 0; v < 256; ++v) {
                int l = 0, num[20];
                if (i >= 100) num[++l] = (i/100)%10;
                if (i >= 10) num[++l] = (i/10)%10;
                num[++l] = i % 10;

                if (j >= 100) num[++l] = (j/100)%10;
                if (j >= 10) num[++l] = (j/10)%10;
                num[++l] = j % 10;

                if (v >= 100) num[++l] = (v/100)%10;
                if (v >= 10) num[++l] = (v/10)%10;
                num[++l] = v % 10;
                int nowg = 0;
                for (int k = 1; k <= l; ++k)
                    nowg |= (1<<num[k]);
                if ((nowg|got)!=got) continue;

                for (int s = 1; s <= 3; ++s) {
                    int totl = l + s;
                    for (int k = l + 1; k <= totl; ++k)
                        num[k] = -1;
                    bool flag = true;
                    for (int k = totl; k >= 1; --k)
                        if (num[k] == -1) num[k] = num[totl - k + 1];
                        else if (num[k] != num[totl - k + 1]) {
                            flag = false;
                            break;
                        }
                    if (s > 1 && !num[l + 1]) flag = false;
                    if (flag) {
                        int x = 0;
                        for (int k = l + 1; k <= totl; ++k)
                            x = x * 10 + num[k];
                        int nowb = 0;
                        for (int k = 1; k <= totl; ++k)
                            nowb |= (1<<num[k]);
                        if (nowb==got && x>=0 && x<=255) {
                            //for (int k = 1; k <= totl; ++k)
                            //    printf("%d", num[k]); puts("");
                            //++ans;
                            printf("%d.%d.%d.%d\n", i, j, v, x);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
