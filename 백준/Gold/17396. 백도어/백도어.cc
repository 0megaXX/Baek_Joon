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
#define MAXX 987654321234567
using namespace std;

int ward[100001];
long long len[100001];
vector<vector<pair<int, int>>>road(100001);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N, M;
	cin >> N >> M;

	for (int a = 0; a < N; a++)
	{
		cin >> ward[a];
		len[a] = MAXX;
	}

	for (int a = 0; a < M; a++)
	{
		int start, end, len;
		cin >> start >> end >> len;
		road[start].push_back({ end,len });
		road[end].push_back({ start,len });
	}


	priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<>>pq;
	len[0] = 0;
	pq.push({ 0 ,0 }); // 누적거리, 현재노드
	while (!pq.empty())
	{

		long long cur_summ = pq.top().first;
	    int cur = pq.top().second;
		pq.pop();

		
		if ( cur_summ > len[cur])
			continue;

		for (int a = 0; a < road[cur].size(); a++)
		{

			if (!ward[road[cur][a].first] || road[cur][a].first == N - 1) // 와드에 안보이거나 넥서스라 걸려도 된다면
				if (len[road[cur][a].first] > len[cur] + road[cur][a].second)
				{
					len[road[cur][a].first] = len[cur] + road[cur][a].second;
					pq.push({len[road[cur][a].first],road[cur][a].first });
				}

		}
	}


	if (len[N - 1] == MAXX)
		cout << -1;
	else
		cout << len[N - 1];
}