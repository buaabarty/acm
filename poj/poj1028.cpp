#include <iostream>
#include <string>
#include <stack>
#define MAX_N 200
using namespace std;
string opr, dat[MAX_N],now;
stack<string> fw, bw;
int l = 1;
int main()
{
    now = "http://www.acm.org/";
    while (cin >> opr)
    {
        bool flag = true;
        if (opr == "QUIT") break;
        else if (opr == "VISIT")
        {
                if (now != "Ignored") bw.push(now);
                while (!fw.empty()) fw.pop();
                cin >> now;
        }
        else if (opr == "BACK")
        {
                if (bw.empty()) flag = false;
                else{
                    fw.push(now);
                    now = bw.top();
                    bw.pop();
                }
        }
        else if (opr == "FORWARD")
        {
                if (fw.empty()) flag = false;
                else{
                    bw.push(now);
                    now = fw.top();
                    fw.pop();
                }
        }
        if (flag) cout << now << endl;
        else cout << "Ignored" << endl;
    }
    return 0;
}
