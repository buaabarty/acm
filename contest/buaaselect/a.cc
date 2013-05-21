#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cmath>
using namespace std;

char str[1000];

int main() {
    while (scanf("%s", str) == 1) {
        if (strlen(str) == 1) {
            int x = str[0] - '0';
            if (x == 0) puts("1");
            else if (x == 1) puts("5");
            else if (x == 2) puts("25");
            else if (x&1) puts("125");
            else puts("625");
        } else {
            int x = str[strlen(str) - 1] - '0';
            if (x & 1) puts("125");
            else puts("625");
        }

    }
    return 0;
}
