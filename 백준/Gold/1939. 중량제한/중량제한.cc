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

bool visit[100001];
vector<pair<int, int>>v[10001];
int max_cost=0;
int Start_node, End_node;

bool bfs(int cur_cost)
{
	queue<int>q;
	q.push(Start_node);
	visit[Start_node] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		if (cur == End_node) //무사히 끝까지 도착했다면
			return true;

		for (int a = 0; a < v[cur].size(); a++)
		{
			int next_node = v[cur][a].first;
			int next_cost = v[cur][a].second;

			if (!visit[next_node] && cur_cost <= next_cost) //방문한적이 없고 현재 비용보다 다음 비용이 크거나 같다면
			{
				visit[next_node] = 1;
				q.push(next_node);
			}


		}
		
	}
		return false;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int node,edge;
	cin >> node>>edge;

	int start, end, cost;
	for (int a = 0; a < edge; a++)
	{
		cin >> start >> end >> cost;

		v[start].push_back({ end,cost });
		v[end].push_back({ start,cost });
		max_cost = max(max_cost, cost);

	}
	cin >> Start_node >> End_node;
	
	int low = 0;
	int high = max_cost;

	while (low <= high)
	{
		
		memset(visit, false, sizeof(visit));
		int mid = (low + high) / 2;
		if (bfs(mid))
			low = mid + 1;
		else
			high = mid - 1;

	}
	cout << high;

}