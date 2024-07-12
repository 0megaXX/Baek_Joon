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
#define MAXX 987654321
using namespace std;

int dp[1001][1001]{ 0 };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string row, col;
	getline(cin, row);
	getline(cin, col);


	for (int a = 0; a <= row.size(); a++)
		dp[0][a] = a;
	for (int b = 0; b <= col.size(); b++)
		dp[b][0] = b;


	int maxx = 0;
	for (int a = 0; a < col.size(); a++)
	{
		for (int b = 0; b < row.size(); b++)
		{
			if (col[a] == row[b]) //만약 단어가 일치한다면
				dp[a + 1][b + 1] = dp[a][b]; //전에 완성한 문자에서 더 수정할 필요는 없음

			else // 단어가 다르다면 수정해야함
				dp[a + 1][b + 1] = min({ dp[a][b + 1], dp[a + 1][b] ,dp[a][b]})+1;


	


		}

	}


	cout << dp[col.length()][row.length()];

}
