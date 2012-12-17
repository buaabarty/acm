#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int a, b, c, d, e, f;
    while (cin >> a >> b >> c >> d >> e >> f)
    {
        if (a + b + c + d + e + f == 0) break;
        int res = 0;
        res += f;
        if (a >= e * 11) a -= e * 11;
        else a = 0;
        res += e;
        if (b >= d * 5) b -= d * 5;
        else{
            if (a >= 20 * d - b * 4) a -= 20 * d - b * 4;
            else a = 0;
            b = 0;
        }
        res += d;
        res += c / 4;
        c %= 4;
        res++;
        if (c == 3){
            if (b >= 1){
                b--;
                if (a >= 5) a -= 5;
                else a = 0;
            }
            else if (a >= 9) a -= 9;
            else a = 0;
        }
        else if (c == 2){
            if (b >= 3){
                b -= 3;
                if (a >= 6) a -= 6;
                else a = 0;
            }
            else{
                if (a >= 18 - b * 4) a -= 18 - b * 4;
                else a = 0;
                b = 0;
            }
        }
        else if (c == 1){
            if (b >= 5){
                b -= 5;
                if (a >= 7) a -= 7;
                else a = 0;
            }
            else{
                if (a >= 27 - b * 4) a -= 27 - b * 4;
                else a = 0;
                b = 0;
            }
        }
        else res--;
        res += (b / 9);
        b %= 9;
        if (b){
            res++;
            if (a >= 36 - 4 * b) a -= 36 - 4 * b;
            else a = 0;
        }
        res += (a / 36);
        a %= 36;
        if (a) res++;
        cout << res << endl;

    }
    return 0;
}
