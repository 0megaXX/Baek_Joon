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
#include <deque>
#include <numeric> 
using namespace std;


;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	vector<vector<int>>dp(15, vector <int>(15, 0));

	int cass;
	cin >> cass;

	for (int a = 0; a <= 14; a++)
		dp[0][a]=a;


	for (int a = 1; a <= 14; a++)
	{
		for (int b = 1; b <= 14; b++)
		{
			dp[a][b] = accumulate(&dp[a-1][0], &dp[a - 1][b]+1,0);

		}

	}


	for (int a = 0; a <cass; a++)
	{
		int x, y;
		cin >> x >> y;
		cout << dp[x][y] << "\n";;

	}

	
}

	