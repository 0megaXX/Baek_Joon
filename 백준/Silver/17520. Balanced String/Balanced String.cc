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
#include <unordered_set>
#include <chrono>
#include <tuple>
#include <regex>

using namespace std;
#define MAXX 2147483647

long long dp[100010];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int n;
	cin >> n;

	dp[1] = 2;

	for (int a = 2; a <= n; a++)
    {
		if (a % 2 == 0)
			dp[a] = dp[a - 1];
		else
			dp[a] = (dp[a - 1] * 2) % 16769023;	
	}

	cout << dp[n] ;

    return 0;
}