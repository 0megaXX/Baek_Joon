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


long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

pair<long long, long long> arr[1500];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		map<pair<long long, long long>, int> m;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			long long x = arr[i].first - arr[j].first;
			long long y = arr[i].second - arr[j].second;
			long long g = gcd(x, y);
			if (g < 0)
				g = -g;
			x /= g, y /= g;
			m[{x, y}]++;
		}
		for (auto& j : m)
		{
			int nowX = j.first.first;
			int nowY = j.first.second;
			if (m.count({ -nowY, nowX }))
			{
				ans += j.second * m[{-nowY, nowX}];
			}
		}
	}
	cout << ans;
}

