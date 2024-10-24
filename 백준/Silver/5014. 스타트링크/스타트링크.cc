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

bool visit[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    queue<pair<int,int>>q;
    visit[S] = true;
    q.push({ S,0 });


    while (!q.empty())
    {
        int cur = q.front().first;
        int ct = q.front().second;
        q.pop();
        if (cur == G)
        {
            cout << ct;
            return 0;
        }

        

        if (cur + U >= 1 && cur + U <= F && !visit[cur + U])
        {
            visit[cur + U] = true;
            q.push({ cur + U,ct + 1 });
        }

        if(cur - D >= 1 && cur -D <= F && !visit[cur -D])
        {
            visit[cur -D] = true;
            q.push({ cur -D,ct + 1 });
        }
    }

    cout << "use the stairs";

    return 0;

}