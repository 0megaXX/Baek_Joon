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


int dp[31][31];

void func()
{
	for (int a=0; a < 31; a++)
	{
		dp[a][0] = 1;
		dp[a][a] = 1;
		for (int b = 1; b < a; b++)
			dp[a][b] = dp[a - 1][b - 1] + dp[a - 1][b];

	}


}
int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	func();
	int cass;
	cin >> cass;
	while (cass--)
	{
		int west, east;
		cin >> west >> east;
		cout << dp[east][west] << '\n';
	}
}
