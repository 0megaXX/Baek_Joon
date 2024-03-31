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

long long dp[4][50001];
vector<long long>v(50001,0);


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	for (int a = 1; a <= cass; a++)
	{
		int b;
		cin >> b;
		v[a] =b+ v[a - 1];
	}
	int dif;
	cin >> dif;

	for (int a = 1; a <= cass; a++)
	{
		if (a / dif != 0)
		{
			for (int b = 1; b <= a / dif; b++)
			{
				if (b > 3)
					break;
				dp[b][a] = max(dp[b][a - 1], v[a] - v[a - dif]+dp[b-1][a - dif]);
				//cout << "dp[" << b << "][" << a << "] 의 값은 " << dp[b][a] << endl;
			}
		}
	}
	cout << dp[3][cass];
		 
}
