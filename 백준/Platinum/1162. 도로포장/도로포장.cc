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


struct MyStruct
{
	long long cost,cur, doropojang;
	bool operator<(const MyStruct& a) const {
		return cost > a.cost;
	}
};

long long dp[10001][21];



int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int city, road, doropojang_max;
	cin >> city >> road >> doropojang_max;

	vector<vector<pair<long long, long long >>>v(city+1);

	for (int a = 0; a < road; a++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		v[start].push_back({ end ,cost});
		v[end].push_back({ start ,cost });
	}

	
	memset(dp, 0x3f, sizeof(dp));
	priority_queue<MyStruct> pq;
	pq.push({ 0,1,0 }); //각 멤버는 현재 누적 비용, 시작 노드, 도로포장 횟수
	dp[1][0] = 0;
	long long cur_node, cost, doropojang;
	long long next_node, next_cost;
	while (!pq.empty())
	{
	
		cur_node = pq.top().cur;
		cost = pq.top().cost;
		doropojang = pq.top().doropojang;
		pq.pop();
		//cout <<v[cur_node].size()<< " 접근\n";
		if (dp[cur_node][doropojang] < cost)
			continue;

		for (int a = 0; a < v[cur_node].size(); a++) {
			next_node = v[cur_node][a].first;
			next_cost = v[cur_node][a].second+cost;
			//cout << "다음 노드는 " << next_node << " 그리고 총 비용은 " << next_cost << endl;

			if (next_cost < dp[next_node][doropojang]) //포장 안해도 적다면
			{ 
				pq.push({ next_cost, next_node ,doropojang });
				dp[next_node][doropojang] = next_cost;
			}

			if (doropojang < doropojang_max&& cost < dp[next_node][doropojang + 1]) //포장하면 적다면
			{
				pq.push({cost, next_node ,doropojang+1 });
				dp[next_node][doropojang+1] = cost;
			}
		}
	}

	long long minn = dp[city][0];
	for (int a = 0; a <= doropojang_max; a++)
		//cout << dp[city][a] << endl;
		minn = min(minn, dp[city][a]);
	cout << minn;


}
