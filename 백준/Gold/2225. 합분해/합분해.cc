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
unsigned long long dp[201][201];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sizz, summ;
	cin >> sizz >> summ;
	for (int c = 1; c <= summ; c++)
	{
		for (int a = 0; a <= sizz; a++)
		{
				if (a == 0)
					dp[c][0] = 1;
				else
					dp[c][a] = (dp[c - 1][a] + dp[c][a - 1]) % 1000000000;

		}
	}
	cout << dp[summ][sizz]%1000000000;


}

