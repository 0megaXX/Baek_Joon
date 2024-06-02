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
#include <unordered_map>

using namespace std;

vector<int> adj[100001]; // 인접 리스트
vector<int> visit_order; // 방문 순서
int visit[100001];       // 방문 여부
int order[100001];       // 방문 우선순위

bool compare(int a, int b)
{
    return order[a] < order[b]; // 주어진 방문 순서에 따라 정렬

}

bool dfs(int node, int& index) 
{
    if (visit[node]) 
        return true; // 이미 방문한 노드라면

    if (visit_order[index] != node)
        return false; // 현재 방문해야 할 노드와 일치하지 않는다면

    visit[node] = true; // 방문

    index++; // 방문 순서 증가

    sort(adj[node].begin(), adj[node].end(), compare);
       

    for (auto& next : adj[node]) 
        if (!dfs(next, index)) return false;
    

    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    visit_order.resize(n);
    for (int a = 1; a < n; a++)
    {
        int satrt, eend;
        cin >> satrt >> eend;
        adj[satrt].push_back(eend);
        adj[eend].push_back(satrt);
    }

    

    for (int a = 0; a < n; a++)
    {
        cin >> visit_order[a];
        order[visit_order[a]] = a; // 방문 순서를 인덱스로 매핑
    }

    int index = 0;
    cout << (dfs(1, index) && index == n ? 1 : 0); // 전체 노드를 방문했는지 확인

    return 0;
}