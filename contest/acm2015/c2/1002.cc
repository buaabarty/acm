#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Matrix {
    int num[2][2];
} mat;

void Initiate(){
    mat.num[0][0] = 5;
    mat.num[0][1] = 12;
    mat.num[1][0] = 2;
    mat.num[1][1] = 5;
}

Matrix Mul(Matrix &a, Matrix &b, int mod){
    Matrix c;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            c.num[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                c.num[i][j] += a.num[i][k] * b.num[k][j];
                c.num[i][j] %= mod;
            }    
        }
    }
    return c;
}

Matrix Pow(int n, int mod){
    cout << n << endl;
    if (n == 1) return mat;
    else {
        Matrix temp = Pow(n - 1, mod);
        return Mul(temp, temp, mod);
    }
}

int main(){
    int T, n, mod;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ++ca) {
        scanf("%d%d", &n, &mod);
        Initiate();
        mat = Pow(n, mod);
        int ans = (mat.num[0][0] * 2 - 1) % mod;
        printf("%d\n", ans);
    }
    return 0;
}
