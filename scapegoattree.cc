#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct node {
    int v;
    node *l;
    node *r;
    node(int val) {
        v = val;
        l = NULL;
        r = NULL;
    }
};

double mylog[100010];

struct ScapeGoatTree {
    int sz, maxsz;
    node *root;
    vector<int> num;
    double a, loga;
    node* build(int l, int r) {
        if (l > r) return NULL;
        node *now = new node(num[(l+r)/2]);
        now->l = build(l, (l+r)/2-1);
        now->r = build((l+r)/2+1, r);
        return now;
    }
    void init(double _a) {
        root = NULL;
        a = _a;
        loga = log(1.0/a);
        sz = maxsz = 0;
    }
    void init(vector<int> x) {
        int n = x.size();
        init(0.7);
        num = x;
        root = build(0, n-1);
        maxsz = sz = n;
    }
    int sizeOf(node *v) {
        if (v == NULL) return 0;
        return sizeOf(v->l) + sizeOf(v->r) + 1;
    }
    node* brother(node* v, node* fa) {
        if (fa->l && fa->l->v == v->v) return fa->r;
        else return fa->l;
    }
    void retravel(node *v) {
        if (!v) return;
        retravel(v->l);
        num.push_back(v->v);
        retravel(v->r);
        delete v;
    }
    node* rebuild(node *r) {
        if (r == NULL) return NULL;
        num.clear();
        retravel(r);
        return build(0, num.size()-1);
    }
    void addSize() {
        ++sz; maxsz = max(maxsz, sz);
    }
    bool insert(int v) {
        if (root == NULL) {
            root = new node(v);
            addSize();
            return true;
        }
        node *now = root;
        vector<node*> l;
        int dp = 1;
        while (true) {
            ++dp;
            l.push_back(now);
            if (now->v == v) return false;
            if (now->v < v) {
                if (!(now->r)) break;
                now = now->r;
            } else {
                if (!(now->l)) break;
                now = now->l;
            }
        }
        if (now->v < v) {
            now->r = new node(v);
            l.push_back(now->r);
        } else {
            now->l = new node(v);
            l.push_back(now->l);
        }
        addSize();
        if (dp > (int)(mylog[sz] / loga)+1) {
            int nowsz = 1, tmpsz, loci = -1;
            node *scapegoat = NULL;
            for (int i = dp-2; i >= 0; --i) {
                nowsz += sizeOf(brother(l[i+1], l[i])) + 1;
                if (!weightbalanced(l[i], nowsz)) {
                    scapegoat = l[i];
                    tmpsz = nowsz;
                    loci = i;
                }
            }
            if (scapegoat == root) root = rebuild(scapegoat);
            else {
                node* fa = l[loci-1];
                if (fa->v > scapegoat->v) fa->l = rebuild(scapegoat);
                else fa->r = rebuild(scapegoat);
            }
        }
        return true;
    }
    node* getmin(node *v) {
        while (v->l) v = v->l;
        return v;
    }
    node* getsucc(int v) {
        node* find = NULL;
        node* now = root;
        while (now) {
            if (now->v < v) now = now->r;
            else {
                if (!find || now->v < find->v) find = now;
                if (find->v != v) now = now->l;
                else return find;
            }
        }
        return find;
    }
    node* getpred(int v) {
        node* find = NULL;
        node* now = root;
        while (now) {
            if (now->v > v) now = now->l;
            else {
                if (!find || now->v > find->v) find = now;
                if (find->v != v) now = now->r;
                else return find;
            }
        }
        return find;
    }
    bool remove(int v) {
        node* now = root;
        node* parent = NULL;
        node* succ = NULL;
        bool isleft = true;
        while (now && now->v != v) {
            parent = now;
            if (v > now->v) {
                now = now->r;
                isleft = false;
            } else {
                now = now->l;
                isleft = true;
            }
        }
        if (!now) return false;
        --sz;
        if (sz == 0) {
            delete root;
            root = NULL;
            return true;
        }
        if (!now->l && !now->r) {}
        else if (!now->l) succ = now->r;
        else if (!now->r) succ = now->l;
        else {
            succ = getmin(now->r);
            if (succ == now->r) succ->l = now->l;
            else {
                succ->l = now->l;
                node *tmp = succ->r;
                succ->r = now->r;
                now->r->l = tmp;
            }
        }
        if (parent == NULL) root = succ;
        else if (isleft) parent->l = succ;
        else parent->r = succ;
        delete now;
        if (1.0*sz < a*maxsz) {
            root = rebuild(root);
            maxsz = sz;
        }
        return true;
    }
    bool weightbalanced(node *v, int sz) {
        return (1.0*sizeOf(v->l)<=a*sz && 1.0*sizeOf(v->r)<=a*sz);
    }
}sgt;
void read(int &x) {
    char c = getchar();
    x = 0;
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
}
int main() {
    for (int i = 1; i <= 100000; ++i) mylog[i] = log(i*1.0);
    int n, m, x;
    while (scanf("%d%d", &n, &m) == 2) {
        int stack[50010], top = 0;
        char str[10];
        sgt.init(0.65);
        sgt.insert(0);
        sgt.insert(n+1);
        while (m--) {
            scanf("%s", str);
            if (str[0] == 'D') {
                read(x);
                stack[++top] = x;
                sgt.insert(x);
            } else if (str[0] == 'Q') {
                read(x);
                node* l = sgt.getpred(x);
                node* r = sgt.getsucc(x);
                printf("%d\n", max(r->v-l->v-1, 0));
            } else {
                sgt.remove(stack[top--]);
            }
        }
    }
    return 0;
}
