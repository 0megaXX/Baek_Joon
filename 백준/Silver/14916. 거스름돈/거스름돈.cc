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
#include <numeric> 
using namespace std;



int box[1001]{ 0 };
int dp[1001]{0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int coin;
	cin >> coin;
	int ct = 0;
	if (coin == 1 || coin == 3)
	{
		cout << -1;
		return 0;
	}
	while (coin != 0)
	{
		if (!(coin / 5 == 0))
		{
			ct += coin / 5;
			coin = coin % 5;
		}
		else if (!(coin / 2 == 0))
		{
			ct += coin / 2;
			coin = coin % 2;
		}
		else
		{
			
			coin += 3;
		}
		
	}
	cout << ct;
}

	