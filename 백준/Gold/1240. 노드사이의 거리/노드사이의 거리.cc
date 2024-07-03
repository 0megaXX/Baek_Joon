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
using namespace std;

vector<vector<pair<int, int>>>v(1001);
bool visit[1001];
int bfs(int start,int end)
{

	queue<pair<int,int>>q;
	q.push({ start ,0});
	visit[start] = true;
	while (!q.empty())
	{
		int cur = q.front().first;
		int cur_cost = q.front().second;

		if (cur == end)
			return cur_cost;

		q.pop();

		for (int a = 0; a < v[cur].size(); a++)
		{
			if (!visit[v[cur][a].first])
			{
				visit[v[cur][a].first] = true;
				q.push({ v[cur][a].first,cur_cost + v[cur][a].second });
			}
		}



	}



}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int node, want_degree;
	cin >> node >> want_degree;
	
	for (int a = 0; a < node - 1; a++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		v[start].push_back({ end,cost });
		v[end].push_back({ start,cost });
	}
	
	while (want_degree--)
	{
		memset(visit, false, sizeof(visit));
		int start, end;
		cin >> start >> end;

		cout << bfs(start, end)<<'\n';


	}
}