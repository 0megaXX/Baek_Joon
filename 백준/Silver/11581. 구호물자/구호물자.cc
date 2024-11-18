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

int MAX = 101;
vector<vector<int>> graph;
vector<bool> visited;
vector<bool> on_stack;
bool has_cycle = false;


// DFS 함수
void dfs(int node) {
    visited[node] = true;
    on_stack[node] = true;

    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
            if (has_cycle) return; // 사이클이 발견되면 탐색 종료
        }
        else if (on_stack[next]) {
            has_cycle = true;
            return;
        }
    }

    on_stack[node] = false; // 탐색 종료 후 스택에서 제거
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 도시의 수
    cin >> n;

    graph.resize(n + 1);
    visited.resize(n + 1, false);
    on_stack.resize(n + 1, false);

    // 그래프 입력
    for (int a = 1; a < n; a++) 
    {
        int t; // 연결된 도시의 수
        cin >> t;

        while (t--) 
        {
            int b;
            cin >> b;
            graph[a].push_back(b); // 간선 추가
        }
    }

    // DFS 시작
    dfs(1);

    cout << (has_cycle ? "CYCLE" : "NO CYCLE");

    return 0;
}