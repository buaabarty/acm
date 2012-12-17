#include <iostream>
using namespace std;
int main()
{
    int x;
    while (cin >> x)
    {
        if (x == 0) break;
        if (x > 2) cout << "Bob\n";
        else cout << "Alice\n";
    }
    return 0;
}
