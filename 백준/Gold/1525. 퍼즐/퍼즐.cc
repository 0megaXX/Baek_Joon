#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stddef.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include <sstream>
#include <cmath>
#include<map>
#include <queue>
#include <stack>
#include <cstring>
#include <deque>
#include <set>
#include <unordered_set>
#include <chrono>

#define MAXX 1000000005
using namespace std;

int ds[4]{ 1,-1,3,-3 };

map<string, int>m;

int bfs(string s)
{

    queue<pair<string,int>>q;
    q.push({ s ,0});

    while (!q.empty())
    {
        string cur = q.front().first;
        int ct = q.front().second+1;
        q.pop();

        if (cur == "123456780")
        {
            return m[cur];
        }

        int zero_pos = cur.find('0');
        
        for (int a = 0; a < 4; a++)
        {
            int next_pos = zero_pos + ds[a];

            // 상하좌우 이동이 가능한지 체크 (열 넘김 방지)
            if (next_pos >= 0 && next_pos < 9 && !(zero_pos == 2 && next_pos == 3) && !(zero_pos == 3 && next_pos == 2) && !(zero_pos == 5 && next_pos == 6) && !(zero_pos == 6 && next_pos == 5))
            {
                string tmp = cur;
                swap(tmp[zero_pos], tmp[next_pos]);

                if (m.find(tmp) == m.end())
                {
                    m[tmp] = ct;
                    q.push({ tmp, ct });
                }
            }
        }

    }

    return -1;


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s = "";

    for (int a = 0; a < 9; a++)
    {
        char c;
        cin >> c;
        s += c;
    }
    m[s] = 111111111;
    if (s == "123456780")
        cout << 0;
    else
    cout << bfs(s);

    return 0;
}