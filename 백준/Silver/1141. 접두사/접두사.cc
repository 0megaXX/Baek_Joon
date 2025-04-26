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

	vector<string> v;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	v.resize(n);
	vector<bool> check(n, true);

	for (int a = 0; a < n; a++)
		cin >> v[a];

	sort(v.begin(), v.end());

	for (int a = 0; a < v.size(); a++)
	{
		for (int b = a + 1; b < v.size(); b++)
		{
			if (v[b].substr(0, v[a].size()) == v[a])
			{
				check[a] = false;
				break;
			}
		}
	}

	int ans = 0;
	for (auto i : check)
		if (i)
			ans++;

	cout << ans;

}

 