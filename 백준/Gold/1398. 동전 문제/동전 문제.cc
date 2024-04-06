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


int dp[101];

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	dp[0] = 0;
	for (int a = 1; a < 101; a++)
	{
		dp[a] = a;

		if (a >= 10)
			dp[a] = min(dp[a], dp[a - 10] + 1);
		if (a >= 25)
			dp[a] = min(dp[a], dp[a - 25] + 1);

	}

	int cass;
	cin >> cass;
	while (cass--)
	{

		long long a;
		cin >> a;
		int rs = 0;
		while (a)
		{
			rs += dp[a % 100];
			a /= 100;
		}
		cout << rs << '\n';

	}
}
