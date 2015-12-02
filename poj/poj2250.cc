#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

template <class T>
class myarray {
private:
    int lo, hi;
    T * const data;
    bool allocated;
    myarray(int l, int h, T *dt)
        : lo(l), hi(h), data(dt), allocated(false) {}
public:
    myarray(int l, int h)
        : lo(l), hi(h), data(new T[hi-lo+1]), allocated(true) {}
    myarray(int l, const std::vector<T> &v)
        : lo(l), hi(l+v.size()-1), data(new T[hi-lo+1]), allocated(true) {
        T *p = data;
        for (int i = 0; i < v.size(); ++i) {
            *p++ = v[i];
        }
    }
    const T& operator[](int i) const {
        return data[i-lo];
    }
    T& operator[](int i) {
        return data[i-lo];
    }
    myarray splice(int l, int r) const {
        return myarray(1, r-l+1, data+l-lo);
    }
    int size() const {
        return hi-lo+1;
    }
    ~myarray() {
        if (allocated) {
            delete [] data;
        }
    }
};

struct snake {
    int x, y, u, v, d;
    snake(int _x, int _y, int _u, int _v, int _d)
        : x(_x), y(_y), u(_u), v(_v), d(_d) {  }
    snake() {
    }
};

snake middle_snake(const myarray<string> &a, const myarray<string> &b) {
    int n = a.size();
    int m = b.size();
    int limd = (m + n + 1) >> 1;
    int delta = n - m;
    bool odd = delta & 1;
    myarray<int> vf(-n-m, n+m);
    myarray<int> vr(delta+(-n-m), delta+(n+m));
    vf[1] = 0;
    vr[delta - 1] = n;
    for (int d = 0; d <= limd; ++d) {
        for (int k = -d, x, y; k <= d; k += 2) {
            if (k == -d || (k != d && vf[k-1] < vf[k+1])) {
                x = vf[k+1];
            } else {
                x = vf[k-1] + 1;
            }
            y = x - k;
            while (x < n && y < m && a[x+1] == b[y+1]) ++x, ++y;
            vf[k] = x;

            if (odd && delta-(d-1) <= k && k <= delta+(d-1)) {
                const int u = vr[k], v = u - k;
                if (u+v >= d && x + y <= n + m - (d - 1) && x >= u) {
                    return snake(u, v, x, y, 2 * d - 1);
                }
            }
        }

        for (int k = -d, u, v; k <= d; k += 2) {
            if (k == d || (k != -d && vr[delta+k-1] < vr[delta+k+1])) {
                u = vr[delta+k-1];
            } else {
                u = vr[delta+k+1] - 1;
            }
            v = u-(delta+k);
            while (u > 0 && v > 0 && a[u] == b[v]) {
                --u, --v;
            }
            vr[delta+k] = u;
            if (!odd && -d<=k+delta && k+delta<=d) {
                const int x = vf[delta+k], y = x-(delta+k);
                if (u+v>=d && x+y<=n+m-d && x >= u) {
                    return snake(u, v, x, y, 2*d);
                }
            }
        }
    }
    return snake();
}


void lcs(vector<pair<int, int> > &out, const myarray<string> &a, int aoff, const myarray<string> &b, int boff) {
    const int n = a.size(), m = b.size();
    if (n && m) {
        snake s(middle_snake(a, b));
        if (s.d > 1) {
            lcs(out, a.splice(1, s.x), aoff, b.splice(1, s.y), boff);
            for (int i = s.x+1; i <= s.u; ++i) {
                out.push_back(make_pair(aoff+i-1, boff-s.x+s.y+i-1));
            }
            lcs(out, a.splice(s.u+1, n), aoff+s.u, b.splice(s.v+1, m), boff+s.v);
        } else if (n < m) {
            for (int i = 1, j = 1; i <= n && j <= m; ++i, ++j) {
                if (a[i] != b[j]) ++j;
                out.push_back(make_pair(aoff+i-1, boff+j-1));
            }
        } else {
            for (int i = 1, j = 1; i <= n && j <= m; ++i, ++j) {
                if (a[i] != b[j]) ++i;
                out.push_back(make_pair(aoff+i-1, boff+j-1));
            }
        }
    }
}

int main() {
    string buf;
    while (cin >> buf) {
        vector<string> va, vb;
        while (buf != "#") {
            va.push_back(buf);
            cin >> buf;
        }
        cin >> buf;
        while (buf != "#") {
            vb.push_back(buf);
            cin >> buf;
        }
        myarray<string> a(1, va), b(1, vb);

        vector<pair<int, int> > sol;
        lcs(sol, a, 0, b, 0);

        for (int i = 0; i < sol.size(); ++i) {
            cout << va[sol[i].first];
            if (i != sol.size() - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }
    return 0;
}
