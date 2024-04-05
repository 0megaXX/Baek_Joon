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


using namespace std;

int arr[1001][1001];
int dp[1001][1001];

int row, col;



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, 0, sizeof(dp));
	cin >> row >> col;

	for (int a = 1; a <= row; a++)
	{
		for (int b = 1; b <= col; b++)
		{
			cin >> arr[a][b];
			if (arr[a][b] == 0)
				dp[a][b] = 1;
		}
	}
	int maxx = 0;
	for (int a = 1; a <= row; a++)
	{
		for (int b = 1; b <= col; b++)
		{
			if (arr[a][b] == 0)
			{
				dp[a][b] = min({ dp[a - 1][b],dp[a][b - 1],dp[a - 1][b - 1] }) + dp[a][b];
				maxx = max(maxx, dp[a][b]);

			}
		}
	}
	cout << maxx;
	/*cout << endl;
	for (int a = 1; a <= row; a++)
	{
		for (int b = 1; b <= col; b++)
		{
			cout << dp[a][b] << ' ';
		}
		cout<<endl;
	}*/
}
