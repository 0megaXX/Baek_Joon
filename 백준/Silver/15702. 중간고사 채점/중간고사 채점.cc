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


bool compare(pair<int, int>& front, pair<int, int>& back)
{
	if (front.second < back.second)
		return front.second > back.second;

	else if (front.second == back.second)
		return front.first < back.first;

	else return front.second > back.second;
}
	vector<int> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m;


	for (int a = 0; a < n; a++)
	{
		cin >> k;
		v.push_back(k);
	}

	int sn;
	char ox;
	vector<pair<int, int>> v2;
	for (int a = 0; a < m; a++)
	{
		int score = 0;
		cin >> sn;
		for (int b = 0; b < n; b++) 
		{
			cin >> ox;
			if (ox == 'O')
				score += v[b];
		}
		v2.push_back({ sn, score });
	}

	sort(v2.begin(), v2.end(), compare);

	cout << v2[0].first << " " << v2[0].second;
	return 0;
}

