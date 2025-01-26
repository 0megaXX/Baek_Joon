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

using namespace std;
#define MAXX 99999999


void dfs(int now, vector<int> v, vector<int> lotto) {
	if (lotto.size() + (v.size() - now) < 6) return;

	lotto.push_back(v[now]);
	if (lotto.size() == 6) {
		for (auto elem : lotto) cout << elem << ' ';
		cout << '\n';
		return;
	}

	for (int i = now + 1; i < v.size(); i++) {
		dfs(i, v, lotto);
	}

	return;
}


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	while (1) 
	{
		int k;
		cin >> k;

		if (k == 0)
			break;

		vector<int> v(k);

		for (int a = 0; a < k; a++)
			cin >> v[a];

		for (int i = 0; i <= v.size() - 6; i++)
		{
			vector<int> lotto;
			dfs(i, v, lotto);
		}
		cout << '\n';
	}

	return 0;

}
