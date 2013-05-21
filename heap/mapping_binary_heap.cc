#include <iostream>
#include <cstdio>
#include <cstring>
#define PII pair<int, int>
#define CLR(x) memset(x, 0, sizeof(x))
using namespace std;

void print(PII p) {
    printf("%d->%d\n", p.first, p.second);
}


const int maxn = 100009;
struct min_heap {
    int size, d[maxn], p[maxn], v[maxn];
    min_heap() {
        CLR(d); CLR(p); CLR(v); size = 0;
    }
    void myswap(int x, int y) {
        swap(d[x], d[y]); swap(p[d[x]], p[d[y]]);
    }
    void pop(int x) {
        for (int y = x>>1; y; x = y, y >>= 1)
            if (v[d[x]] < v[d[y]]) myswap(x, y);
    }
    void push(int x) {
        for (int y = x<<1; y <= size; x = y, y <<= 1) {
            if (y + 1 <= size && v[d[y + 1]] < v[d[y]]) myswap(y + 1, y);
            if (v[d[y]] < v[d[x]]) myswap(x, y);
        }
    }
    void insert(int loc, int value) {
        d[++size] = loc; p[loc] = size;
        v[loc] = value; pop(size);
    }
    void change(int loc, int value) {
        v[d[p[loc]]] = value; pop(p[loc]); push(p[loc]);
    }
    PII pop() {
        PII ans; myswap(1, size);
        ans = make_pair(d[size], v[d[size]]);
        if (--size) push(1); return ans;
    }
};


int main() {
    min_heap s;
    s.insert(1, 100);
    s.insert(8, 20);
    s.insert(13, 31);
    s.change(1, 10);
    print(s.pop());
    print(s.pop());
    print(s.pop());
    return 0;
}
