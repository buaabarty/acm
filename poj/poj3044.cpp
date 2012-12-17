#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#define LL long long
using namespace std;

LL n,w,ans;
stack<LL> h;

int main()
{
    LL x,y;
    while (cin>>n>>w)
    {
        ans = 0;
        while (!h.empty()) h.pop();
        for (LL i = 0; i < n; ++i)
        {
            cin>>x>>y;
            if (!h.empty() && h.top() > y)
            {
                LL t = h.top();
                while(!h.empty() && h.top() == t)
                {
                    h.pop();
                }
                ans++;
            }
            if (h.empty() || y > h.top())
            {
                h.push(y);
            }
        }
        while (!h.empty() && h.top() > 0)
        {
            LL t = h.top();
            while(!h.empty() && h.top() == t)
            {
                h.pop();
            }
            ans++;
        }
        cout << ans;
    }
    return 0;
}
