#include <iostream>
int main() {
    int n;
    scanf("%d", &n);
    int **a;
    a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
    }
    return 0;
}
