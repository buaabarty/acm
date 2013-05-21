#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node {
    int d;
    node* prev, *next;
    node(int _d) {
        d = _d;
        prev = next = 0;
    }
    node() {}
};
const int INF = 1000000000 + 1111111;
struct delink {
    node* head, *tail;
    int size;
    void init(int n) {
        size = n;
        if (!n) return;
        node* last;
        head = new node(INF);
        tail = head; last = head;
        for (int i = 0; i <= n; ++i) {
            int x;
            if (i < n) scanf("%d", &x);
            else x = INF;
            tail = new node(x);
            tail->prev = last;
            last->next = tail;
            last = tail;
        }
    }
    int gao() {
        node* now = head->next, *tmp, *k;
        int tot = 0, t;
        while (size-- > 1) {
            while (!now->prev || now->prev->d > now->next->d) now = now->next;
            t = now->prev->d + now->d;
            now->next->prev = now->prev->prev;
            now->prev->prev->next = now->next;
            k = now->prev->prev;
            now = new node(t);
            tot += t;
            while (k->d <= t) k = k->prev;
            now->next = k->next;
            now->prev = k;
            k->next->prev = now;
            k->next = now;
            now = now->prev;
        }
        return tot;
    }
}dq;

int main() {
    int n;
    while (scanf("%d", &n), n) {
        dq.init(n);
        printf("%d\n", dq.gao());
    }
    return 0;
}
