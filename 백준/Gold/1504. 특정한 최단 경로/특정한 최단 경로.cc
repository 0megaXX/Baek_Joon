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
using namespace std;

int INF = 98765432;
int cost_list[801];
vector<vector<pair<int, int>>>v(801);

void bfs(int a)
{
	memset(cost_list, INF, sizeof(cost_list));
	priority_queue<pair<int, int>>pq;
	pq.push({ a ,0 });
	cost_list[a] = 0;
	while (!pq.empty())
	{
		int start = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (cost > cost_list[start])
			continue;
		cost_list[start] = cost;

		int nstart, ncost;
		for (int a = 0; a < v[start].size(); a++)
		{
			nstart = v[start][a].first;
			ncost = v[start][a].second+cost;
			if (cost_list[nstart] > ncost)
			{
				pq.push({ nstart,ncost });
				cost_list[nstart] = ncost;
			}
			
		}

	}


}

int main(void)
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node, edge;
	cin >> node >> edge;
	

	for (int a = 0; a < edge; a++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		v[start].push_back({ end,cost });
		v[end].push_back({ start,cost });

	}
	int want_1, want_2;
	cin >> want_1 >> want_2;
	
	bfs(1);
	int to_want_1 = cost_list[want_1]; //1에서 첫 경유지 들리는 최단거리
	int to_want_2 = cost_list[want_2]; //1에서 두번째 경유지 들리는 최단거리

	bfs(want_1);
	int _1_to_2 = cost_list[want_2];  //첫 경유지에서 두번째 경유지 들리는 최단거리
	int _1_to_node= cost_list[node];  //첫 경유지에서 마지막 노드 가는 최단거리
	bfs(want_2);
	//int _2_to_1 = cost_list[to_want_1]; 필요없는 이유는 무방향그래프이기에 1>2나 2>1이나 같음
	int _2_to_node = cost_list[node];  //두번째 경유지에서 마지막 노드 가는 최단거리
	
	int result = min(INF, to_want_1 + _1_to_2 + _2_to_node);
	result = min(result, to_want_2 + _1_to_2 + _1_to_node);

	if (result >= INF)
		cout << -1;
	else
		cout << result;
}
