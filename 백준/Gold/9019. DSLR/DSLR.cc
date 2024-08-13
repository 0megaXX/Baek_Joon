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
#define MAXX 987654321
using namespace std;



bool visit[10000];

void bfs(int start, int eend)
{
    memset(visit, false, sizeof(visit));
    queue<pair<int, string>> q;
    q.push({ start, "" });

    while (!q.empty())
    {
        int cur = q.front().first;
        string command = q.front().second;
        q.pop();

        if (cur == eend)
        {
            cout << command << '\n';
            return;
        }

        int case_D = cur * 2 % 10000;
        if (!visit[case_D]) // D 명령어 처리
        {
            visit[case_D] = true;
            q.push({ case_D, command + 'D' });
        }

        int case_S = (cur == 0) ? 9999 : cur - 1;
        if (!visit[case_S]) // S 명령어 처리
        {
            visit[case_S] = true;
            q.push({ case_S, command + 'S' });
        }

        int d1 = cur / 1000;
        int d2 = (cur / 100) % 10;
        int d3 = (cur / 10) % 10;
        int d4 = cur % 10;

        int case_L = (d2 * 1000) + (d3 * 100) + (d4 * 10) + d1;
        if (!visit[case_L]) // L 명령어 처리
        {
            visit[case_L] = true;
            q.push({ case_L, command + 'L' });
        }

        int case_R = (d4 * 1000) + (d1 * 100) + (d2 * 10) + d3;
        if (!visit[case_R]) // R 명령어 처리
        {
            visit[case_R] = true;
            q.push({ case_R, command + 'R' });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while (n--)
    {
        int A, B;
        cin >> A >> B;
        bfs(A, B);
    }
}