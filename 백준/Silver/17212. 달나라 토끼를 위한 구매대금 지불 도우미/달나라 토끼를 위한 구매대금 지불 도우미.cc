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


int dp[100010];

void fn(int start)
{
	for (int a = 0; a <= start; a++)
	{
		dp[a + 7] = min(dp[a] + 1, dp[a + 7]);
		dp[a + 5] = min(dp[a] + 1, dp[a + 5]);
		dp[a + 2] = min(dp[a] + 1, dp[a + 2]);
		dp[a + 1] = min(dp[a] + 1, dp[a + 1]);

	}
	


}
int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, 0, sizeof(dp));
	fill_n(dp,100010, 9999999);
	dp[0] = 0;
	int want;
	cin >> want;
	fn(want);
	cout << dp[want];
}
