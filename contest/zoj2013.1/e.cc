#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cctype>

#include <algorithm>
#include <map>

#define pb push_back

using namespace std;

typedef long long LL;

string a, b, c;
map<string, int> name;
string saved[510];

struct data {
    int a, b;
    data(string s) {
        int i = 0;
        a = 0, b = 0;
        while (isdigit(s[i])) {
            a = a * 10 + (s[i++]-48);
        }
        i++;
        while (isdigit(s[i]) && i < s.length()) {
            b = b * 10 + (s[i++]-48);
        }
    }
    data(){}
};

int res[510][510];
int n, m, tot;

int getid(string s) {
    if (name.find(s) == name.end()) {
        saved[++tot] = s;
        return (name[s] = tot);
    } else return name[s];
}

struct Data {
    int id, score, goal, goaldiff, rank, samescore, samegoaldiff, samegoal;
}p[510];

bool cmp(const Data &a, const Data &b) {
    if (a.score != b.score) return a.score > b.score;
    if (a.samescore != b.samescore) return a.samescore > b.samescore;
    if (a.samegoaldiff != b.samegoaldiff) return a.samegoaldiff > b.samegoaldiff;
    if (a.samegoal != b.samegoal) return a.samegoal > b.samegoal;
    if (a.goal != b.goal) return a.goal > b.goal;
    if (a.rank != b.rank) return a.rank < b.rank;
}

int main() {
    int ca = 0;
    while (scanf("%d", &n) == 1) {
        tot = 0;
        name.clear();
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= n; ++i) p[i].id = i;
        for (int i = 1; i <= (n-1)*n/2; ++i) {
            cin >> a >> b >> c;
            data d(b);
            int x = getid(a), y = getid(c);
            res[x][y] = d.a;
            res[y][x] = d.b;
            if (d.a > d.b) p[x].score += 3;
            else if (d.a < d.b) p[y].score += 3;
            else p[x].score += 1, p[y].score += 1;
            p[x].goal += d.a;
            p[y].goal += d.b;
            p[x].goaldiff += d.a - d.b;
            p[y].goaldiff += d.b - d.a;
        }
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (p[i].score == p[j].score) {
                    if (res[i][j] > res[j][i]) p[i].samescore += 3;
                    else if (res[i][j] < res[j][i]) p[j].samescore += 3;
                    else p[i].samescore += 1, p[j].samescore += 1;
                    p[i].samegoal += res[i][j], p[j].samegoal += res[j][i];
                    p[i].samegoaldiff += res[i][j];
                    p[j].samegoaldiff += res[j][i];
                }
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) {
            cin >> a;
            if (name.find(a) != name.end()) p[name[a]].rank = i;
        }
        sort(p+1, p+n+1, cmp);
        if (ca++) cout << endl;
        for (int i = 1; i <= n; ++i)
            cout << saved[p[i].id] << endl;
    }
    return 0;
}
