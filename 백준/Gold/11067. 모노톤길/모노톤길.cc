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



pair<int, int> pos[100001];


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int test;
	for (cin >> test; test--;)
	{
		int N;
		cin >> N;
		for (int a = 1; a <= N; a++)
			cin >> pos[a].first >> pos[a].second;

		sort(pos + 1, pos + 1 + N);

		for (int a = 1, e; a < N; a = e)
		{
			e = upper_bound(pos + 1, pos + 1 + N, make_pair(pos[a].first, int(1e9))) - pos;
			
			if (pos[a].second != pos[a - 1].second)
				reverse(pos + a, pos + e);
		}

		int M;
		cin >> M;
		while (M--)
		{
			int n;
			cin >> n;
			cout<< pos[n].first<<' '<< pos[n].second<<'\n';
		}
	}


}

 