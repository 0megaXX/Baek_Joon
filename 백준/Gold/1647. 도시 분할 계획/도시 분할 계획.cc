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
int parent[100001];

int find_parent(int a)
{
	if (parent[a] != a)
		return parent[a] = find_parent(parent[a]);
	else
		return a;
}

bool same_parent(int a, int b)
{
	return find_parent(a) == find_parent(b);

}



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int city, road;
	cin >> city >> road;
	for (int a = 1; a <= city; a++)
		parent[a] = a;

	vector<pair<int, pair<int, int>>>v;
	for (int a = 0; a < road; a++)
	{
		int start, end, km;
		cin >> start >> end >> km;
		v.push_back({ km,{start,end} });

	}
	sort(v.begin(), v.end());
	int total_km = 0;
	int hign_km=0;
	for (int a = 0; a < road; a++)
	{
		if (!same_parent(v[a].second.first, v[a].second.second))
		{

			parent[find_parent(v[a].second.second)] = find_parent(v[a].second.first);
			total_km += v[a].first;
			hign_km = max(hign_km, v[a].first);
		}


	}
	
	cout << total_km - hign_km;
}
