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
#include <tuple>

using namespace std;
#define MAXX 2147483647



vector<pair<int, pair<int, int>>>edges; // 비용, 도시1, 도시2
int parent[10001];

 
int find_Parent(int a)
{
    if (a == parent[a]) 
        return a;
    else
        return a = find_Parent(parent[a]);
}
 
void union_Parent(int a, int b)
{
    a = find_Parent(a);
    b = find_Parent(b);
 
    if (a < b) 
        parent[b] = a;
    else 
        parent[a] = b;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, T; 
    cin >> N >> M >> T;
 
    for (int a = 1; a <= N; a++) // union_find 초기화
        parent[a] = a;            
    
    for (int a = 0; a < M; a++)
    {
        int city1, city2, cost;
        cin >> city1 >> city2 >> cost;
        edges.push_back({ cost,{city1,city2} }); // 비용이 기준  
    }
    
    sort(edges.begin(), edges.end()); // 적은 비용순으로 정렬 

    int rs = 0, ct = 0;
    for (int a = 0; a < edges.size(); a++)
    {
        int cost = edges[a].first;
        int city_a = edges[a].second.first;
        int city_b = edges[a].second.second;
        if (find_Parent(city_a) != find_Parent(city_b)) // 아직 정복 전 이라면
        {
            union_Parent(city_a, city_b);
            rs += cost+ct*T;
            ct++;
        }
    }
    cout << rs;
    
}