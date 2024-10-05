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

vector<pair<int, pair<int, int>>> edge;
int parent[1001];
int sizz;

int find_parent(int x) 
{
	if (parent[x] == x)
        return x;

	return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int same_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a == b)
        return 1;

	else
        return 0;
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> sizz;

	for (int a = 0; a < sizz; a++)
		for (int b = 0; b < sizz; b++)
		{
			int c;
			cin >> c;
			edge.push_back({ c,{a,b} });
		}


	sort(edge.begin(), edge.end());

	for (int a = 1; a <= sizz; a++)
		parent[a] = a;

	long long ans = 0;

	for (int a = 0; a < edge.size(); a++)
	{

		int dist = edge[a].first;
		int first = edge[a].second.first;
		int second = edge[a].second.second;

		if (dist == 0)
			continue;

		if (same_parent(first, second)) // 이미 연결되었다면
			continue;

		union_parent(first, second); // 아니면 연결

		ans += dist; // 거리추가
	}

	cout << ans;



    return 0;
}