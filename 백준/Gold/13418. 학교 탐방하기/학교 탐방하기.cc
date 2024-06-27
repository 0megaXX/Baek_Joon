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

int parent[1001];

int parent_find(int a)
{
	if (parent[a] == a)
		return a;
	else
		return parent[a] = parent_find(parent[a]);
}

void parent_union(int a, int b)
{
	a = parent_find(a);
	b = parent_find(b);

	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;
}


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int a = 0; a <= N; a++)
		parent[a] = a;

	vector < pair<int, pair<int, int>>>v;
	int x, y, z;
	
	for (int a = 0; a <= M; a++)
	{
		cin >> x >> y >> z;
		v.push_back({ z, { x,y } }); // 1은 내리막 0은 오르막
	}
	sort(v.rbegin(), v.rend());

	long how_up_when_good = 0;
	for (int a = 0; a < v.size(); a++)
	{
		int cost = v[a].first;
		int start = v[a].second.first;
		int end = v[a].second.second;

		if (parent_find(start) != parent_find(end))//연결이 되어있지 않다면
		{	
			parent_union(start, end);
			if (cost == 0)
				how_up_when_good++;
		}

	}

	for (int a = 0; a <= N; a++) // 최적의 parent는 구했으니 최악의 parent를 구하기 위해 초기화
		parent[a] = a;
	
	 
	sort(v.begin(), v.end());

	long how_up_when_bad = 0;
	for (int a = 0; a < v.size(); a++)
	{
		int cost = v[a].first;
		int start = v[a].second.first;
		int end = v[a].second.second;

		if (parent_find(start) != parent_find(end))//연결이 되어있지 않다면
		{
			parent_union(start, end);
			if (cost == 0)
				how_up_when_bad++;
		}

	}

	cout << pow(how_up_when_bad,2) - pow(how_up_when_good,2);
}
