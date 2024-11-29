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

using namespace std;
#define MAXX 99999999


int parent[100001];
int Rank[100001];


int find(int x) // 부모 찾기
{
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  
    }
    return parent[x];
}


void union_sets(int x, int y) // 부모 결합
{
    int px = find(x);
    int py = find(y);

    if (px != py) // 부모가 다르다며 결합
    {
        if (Rank[px] > Rank[py])
        {
            parent[py] = px;
        } 
        else if (Rank[px] < Rank[py])   
        {
            parent[px] = py;
        }
        else 
        {
            parent[py] = px;
            Rank[px]++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int node, edge;
    cin >> node >> edge;
    int s, e;
    cin >> s >> e;

    vector<pair<int, pair<int, int>>> edges;  // 가중치, 노드1, 노드2

    // 부모 배열 초기화
    for (int a = 1; a <= node; a++)
        {
        parent[a] = a;
        Rank[a] = 0;
    }

    // 간선 정보 입력
    for (int a = 0; a < edge; a++) 
    {
        int start, end, degree;
        cin >> start >> end >> degree;
        edges.push_back({degree, {start, end}});
    }

    // 간선 가중치 내림차순 정렬
    sort(edges.rbegin(), edges.rend());

    int max_min_degree = -1;

    // 간선을 하나씩 처리하며 두 노드가 연결되도록 합침
    for (auto& edge : edges)
        {
        int degree = edge.first;
        int start = edge.second.first;
        int end = edge.second.second;

        // 두 노드가 서로 다른 집합에 속하면 합침
        if (find(start) != find(end)) 
        {
            union_sets(start, end);
        }

        // 시작 노드와 끝 노드가 같은 집합에 속하면, 그 때의 최소 가중치를 기록
        if (find(s) == find(e))
        {
            max_min_degree = degree;
            break;  // 두 노드가 연결되었으므로 더 이상 간선을 처리할 필요 없음
        }
    }

    if(max_min_degree==-1)
        cout<<0;
    else
    cout << max_min_degree ;

    return 0;
}