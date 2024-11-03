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

#define MAXX 1000000000
using namespace std;
vector<int> ct;
vector<vector<int>> v;
vector<bool> visit;

int bfs(int start) {
    int Count = 0;
    queue<int> q;
    q.push(start);
    visit[start] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        Count++;

        for (int next : v[cur]) {
            if (!visit[next]) {
                visit[next] = true;
                q.push(next);
            }
        }
    }

    return Count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    ct.resize(N + 1, 0);
    v.resize(N + 1);
    visit.resize(N + 1);

    for (int a = 0; a < M; a++) {
        int b, c;
        cin >> b >> c;
        v[c].push_back(b); // c가 b를 신뢰함
    }

    int max_val = 0;
    for (int a = 1; a <= N; a++) {
        fill(visit.begin(), visit.end(), false); // BFS마다 visit 초기화
        ct[a] = bfs(a); // 각 노드에 대해 BFS 수행
        max_val = max(max_val, ct[a]);
    }

    for (int a = 1; a <= N; a++) 
        if (ct[a] == max_val) 
            cout << a << ' ';
        
    

    return 0;
}