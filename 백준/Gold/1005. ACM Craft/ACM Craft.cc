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
using namespace std;

int dp[1001]{ 0 };
int Time[1001]{ 0 };
int Entry[1001]{ 0 };
vector<int>Build[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	while (cass--)
	{

		memset(dp, 0, sizeof(dp));
		memset(Time, 0, sizeof(Time));
		memset(Entry, 0, sizeof(Entry));
		for (int a = 0; a < 1001; a++)
			Build[a].clear();




		int build, rute;
		cin >> build >> rute;

		for (int a = 1; a <= build; a++)
		{

			cin >> Time[a];

		}


		for (int a = 0; a < rute; a++)
		{
			int start, endd;
			cin >> start >> endd;
			Build[start].push_back(endd);
			Entry[endd]++;

		}

		queue<int>q;
		for (int a = 1; a <= build; a++)
		{
			if (Entry[a] == 0)
			{
				q.push(a);
				dp[a] = Time[a];
			}

		}

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			for (int a = 0; a < Build[cur].size(); a++)
			{
				int next = Build[cur][a];
				dp[next] = max(dp[next], dp[cur] + Time[next]);
				Entry[next]--;

				if (Entry[next] == 0)
					q.push(next);
			}

		}

		int target;
		cin >> target;
		cout << dp[target] << "\n";


	}

}