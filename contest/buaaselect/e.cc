#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct node {
    char c;
    node* prev, next;
    node(char _c) {
        c = _c;
        prev = 0;
        next = 0;
    }
    node() {}
};

struct delink {
    node *head, *tail, *now;
    bool empty;
    void init() {
        head = 0;
        tail = 0;
        empty = true;
    }
    void
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {

    }
    return 0;
}
