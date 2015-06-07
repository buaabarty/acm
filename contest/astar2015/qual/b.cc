#include <iostream>
#include <cstring>
using namespace std;
char str[100000 + 9];
char res[100000 + 9];
int main() {
    int T, k;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        gets(str); gets(str);
        scanf("%d", &k);
        int len = strlen(str);
        int first = len % k;
        for (int i = 0; i < first; ++i) {
            for (int j = 0; j < (len / k + 1); ++j)
                res[i + j * k] = str[i * (len / k + 1) + j];
        }
        int st = first * (len / k + 1);
        for (int i = first; i < k; ++i) {
            for (int j = 0; j < len / k; ++j)
                res[i + j * k] = str[st + (i - first) * (len / k) + j];
        }
        res[len] = '\0';
        printf("Case #%d:\n", ca);
        puts(res);
    }
    return 0;
}
