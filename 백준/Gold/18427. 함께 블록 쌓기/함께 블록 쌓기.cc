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

int N, M, H;
vector<vector<int>>v(51);
int dp[51][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp, 0, sizeof(dp));
	cin >> N >> M >> H;

	cin.ignore();
	for (int a = 1; a <= N; a++)
	{
		string s;
		getline(cin, s);
		stringstream ss(s);
		string sub;
		while (getline(ss, sub, ' '))
		{
			int c = stoi(sub);
			v[a].push_back(c);
		}
	}

	for (int a = 0; a <= N; a++)
		dp[a][0] = 1;


	for (int a = 1; a <= N; a++) //사람 수
	{
		for (int c = 1; c <= H; c++) //만들수있는 모든 수들
		{
			for (int b = 0; b < v[a].size(); b++) //사람이 갖고있는 수
			{

				if (c >= v[a][b])	
					dp[a][c] = (dp[a - 1][c - v[a][b]] + dp[a][c])%10007;
				
			}
			dp[a][c] = (dp[a - 1][c] + dp[a][c]) % 10007;

		}


	}




	cout << dp[N][H];


}