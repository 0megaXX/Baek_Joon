#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1001];

int find_parent(int a)
{
    if (a == parent[a]) 
        return a;
    else
        return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) 
{
    a = find_parent(a);
    b = find_parent(b);
    if (a != b) 
    {
        if (a < b)
            parent[b] = a;          
        else 
            parent[a] = b;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, start, end;
    cin >> n >> m >> start >> end;

    vector<pair<int, pair<int, int>>> edges; // {가중치, {정점1, 정점2}}

    // 간선 정보 입력
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges.push_back({cost, {u, v}});
    }

    // 간선들을 비용 기준으로 내림차순으로 정렬
    sort(edges.rbegin(), edges.rend());

    // 이진 탐색을 위한 변수 설정
    int left = 1, right = 50000; // 비용범위
    int rs = 0;
    int mid;
    while (left <= right) // 이진탐색
    {
        mid = (left + right) / 2;

        // 부모 배열 초기화
        for (int a = 0; a <= n; a++) 
            parent[a] = a;

        // mid 값 이상인 간선들만 유니온 파인드를 통해 연결
        for (auto& edge : edges) {
            int cost = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            if (cost >= mid) 
                union_parent(u, v);
            
        }

        // start와 end가 연결되어 있는지 확인
        if (find_parent(start) == find_parent(end))
        {
            rs = mid;
            left = mid + 1; // 더 큰 최소 비용을 찾기 위해
        } 
        else 
            right = mid - 1; // 더 작은 비용으로 탐색
        
    }

    cout << rs;

    return 0;
}
