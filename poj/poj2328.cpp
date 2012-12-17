#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
using namespace std;
int main()
{
    int x;
    string a, b;
    int left = INT_MIN, right = INT_MAX;
    while (scanf("%d", &x), x)
    {
        cin >> a >> b;
        if (a + b == "toohigh") right = min(right, x - 1);
        else if (a + b == "toolow") left = max(left, x + 1);
        else
        {
            if ((x >= left) && (x <= right)) printf("Stan may be honest\n");
            else printf("Stan is dishonest\n");
            left = INT_MIN, right = INT_MAX;
        }
    }
    return 0;
}
