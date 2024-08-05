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

int sizz, cass;


vector<set<int>> v;
vector<int> bfs_order;
vector<bool> visited;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int idx = 1; // 현재 순서

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        set<int> child;
        for (int neighbor : v[current]) 
            if (!visited[neighbor]) 
                child.insert(neighbor);      
        

        for (int i = 0; i < child.size(); i++) {
            if (idx >= bfs_order.size() || child.find(bfs_order[idx]) == child.end()) {
                cout << 0;
                return;
            }
            q.push(bfs_order[idx]);
            visited[bfs_order[idx]] = true;
            idx++;
        }
    }

    cout << 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin >> cass;

    v.resize(cass + 1);
    visited.resize(cass + 1, false);
    bfs_order.resize(cass);

    for (int a = 0; a < cass - 1; a++) {
        int b, c;
        cin >> b >> c;
        v[b].insert(c);
        v[c].insert(b);
    }

    for (int a = 0; a < cass; a++) 
        cin >> bfs_order[a];
    
    if (bfs_order[0] != 1) { // BFS 시작은 항상 1번 노드부터
        cout << 0 << '\n';
        return 0;
    }

    bfs(bfs_order[0]);


}