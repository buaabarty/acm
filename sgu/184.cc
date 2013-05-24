#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a, b, c, d, e, f;
int main() {
	while (scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f) == 6) {
		printf("%d\n", min(min(a/d, b/e), c/f));
	}
	return 0;
}
