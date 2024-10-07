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

#define MAXX 987654321
using namespace std;

int N, M, T, S, G, H, Dist_G_to_H;

vector<pair<int, int>>v[2001];
vector<int>ter;
int dist_S[2001];
int dist_G[2001];
int dist_H[2001];

void dik(int start, int* arr)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
	pq.push({ 0,start });
	arr[start] = 0;

	while (!pq.empty())
	{
		int cur_cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		int next, next_cost;
		for (int a = 0; a < v[cur].size(); a++)
		{
			next = v[cur][a].first;
			next_cost = v[cur][a].second;

			if (arr[next] > cur_cost + next_cost) // 최단거리 갱신이라면
			{
				arr[next] = cur_cost + next_cost;
				pq.push({ arr[next],next });

			}

		}

	}

}



int main() {
	ios_base::sync_with_stdio(false);

	int cass;
	cin >> cass;
	while (cass--)
	{


		for (int a = 0; a < 2001; a++)
		{
			v[a].clear();
			dist_S[a]=MAXX;
			dist_G[a] = MAXX;
			dist_H[a] = MAXX;
		}
		ter.clear();

		cin >> N >> M >> T;
		cin >> S >> G >> H;

		for (int a = 0; a < M; a++)
		{
			int start, end, degree;
			cin >> start >> end >> degree;
			v[start].push_back({ end,degree });
			v[end].push_back({ start,degree });

		}

		for (int a = 0; a < T; a++)
		{
			int b;
			cin >> b;
			ter.push_back(b);
		}

		dik(S, dist_S);
		dik(G, dist_G);
		Dist_G_to_H = dist_G[H];
		dik(H, dist_H);

		sort(ter.begin(), ter.end()); // 오름차순 출력을 위한 정렬.

		for (int a = 0; a < ter.size(); a++)
		{
			int termi = ter[a];
			if (dist_S[termi] == dist_S[G] + Dist_G_to_H + dist_H[termi]) // 지나가는 최단거리라면
				cout << termi << ' ';
			else if (dist_S[termi] == dist_S[H] + Dist_G_to_H + dist_G[termi]) // 지나가는 최단거리라면
				cout << termi << ' ';
		}
		cout << '\n';

	}
	return 0;
}