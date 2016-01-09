#include <iostream>
#include <cstdio>
using namespace std;

class DisjointSetUnion {
private:
    int *father;
public:
    DisjointSetUnion(int size) {
        father = new int[size];
        for (int i = 0; i < size; ++i) {
            father[i] = i;
        }
    }
    ~DisjointSetUnion() {
        delete[] father;
    }
    int ancestor(int node) {
        if (father[node] != node) {
            father[node] = ancestor(father[node]);
        }
        return father[node];
    }
    bool join(int node1, int node2) {
        int ancestor1 = ancestor(node1);
        int ancestor2 = ancestor(node2);
        if (ancestor1 != ancestor2) {
            father[ancestor1] = ancestor2;
            return true;
        }
        return false;
    }
};

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m), n + m) {
        DisjointSetUnion dsu(n);
        int ans = n;
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            --x; --y;
            if (dsu.join(x, y)) {
                --ans;
            }
        }
        static int ca = 1;
        printf("Case %d: %d\n", ca++, ans);
    }

    return 0;
}
