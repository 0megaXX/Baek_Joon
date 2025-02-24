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

int n, m, dist[20001];
bool visited[20001];
vector<int> arr[20001];

void bfs()
{
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	visited[1] = true;
    // 1부터 시작

	while (!q.empty()) // 거리 측정
	{
		int now = q.front();
		q.pop();

		for (auto& next : arr[now])
    		{
    			if (!visited[next])
			{
				q.push(next);
				dist[next] = dist[now] + 1;
				visited[next] = true;
			}
		}
	}

	int maxx = 0;
	for (int a = 1; a <= n; a++)
		maxx = max(maxx, dist[a]); // 최대 거리 측정

	int rs = 0, ct = 0;
	bool flag = 0;
	for (int a = 1; a <= n; a++)
	{
		if (maxx == dist[a])
		{
			if (!flag) // 첫 최대거리 (작은 번호) 만 정보필요
				flag = true, rs = a;
            
			ct++; // 외에는 카운트만 증가
		}
	}

	cout << rs << ' ' << maxx << ' ' << ct;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n >> m;

	for (int a= 0; a < m; a++)
	{
		int s, e;
		cin >> s >> e;
		arr[s].push_back(e);
		arr[e].push_back(s);
	}

	bfs();
	return 0;
}