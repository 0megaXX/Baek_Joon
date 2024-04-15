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
#include <set>
using namespace std;


int dp[1001][1001]{ 0 };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string row, col;
	getline(cin, row);
	getline(cin, col);


	for (int a = 0; a <= row.size(); a++)
		dp[0][a] = 0;
	for (int b = 0; b <= col.size(); b++)
		dp[b][0] = 0;


	int maxx = 0;
	for (int a = 0; a < row.size(); a++)
	{
		for (int b = 0; b < col.size(); b++)
		{
			if (row[a] == col[b])
				dp[a + 1][b + 1] = dp[a][b] + 1;
			else
				dp[a + 1][b + 1] = max(dp[a][b + 1], dp[a + 1][b]);


			maxx = max(dp[a + 1][b + 1], maxx);


		}


	}
	cout << maxx;

}
