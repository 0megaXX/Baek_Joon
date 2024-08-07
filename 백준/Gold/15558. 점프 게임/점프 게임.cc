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


int dp[2][100001];
int arr[2][100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int len, k;
	cin >> len >> k;

	for (int a = 0; a < 2; a++)
		for (int b = 0; b < len; b++)
			dp[a][b] = MAXX;

	for(int a=0;a<2;a++)
		for (int b = 0; b < len; b++)
		{
			char c;
			cin >> c;
			arr[a][b] = c - '0';
		}

	dp[0][0] = 0;

	queue<pair<int, pair<int, int>>>q;
	q.push({ 0,{0,0} });
int ct = 0;
	while (!q.empty())
	{
		int sizz = q.size();
		for (int a = 0; a<sizz; a++)
		{
			int cur_cost = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			if (y + k >= len)
			{
				cout << 1;
				exit(0);
			}
			if (y+1>ct && arr[x][y + 1] == 1 && dp[x][y + 1] > cur_cost + 1) // 한칸 전진
			{
				dp[x][y + 1] = cur_cost + 1;
				q.push({ cur_cost + 1,{x,y + 1} });
			}

			if (y + k > ct && x == 0 && arr[x + 1][y + k] == 1 && dp[x + 1][y + k] > cur_cost + 1) // 반대로 넘어가서 k칸 전진
			{
				dp[x + 1][y + k] = cur_cost + 1;
				q.push({ cur_cost + 1,{x + 1,y + k} });
			}

			if (y + k > ct && x == 1 && arr[x - 1][y + k] == 1 && dp[x - 1][y + k] > cur_cost + 1)// 반대로 넘어가서 k칸 전진
			{
				dp[x - 1][y + k] = cur_cost + 1;
				q.push({ cur_cost + 1,{x - 1,y + k} });
			}

			if (y - 1 > ct && y != 0 && arr[x][y - 1] == 1 && dp[x][y - 1] > cur_cost + 1) // 한칸 후진
			{
				dp[x][y - 1] = cur_cost + 1;
				q.push({ cur_cost + 1,{x,y - 1} });
			}
		}
		ct++;
	}

	/*for (int a = 0; a < 2; a++)
	{
		for (int b = 0; b < len; b++)
			cout << dp[a][b] << ' ';
		cout << endl;
	}*/


	cout << 0;

}