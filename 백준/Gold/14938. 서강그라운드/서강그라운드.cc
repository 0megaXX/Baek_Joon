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

int area_list[101];
bool visit[101];
int max_cost[101]{0};
int maxx = 0;

vector<vector<pair<int, int>>>v(101);



//void dfs(int cur, int cur_range)
//{
//	
//
//	for (int a = 0; a < v[cur].size(); a++)
//	{	
//		if (cur_range >= v[cur][a].second && !visit[v[cur][a].first])
//		{
//			cout << cur << "일때 " << v[cur][a].first << "에 접근\n";
//			visit[v[cur][a].first] = true;
//			dfs( v[cur][a].first, cur_range - v[cur][a].second );
//		
//		}
//
//	}
//
//
//}


int main(void)
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int area, search_range, node;

	cin >> area >> search_range >> node;
	for (int a = 1; a <= area; a++)
		cin >> area_list[a];

	for (int a = 0; a < node; a++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		v[start].push_back({ end,cost });
		v[end].push_back({ start,cost });
	}
	int rs = 0;
	for (int a = 1; a <= area; a++)
	{
		
		memset(visit, false, sizeof(visit));
		memset(max_cost, 0, sizeof(max_cost));
		visit[a] = true;
		priority_queue<pair<int, int>>pq;
		pq.push({ a,search_range });
		while (!pq.empty())
		{
			int cur = pq.top().first;
			int cur_range = pq.top().second;
			pq.pop();
			if (max_cost[cur] != 0 && max_cost[cur] >= cur_range) //한번이라도 들렸는데 갈수 있는 범위가 기존보다 작다면
				continue;

			max_cost[cur] = cur_range;

			for (int a = 0; a < v[cur].size(); a++)
			{
				if (cur_range >= v[cur][a].second)
				{
					//cout << cur << "일때 " << v[cur][a].first << "에 접근\n";
					visit[v[cur][a].first] = true;
					//dfs(v[cur][a].first, cur_range - v[cur][a].second);
					//max_cost[v[cur][a].first] = cur_range - v[cur][a].second;
					pq.push({ v[cur][a].first,cur_range - v[cur][a].second });
				}
			}

		}
		int maxx = 0;
		for (int b = 1; b <= area; b++)
		{
			if (visit[b])
				maxx += area_list[b];
		}
				rs = max(maxx, rs);
		
	}
	cout << rs;
}
