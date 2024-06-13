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
#include <unordered_map>


using namespace std;

long long dp[101][101];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int A, Z;
	cin >> A >> Z;
	int search_target;
	cin >> search_target;

	for (int a = 1; a <= A; a++)
		dp[a][0] = 1;
	for (int b = 1; b <= Z; b++)
		dp[0][b] = 1;

	for (int a = 1; a <= A; a++)
		for (int b = 1; b <= Z; b++)
		{
			dp[a][b] = dp[a - 1][b] + dp[a][b - 1];
			if (dp[a][b] > 1000000000) dp[a][b] = 1000000000;
		}

	int range = A + Z;

	if (search_target > dp[A][Z])
	{
		cout << -1;
		return 0;
	}


	for (int a=0;a<range;a++)
	{
		if (A == 0)
		{
			cout << 'z';
			Z--;
			continue;
		}

		else if (Z == 0)
		{
			cout << 'a';
			A--;
			continue;
		}
		
		int Start_Is_A = dp[A - 1][Z];
		int Start_IS_Z = dp[A][Z - 1];

		if (search_target <= Start_Is_A)
		{
			cout << 'a';
			A--;
		}

		else
		{
			cout << 'z';
			
			search_target -= dp[A - 1][Z];
			Z--;
		}







	}

	return 0;
}