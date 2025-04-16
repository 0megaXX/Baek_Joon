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
	int a, b, w;

	bool operator < (const Edge& e) const
	{
		return w < e.w;
	}
};
struct Node
{
	int to, w;
};

int parents[1000];
long long result = 0, worst = 0;

bool visit[1000];
vector<Node> nodes[1000];
vector<Edge> edges;

// union-find
int find_parent(int v)
{
	vector<int> vec;

	while (v != parents[v])
	{
		vec.push_back(v);
		v = parents[v];
	}

	for (int i : vec)
		parents[i] = v;

	return v;
}

// 최대 비용 구하기
void DFS(int cur, int dist)
{
	visit[cur] = true;

	for (int a = 0; a < nodes[cur].size(); a++)
		if (!visit[nodes[cur][a].to])
			DFS(nodes[cur][a].to, dist + nodes[cur][a].w);

	// 최대 비용 계산
	worst = max(worst, ( long long)dist);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int N, K;

	cin >> N >> K;

	for (int a = 0; a <= N; a++)
		parents[a] = a;

	for (int a = 0; a < K; a++)
	{
		int node1, node2, dist;
		cin >> node1>> node2>> dist;
		edges.push_back({ node1, node2, dist });
	}

	sort(edges.begin(), edges.end());

	for (int a = 0; a < edges.size(); a++)
	{
		Edge edge = edges[a];
		int fa = find_parent(edge.a), fb = find_parent(edge.b);

		if (fa != fb)
		{
			result += edge.w;
			parents[fa] = fb;

			nodes[edge.a].push_back({ edge.b, edge.w });
			nodes[edge.b].push_back({ edge.a, edge.w });
		}
	}

	// 0부터 N까지 경로를 계산
	for (int a = 0; a < N; a++)
	{
		for (int b = 0; b < N; b++)
			visit[b] = false;

		DFS(a, 0);
	}

	cout << result << '\n' << worst;
}