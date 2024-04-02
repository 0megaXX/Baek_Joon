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


int summ[101];
int dp[101][51];


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	memset(summ, 0, sizeof(summ));
	cin >> n >> m;
	for (int a = 1; a <= n; a++) {
		int x;
		cin >> x;
		summ[a] = x + summ[a - 1];
	}

	for (int a = 1; a <= m; a++) //모든 구간이 0개일때는 값이 존재하지 않는 정도여야힘.
		dp[0][a] = -9999999;



	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= m; b++) {
			dp[a][b] = dp[a - 1][b];
			for (int k = 1; k <= a; k++) {
				if (k >= 2)
					dp[a][b] = max(dp[a][b], dp[k - 2][b - 1] + summ[a] - summ[k - 1]);
				else if (k == 1 && b == 1)
					dp[a][b] = max(dp[a][b], summ[a]);
			}
		}
	}

	cout << dp[n][m];
}
