#include <iostream>
using namespace std;
int main()
{
    int t, a, b, c;
    cin >> t;
    cout << "Gnomes:" << endl;
    while (t--)
    {
        cin >> a >> b >> c;
        if ((a <= b) && (b <= c) || (a >= b) && (b >= c)) cout << "Ordered" << endl;
        else cout << "Unordered" << endl;
    }
    return 0;
}
