#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char str[100000 + 9];
int main() {
    gets(str);
    bool inq = false, inb = false;
    for (int i = 0; str[i]; ++i) {
        if (str[i] == ' ') {
            if (inq) printf("%c", str[i]);
            else if (inb) {
                inb = false;
                printf(">\n");
            }
            continue;
        } else if (str[i] == '"') {
            if (!inq) {
                inq = true;
                printf("<");
            } else {
                inq = false;
                printf(">\n");
            }
        } else {
            if (inq) printf("%c", str[i]);
            else if (!inb) {
                inb = true;
                printf("<%c", str[i]);
            } else printf("%c", str[i]);
        }
    }
    if (inb) printf(">\n");
    return 0;
}
