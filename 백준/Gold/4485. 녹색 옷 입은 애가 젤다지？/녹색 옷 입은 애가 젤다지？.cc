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
#include <unordered_map>


using namespace std;

int arr[126][126];
int dp[126][126];
int dx[4]{ -1,1,0,0 };
int dy[4]{ 0,0,1,-1 };


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int size;
	cin >> size;
	int cass = 0;
	while (size != 0)
	{
		cass++;
	//	memset(arr, 0, sizeof(arr));
	//	fill_n(dp[0],(126 * 126), 987654321);

		for (int a = 0; a < size; a++)
			for (int b = 0; b < size; b++)
			{
				dp[a][b] = 98765432;
				cin >> arr[a][b];
			}

		priority_queue<pair<int, pair<int, int>>>pq;
		pq.push(make_pair(-arr[0][0], make_pair(0, 0)));
		dp[0][0] = arr[0][0];
		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			int nx, ny;
			for (int a = 0; a < 4; a++)
			{
				nx = x + dx[a];
				ny = y + dy[a];
				if (nx >= 0 && ny >= 0 && nx < size && ny < size)
				{
					int cur_cost = cost + arr[nx][ny];
					if (dp[nx][ny] > cur_cost)
					{
						dp[nx][ny] = cur_cost;
						pq.push(make_pair(-dp[nx][ny], make_pair(nx, ny)));
					}
				}
			}
		}


		cout << "Problem " << cass << ": " << dp[size-1][size-1] << '\n';
		cin >> size;
	}
	return 0;
}