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
#define MOD 987654321
using namespace std;


long long dp[10001];



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	dp[0] = dp[2] = 1;

	for (int a = 4; a <= cass; a += 2) 
		for (int b = 2; a - b >= 0; b += 2) 
			dp[a] = (dp[a] + (dp[b - 2] * dp[a - b]) % MOD) % MOD;
		
	
	cout << dp[cass];
}
