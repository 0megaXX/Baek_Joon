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

using namespace std;
#define MAXX 2147483647

int player[1001][2]; // [N][0] 일때 N번째 흑의 값, [N][1] 일때 N번째 백의 값
int dp[1001][16][16];
int N;

int dfs(int idx, int white, int black) {
    
	if (white == 15 && black == 15)  // 전부 다 찼다면 
        return 0;
    
	if (idx == N) //모두 시도했다면 
        return 0;
    
	if (dp[idx][white][black]) // 이미 있다면
        return dp[idx][white][black];
    
	int ans = 0;
    
	if (white < 15) // 백을 다 못채웠다면 백에 채워보기
		ans = dfs(idx+1, white + 1, black) + player[idx][0];
	
	if (black < 15) // 흑을 다 못채웠다면 흑에 채워보기
		ans = max(ans, dfs(idx + 1, white, black+1) + player[idx][1]);
	
	return
        dp[idx][white][black] = max(ans, dfs(idx + 1, white, black));
}


int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    

    int idx = 0;
	int w, b;


	while (scanf("%d %d", &w, &b) == 2) {
		player[idx][0] = w;
		player[idx++][1] = b;
	}


	N = idx;
	cout << dfs(0,0,0) ;

    return 0;
}