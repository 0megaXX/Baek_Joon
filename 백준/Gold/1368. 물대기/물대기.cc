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


vector<pair<int, pair<int, int>>>v;
int parent[301];
int arr[301][301];

int find_parent(int son)
{
	if (parent[son] != son)
		return parent[son] = find_parent(parent[son]);
	else
		return son;
}

void union_parent(int a, int b)
{

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	cin >> N;

	for (int a = 0; a <= N; a++)
		parent[a] = a;

	for (int a = 1; a <= N; a++)
	{
		int b;
		cin >> b;
		v.push_back({ b, { 0,a } }); // 비용 ,시작도시, 끝도시
		
	}
	for (int a = 1; a <= N; a++)
	{
		for (int b = 1; b <= N; b++)
		{
			cin >> arr[a][b];
			v.push_back({ arr[a][b],{a,b} }); // 비용 ,시작도시, 끝도시
		}
	}

	sort(v.begin(), v.end());


	int summ = 0;

	for (int a = 0; a <v.size(); a++)
	{
		int start = find_parent(v[a].second.first);
		int endd = find_parent(v[a].second.second);
		int cost = v[a].first;
		if (start != endd)
		{
			summ += cost;
			union_parent(start, endd);
		}

	}

	cout << summ;
	
}