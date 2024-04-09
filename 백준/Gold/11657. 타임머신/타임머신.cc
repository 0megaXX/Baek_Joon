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
#define MAX 999999999

using namespace std;

long long arr[6001];
int city, road;
vector<pair<int, pair<int, int>>>v;

void Bellman_Ford()
{
	arr[1] = 0;
	for (int a = 1; a <= city - 1; a++)
	{
		for (int b = 0; b < v.size(); b++)
		{
			int start = v[b].first;
			int end = v[b].second.first;
			int cost = v[b].second.second;

			if (arr[start] == MAX)
				continue;
			if (arr[end] > arr[start] + cost)
				arr[end] = arr[start] + cost;

		}
	}

	for (int b = 0; b < v.size(); b++)
	{
		int start = v[b].first;
		int end = v[b].second.first;
		int cost = v[b].second.second;

		if (arr[start] == MAX)
			continue;
		if (arr[end] > arr[start] + cost)
		{
			cout << -1;
			return;
		}

	}

	for (int a = 2; a <= city; a++)
	{
		if (arr[a] == MAX)
			cout << -1 << '\n';
		else
		cout << arr[a] << '\n';
	}
}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(arr, arr + 6000, MAX);
	cin >> city >> road;
	for (int a = 0; a < road; a++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		v.push_back({ start,{end,cost} });
	}
	sort(v.begin(), v.end());

	Bellman_Ford();
}
