#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string res[10] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        n--;
        int lasts = 0, s = 5, j = 1;
        while (!((n >= lasts) && (n < s)))
        {
            lasts = s;
            j *= 2;
            s += 5 * j;
        }
        n -= lasts;
        n /= j;
        cout << res[n] << endl;
    }
    return 0;
}
