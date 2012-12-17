#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct hash {
    bool use[26];
    int cnt;
    hash() {
        memset(use, 0, sizeof(use));
        cnt = 0;
    }
    int gethash(int x) {
        if (use[x]) return use[x];
        else return (use[x] = ++cnt);
    }
}h;
bool toint(char *str, int &x) {
    x = 0;
    for (int i = 0; str[i]; ++i)
        if (str[i]>='0' && str[i]<='9') {
            x = x * 10 + str[i]-'0';
        } else return false;
    return true;
}
void error(int ca, int type) {
    printf("0\n");
    switch (type) {
        case 0: printf("step error"); break;
        case 1: printf("format error"); break;
        case 2: printf("movement error"); break;
        case 3: printf("result error"); break;
    }
    printf(" on case %d.\n", ca);
}
const int move[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int hashstr(char *str) {
    if (!strcmp(str, "Right")) return 0;
    if (!strcmp(str, "Left")) return 1;
    if (!strcmp(str, "Up")) return 2;
    if (!strcmp(str, "Down")) return 3;
    return -1;
}
bool canfall(int dat[][20], int n, int m) {
    int ans[20][20];
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            ans[i][j] = dat[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            int l = j, r = j;
            while (dat[i][l] == dat[i][j]) --l;
            ++l;
            while (dat[i][r] == dat[i][j]) ++r;
            --r;
            if (r-l+1 >= 3) ans[i][j] = 0;
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dat[i][j] = ans[i][j];
}
void fall(int dat[][20], int n, int m) {
    for (int j = 1; j <= m; ++j) {
        int i = 1, pt = 1;
        while (pt <= n) {
            while (!dat[pt][j] && pt<=n) ++pt;
            if (pt <= n) dat[i++][j] = dat[pt][j];
        }
    }
}
bool all0(int dat[][20], int n, int m) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (dat[i][j]) return false;
    return true;
}
int main(int argc, char *argv[]) {
    char input_file[100];
	char stdout_file[100];
	char prgout_file[100];
	char temp[100], buff[100];
	strcpy(input_file, argv[1]);
	strcpy(stdout_file, argv[2]);
	strcpy(prgout_file, argv[3]);
	FILE *fin, *fstdout, *fprgout;
	fin = fopen(input_file, "r");
	fstdout = fopen(stdout_file, "r");
	fprgout = fopen(prgout_file, "r");
	int T, n, m;
	int dat[20][20];
	/*
        步数不对
        移动非法
        移动后未完成
	*/
	memset(dat, 0, sizeof(dat));
	fscanf(fin, "%d", &T);
	for (int ca = 1; ca <= T; ++ca) {
	    scanf("%d%d", &n, &m);
	    char str[12];
	    for (int i = n; i >= 1; --i) {
	        scanf("%s", str);
	        for (int j = 1; j <= m; ++j)
                dat[i][j] = h.gethash(str[j-1]-'A');
	    }
	    int stdmove, prgmove;
	    fscanf(fstdout, "%d", &stdmove);
	    for (int j = 0; j <= stdmove; ++j) {
	        fgets(temp, 1000, fstdout);
	    }
	    fscanf(fprgout, "%s", buff);
	    if (!toint(buff, prgmove)) {
	        error(ca, 1);
	        return 0;
	    }
	    if (stdmove != prgmove) {
	        error(ca, 0);
	        return 0;
	    }
	    for (int i = 0; i < prgmove; ++i) {
	        int x, y;
	        fscanf(fprgout, "%s", buff);
	        if (!toint(buff, x)) {
	            error(ca, 1);
	            return 0;
	        }
	        fscanf(fprgout, "%s", buff);
	        if (!toint(buff, y)) {
	            error(ca, 1);
	            return 0;
	        }
	        if (x<1||x>n||y<1||y>m) {
	            error(ca, 2);
	            return 0;
	        }
	        fscanf(fprgout, "%s", temp);
	        int dir = hashstr(temp);
	        if (dir == -1) {
	            error(ca, 1);
	            return 0;
	        }
	        int dx = x + move[dir][0], dy = y + move[dir][1];
	        if (dx>=1 && dx<=n && dy>=1 && dy>=m) {
	            if (dat[dx][dy]) swap(dat[dx][dy], dat[x][y]);
	            else {
	                dat[dx][dy] = dat[x][y];
	                dat[x][y] = 0;
	                while (dat[x+1][y]) {
	                    dat[x][y] = dat[x+1][y];
	                    ++x;
	                }
	            }
	        } else {
	            error(ca, 1);
	            return 0;
	        }
	        while (canfall(dat, n, m)) {
                fall(dat, n, m);
            }
	    }
	    if (!all0(dat, n, m)) {
            error(ca, 3);
            return 0;
        }
	}
	printf("1\n");
	fclose(fin);
	fclose(fstdout);
	fclose(fprgout);
    return 0;
}
