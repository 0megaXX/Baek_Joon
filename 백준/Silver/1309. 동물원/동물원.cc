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
using namespace std;

unsigned long long dp[100001]{1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	dp[1] = 3;
	
		int want;
		cin >> want;
		for(int b=2;b<=want;b++)
		{
			dp[b] = (dp[b - 1] * 2 + dp[b - 2]) % 9901;
		}
		cout << dp[want];
		
}
