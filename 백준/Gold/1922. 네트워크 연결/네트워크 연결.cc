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


int N, M;
vector<pair<int, pair<int, int>>> v;

int parent[1001];


int find_parent(int a)
{

	if (parent[a] == a)
		return a;
	else
		return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b)
{

	a = find_parent(a);
	b = find_parent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;

}


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int a = 1; a <= N; a++)
		parent[a] = a;


	for (int a = 0; a < M; a++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		v.push_back({ cost,{start,end} });
	}

	sort(v.begin(), v.end());

	int summ = 0;

	for (int a = 0; a < M; a++)
	{
		int cost = v[a].first;
		int start = v[a].second.first;
		int end = v[a].second.second;


		if (find_parent(start) != find_parent(end))//연결이 안되어있다면
		{
			summ += cost;
			union_parent(start, end);
		}
	}
	cout << summ;
	
}
