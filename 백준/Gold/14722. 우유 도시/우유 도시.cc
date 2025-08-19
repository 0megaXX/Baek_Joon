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

int milk[1001][1001];  // 좌표 
int dp[3][1001][1001]; // 우유타입, 좌표

int dx[] = {0, -1};
int dy[] = {-1, 0};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N; 

	for(int a = 0; a < N; a++)
		for(int b = 0; b < N; b++)
        {
			cin >> milk[a][b];

			if(milk[a][b] == 0) // 0에서 시작
				dp[0][a][b] = 1;
			
		}
	

	for(int x = 0; x < N; x++)
    {
		for(int y = 0; y < N; y++)
        {
			for(int d = 0; d < 2; d++){
				int bx = x + dx[d]; // 이전 x 
				int by = y + dy[d]; // 이전 y
                
				if(bx < 0 || bx >= N || by < 0 || by >= N)  // 벗어나면 컨티뉴
                    continue;

				int curMilk = milk[x][y]; // 현재 우유의 타입
				int beforeMilk = (curMilk + 2) % 3; // 이전 마셨던 우유의 타입

				// 우유를 마실 수 없는 경우 현재 위치까지의 누적 우유 vs 이전까지 마시고 그냥 걸어온 우유
				dp[0][x][y] = max(dp[0][x][y], dp[0][bx][by]); 
				dp[1][x][y] = max(dp[1][x][y], dp[1][bx][by]);
				dp[2][x][y] = max(dp[2][x][y], dp[2][bx][by]);

				 
				if(dp[beforeMilk][bx][by] > 0) // 이전에 다른 우유를 마셔 우유를 마실 수 있는 경우
					dp[curMilk][x][y] = max(dp[curMilk][x][y], dp[beforeMilk][bx][by] + 1);
				
			}
		}
	}

	int rs = max( {dp[0][N - 1][N - 1], dp[1][N - 1][N - 1] , dp[2][N - 1][N - 1] });
	cout << rs; 
    
   
    return 0;
}

