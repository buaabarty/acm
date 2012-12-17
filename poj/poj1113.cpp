#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define PI acos(-1)
#define eps 1e-6

using namespace std;
const int MAXN = 50009;

struct Point { // 点结构体
    int x, y;
};

Point p[MAXN], cHull[MAXN], pivot;
double L;
int N;

//AB * AC
int cross(const Point &A, const Point &B, const Point &C) { // 点的叉乘
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

int distsqr(const Point &A, const Point &B) { // 计算两点之间距离的平方
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

double dist(const Point &A, const Point &B)
{
    return sqrt((double)distsqr(A, B));
}

bool cmp(const Point &a, const Point &b) { // 根据极角从小到大排序的比较函数
    int t = cross(pivot, a, b); // pivot是点集中y坐标最小的点
    return t > 0 || (t == 0 && distsqr(pivot, a) < distsqr(pivot, b));
}

void convexHull(Point p[], int n, Point stck[], int &m) {
    int i, k, top;
    if (n < 3) { // 如果点数小于3，直接保存当前的点集
        for (i = 0; i < n; ++i) stck[i] = p[i];
        m = n;
        return;
    }
    for (k = 0, i = 1; i < n; ++i) // 找出y坐标最小的点
        if (p[i].y < p[k].y || (p[i].y == p[k].y && p[i].x < p[k].x))
            k = i;
    pivot = p[k]; // 把pivot放到p[0]的位置
    p[k] = p[0];
    p[0] = pivot;
    sort(p + 1, p + n, cmp); // 根据极角从小到大排序
    stck[0] = p[0];  // 初始时，排序后的点集中第一和第二个元素进栈
    stck[1] = p[1];
    top = 1;
    for (i = 2; i < n; ++i) {
        while (top > 0 && cross(p[i], stck[top], stck[top - 1]) >= 0) // 删除多余的点
            --top;
        stck[++top] = p[i]; // 当前访问的点进栈
    }
    m = top + 1; // 凸包的点数
}

bool input() {
    int i;
    if (scanf("%d%lf", &N, &L) == EOF) return false;
    for (i = 0; i < N; ++i) // 输入点的坐标
        scanf("%d%d", &p[i].x, &p[i].y);
    return true;
}

void solve() {
    int i, j, d, ans = 0, M;
    convexHull(p, N, cHull, M); // 先求凸包
    double s = 0;
    for (i = 0; i < M; ++i)
        s += dist(cHull[i], cHull[(i + 1) % M]);
    s += 2 * PI * L;
    printf("%d\n", (int)(round(s) + eps));
}

int main() {
    while (input()) solve();
    return 0;
}
