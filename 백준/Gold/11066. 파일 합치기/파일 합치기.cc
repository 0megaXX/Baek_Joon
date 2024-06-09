#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stddef.h>
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

int dp[501][501]{ 0 };
int sum[501]{0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	while (cass--)
	{
		//memset(dp, 251001, 10001);

		int sizz;
		cin >> sizz;
		int sum_sub;
		for (int a = 1; a <= sizz; a++)
		{
			
			cin >> sum_sub;
			sum[a] = sum[a - 1] + sum_sub;
		}
		for(int a=1;a<sizz;a++)
		{
			int eend = 1;
			int start = a + 1;
			for (int b = 1; b <= sizz - a; b++)
			{
				dp[eend][start] = 1e9;
				for(int c=start-a;c<=start-1;c++)
					dp[eend][start]= min(dp[eend][start],
						dp[eend][c] + dp[c + 1][start] + sum[start] - sum[eend - 1]);
				start++;
				eend++;
			}
		}

		cout << dp[1][sizz] << "\n";
	}

}
