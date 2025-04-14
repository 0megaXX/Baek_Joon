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

struct Edge 
{
	int u, v, d;
	bool operator<(const Edge& a)  // struct 오퍼레이터 
    {
		return d < a.d; // 거리순 정렬
	}
};

vector<int>parent;
vector<char>univ;
vector<Edge>edges;

int Find_parent(int a)
{
	if (a == parent[a])
		return a;
    
	return parent[a] = Find_parent(parent[a]);
}

void Union_parent(int a, int b) {
	a = Find_parent(a);
    b = Find_parent(b);
	parent[a] = b;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

    parent.resize(n+1);
    univ.resize(n+1);
	for (int a = 1; a <= n; a++)
    {
		cin >> univ[a];
		parent[a] = a;
	}

	for (int a = 0; a < m; a++) 
    {
		int u, v, d;
		cin >> u >> v >> d;

		if (univ[u] != univ[v]) // 다른 성별이라면 연결 가능 
			edges.push_back({ u, v, d });
	}

	sort(edges.begin(), edges.end()); // 거리순으로 정

	int rs = 0;
	for (auto& i : edges)
    {
		if (Find_parent(i.u) != Find_parent(i.v)) // 연결되어있지 않다면 
        {
			Union_parent(i.u, i.v);
			rs += i.d;
		}
	}

	bool all_conect = true;
    
	for (int a = 2; a <= n; a++) // 모든 대학이 연결되었는지 확인 
		if (Find_parent(1) != Find_parent(a)) // 하나라도 연결 안되었으면 -1
        {
            all_conect = false;
            break;
        }
	cout << (all_conect ? rs : -1 );
    
	return 0;
}