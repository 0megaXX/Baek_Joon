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

long long dp[31][31];

void fn()
{

	for (int a = 1; a <= 30; a++)
	{
		dp[a][1] = 1;
		dp[a][a] = 1;
		for (int b = 2; b < a; b++)
			dp[a][b] = dp[a - 1][b - 1] + dp[a - 1][b];
	}


}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, 0, sizeof(dp));
	fn();
	int floor, start, range;
	cin >> floor >> start >> range;
	long long summ = 0;
	int ss = 1;
	for (int a = floor; a < floor+range; a++)
	{
		for (int b = start; b < start+ss; b++)
		{
			summ+= dp[a][b] ;
		}
		ss++;
	}
	cout << summ;
	
		 
}
