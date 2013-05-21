#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
char* getrandstr() {
    int len = 12;
    char* temp = new char[len+1];
    for (int i = 0; i < len; ++i) {
        int x = rand()%26;
        temp[i] = x+'a';
    }
    temp[len] = '\0';
    return temp;
}
int main() {
    srand(0);
    int T, n, h;
    scanf("%d%d%d", &T, &n, &h);
    while (T--) {
        for (int i = 1; i <= n; ++i)
            printf("%s\n", getrandstr());
    }
    return 0;
}
