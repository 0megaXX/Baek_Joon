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
#define MAXX 987654321
using namespace std;

int n;
vector<vector<int>> vec;
int parent[50001];
int depth[50001];
bool visit[50001];



void dfs(int cur, int deep)
{
	
	visit[cur] = 1; //방문 저장
	
	depth[cur] = deep; // 현재 노드의 깊이를 저장

	for (auto nxt : vec[cur])
	{
		if (visit[nxt]) // 이미 방문했다면 무시
			continue;

		parent[nxt] = cur; //아니라면 다음의 부모는 현재위치
		dfs(nxt, deep + 1);
	}
}


int lca(int a, int b)
{
	while (depth[a] != depth[b]) // 깊이가 다르다면 깊이를 동일하게 만듬
	{

		//길이가 긴걸 짧게 만듬
		if (depth[a] > depth[b]) 
			a = parent[a];
		else
			b = parent[b];
	
	}

	while (a != b) // 길이가 같다면 하나씩 올라가며 LCA를 탐색
	{
		a = parent[a];
		b = parent[b];
	}

	return a;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


		cin >> n;
		vec.resize(n + 1, vector<int>());

		int a, b;
		for (int i = 0; i < n - 1; i++)
		{
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}

		dfs(1, 0);

		int q;
		cin >> q;
		while (q--)
		{

			int a, b;
			cin >> a >> b;
			cout << lca(a, b) << '\n';
		}
	
  

}
