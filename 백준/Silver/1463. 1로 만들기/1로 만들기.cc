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
#include <numeric>
using namespace std;



int dp[3000001]{ 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int want;
	cin >> want;
	dp[1] = 0;

		for (int i = 1; i < want; i++)
		{

			if (dp[i * 2] == 0)
				dp[i * 2] = dp[i] + 1;
			else
				dp[i * 2] = min(dp[i] + 1, dp[i * 2]);

			if (dp[i +1] == 0)
				dp[i+1] = dp[i] + 1;
			else
				dp[i + 1] = min(dp[i] + 1, dp[i + 1]);

		    if(dp[i * 3] == 0)
				dp[i*3] = dp[i] + 1;
			else
				dp[i * 3] = min(dp[i] + 1, dp[i * 3]);


			
		}

		cout << dp[want];




	
}