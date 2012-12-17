#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
class Team
{
public:
    string name;
    int pt, goal, lost, tot, cnt;
    bool operator < (const Team a) const
    {
        if (pt != a.pt) return pt > a.pt;
        if (tot != a.tot) return tot > a.tot;
        if (goal != a.goal) return goal > a.goal;
        return name < a.name;
    }
}team[4], temp[4];
string str1, str2;
int d1, d2, tot, x, y;
bool okay(int win, int loss, int t1, int t2)
{
    for (int i = 0; i < 4; ++i) temp[i] = team[i];
    team[t1].tot += win - loss;
    team[t1].goal += win;
    team[t1].lost += loss;
    if (win > loss) team[t1].pt += 3;
    else if (win == loss)
    {
        team[t1].pt++; team[t2].pt++;
    }
    else team[t2].pt += 3;
    team[t2].tot += loss - win;
    team[t2].goal += loss;
    team[t2].lost += win;
    sort(team, team + 4);
    bool flag = ((team[0].name == "BERLAND") || (team[1].name == "BERLAND"));
/*    if (flag)
    {
        cout << win << " " << loss << endl;
        for (int i = 0; i < 4; ++i)
            cout << temp[i].name << " " << temp[i].pt << " " << temp[i].goal << " " << temp[i].tot << endl;
        for (int i = 0; i < 4; ++i)
            cout << team[i].name << " " << team[i].pt << " " << team[i].goal << " " << team[i].tot << endl;
            system("pause");
    }*/

    for (int i = 0; i < 4; ++i) team[i] = temp[i];
    return flag;
}
int main()
{
    tot = 0;
    for (int i = 1; i <= 5; ++i)
    {
        cin >> str1 >> str2;
        scanf("%d:%d", &d1, &d2);
//        cout << str1 << str2 << d1 << d2 << endl;
        x = -1; y = -1;
        for (int j = 0; j < tot; ++j)
            if (str1 == team[j].name)
            {
                x = j;
                break;
            }
        if (x == -1)
        {
            x = tot++;
            team[x].name = str1;
        }
        for (int j = 0; j < tot; ++j)
            if (str2 == team[j].name)
            {
                y = j;
                break;
            }
        if (y == -1)
        {
            y = tot++;
            team[y].name = str2;
        }
//        cout << x << y <<endl;
        team[x].goal += d1;
        team[x].lost += d2;
        team[x].tot += (d1 - d2);
        if (d1 > d2) team[x].pt += 3;
        else if (d1 == d2) team[x].pt += 1;
        team[y].goal += d2;
        team[y].lost += d1;
        team[y].tot += (d2 - d1);
        if (d2 > d1) team[y].pt += 3;
        else if (d2 == d1) team[y].pt += 1;
        team[x].cnt++;
        team[y].cnt++;
    }
    sort(team, team + 4);
    int bl = -1, opp = -1;
    for (int i = 0; i < 4; ++i)
        if (team[i].name == "BERLAND")
        {
            bl = i;
            break;
        }
    if (bl == -1)
    {
        puts("IMPOSSIBLE");
        return 0;
    }
    for (int i = 0; i < 4; ++i)
        if ((team[i].name != "BERLAND") && (team[i].cnt < 3))
        {
            opp = i;
            break;
        }
    //cout << team[bl].name << " " << team[opp].name << endl;
    int delta = 1000000, mloss = 1000000, mgoal;
    for (int g = 0; g <= 100; ++g)
        for (int l = 0; l < g; ++l)
            if (okay(g, l, bl, opp))
            {
                if (g - l < delta)
                {
                    delta = g - l;
                    mloss = l;
                    mgoal = g;
                }
                else if ((g - l == delta) && (l < mloss))
                {
                    mloss = l;
                    mgoal = g;
                }
            }
    /*team[bl].goal += 100;
    team[bl].tot += 100;
    team[bl].pt += 3;
    team[opp].lost += 100;
    team[opp].tot -= 100;
    sort(team, team + 4);*/
//    for (int i = 0; i < 4; ++i)
//        cout << team[i].name << team[i].pt << " " << team[i].tot << endl;
    if (delta == 1000000) puts("IMPOSSIBLE");
    else printf("%d:%d\n", mgoal, mloss);
    //if ((team[0].name != "BERLAND") && (team[1].name != "BERLAND")) puts("IMPOSSIBLE");
    //else printf("100:0\n");
    return 0;
}
