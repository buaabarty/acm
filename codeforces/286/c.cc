#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef long long lint;
const int N = 1000000 + 9;
int n, m, a[N], b[N], v[N], stack[N], top, x;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 1, x; i <= m; i++) {
	    scanf("%d",&x);
	    v[x] = 1;
	}
	for (int i = n; i >= 1; i--)
        if(v[i]) {
            stack[++top] = a[i];
            b[i] = -1;
        }
        else {
            if (stack[top] == a[i]) {
                b[i] = 1;
                --top;
            }
            else {
                stack[++top] = a[i], b[i] = -1;
            }
	if(top) printf("NO\n");
	else {
		printf("YES\n");
		for(int i = 1; i <= n; i++)
			printf("%d ", a[i] * b[i]);
	}
	return 0;
}
