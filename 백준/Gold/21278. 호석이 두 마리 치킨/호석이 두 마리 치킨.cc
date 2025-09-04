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
#define MAXX 214748364
//#define MAXX 2147483647

int dp[101][101];
int ans_time = MAXX;

int n, m;

void floyd()
{

    for (int c = 1; c <= n; c++) 
        for (int a = 1; a <= n; a++) 
            for (int b = 1; b <= n; b++) 
                dp[a][b] = min(dp[a][b], dp[a][c] + dp[c][b]);

    
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   
    cin >> n >> m;

	for (int a = 0; a <= n; a++) 
		for (int b = 0; b <= n; b++)
        {
			if (a == b) 
				continue;
			
			else 
				dp[a][b] = MAXX;		
		}
	

	for (int a = 0; a < m; a++) 
    {
		int b, c;
		cin >> b >> c;
		dp[b][c] = 1;
		dp[c][b] = 1;
	}

	
	floyd();
    
	pair<int, int> ans;
	
	for (int a = 1; a <= n; a++)
    {
		for (int b = a + 1; b <= n; b++)
        {
			int tmp_time = 0;
			for (int k = 1; k <= n; k++) // 왕복길이 합 갱신
				tmp_time += min(dp[k][a] * 2, dp[k][b] * 2); 
			
			if (ans_time > tmp_time) 
            {
				ans_time = tmp_time;
				ans = make_pair(a, b);
			}
		}
	}

    cout << ans.first << " " << ans.second << " " << ans_time;
    return 0;
}

