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

bool cmp(pair<string, int> a, pair<string, int> b)
{
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int a = 0; a < T; ++a)
	{
		int N;
		cin >> N;

		vector<pair<string, int>> v;
		string name;
		int num;

		for (int j = 0; j < N; ++j)
		{
			cin >> name >> num;
			v.push_back({ name, num });
		}

		sort(v.begin(), v.end(), cmp);
		cout << v[0].first << '\n';
	}

	return 0;
}