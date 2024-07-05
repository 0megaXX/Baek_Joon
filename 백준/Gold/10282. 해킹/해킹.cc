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
vector<pair<int, int>>v[10001];
int degree[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cass;
	cin >> cass;
	while (cass--)
	{
		v->clear();
		int n, d, c;
		cin >> n >> d >> c;

		for (int a = 1; a <= n; a++) 
			v[a].clear();
		

		int hacking = c;
		for (int a = 1; a <= n; a++)
			degree[a] = MAXX;

		degree[c] = 0;

		for (int a = 0; a < d; a++)
		{
			int start, end, cost;
			cin >> start >> end >> cost;
			v[end].push_back({start,cost});
		}

		priority_queue<int>pq;
		pq.push(hacking);
		while (!pq.empty())
		{
			int cur = pq.top();
			pq.pop();

			for (int a = 0; a < v[cur].size(); a++)
			{
				if (degree[v[cur][a].first] > degree[cur] + v[cur][a].second)
					//현재 연결된 위치까지의 거리보다 현재위치에서 연결된 위치까지 가는 거리보다 짧다면
				{
				/*	cout << v[cur][a].first << "의 거리는 " << cur << "의 위치인"
						<< degree[cur] << " 와 " << v[cur][a].second << endl;*/
					degree[v[cur][a].first] = degree[cur] + v[cur][a].second;
					pq.push(v[cur][a].first);
				}


			}

		}

		int com=0, cost=0;
		for (int a = 1; a <= n; a++)
		{
			if (degree[a]!=MAXX) // 감염 주체거나 감염이 되지 않았다면
			{
				com++;
				cost = max(cost, degree[a]);
			}

		}
		cout << com << ' ' << cost << '\n';
	}


}