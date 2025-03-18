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

int N, M; // 수용량, 갯수
int NN[31], MM[301];
int DP[31][301];
int ans = 0;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M;

	for (int a = 1; a <= M; a++) 
		cin >> NN[a] >> MM[a];
	

    // 배낭 알고리즘
    for (int a = 1; a <= M; a++)
		 for (int b = 0; b <= N; b++)
        {
			if (b - NN[a] >= 0) // 들어갈수 있다면
				DP[a][b] = max(DP[a - 1][b],  DP[a - 1][b - NN[a]] + MM[a]); // 들어간다고 그것이 꼭 최적은 아니다,		
			else // 없다면 기존 최대
				DP[a][b] = DP[a - 1][b];
			
			ans = max(ans, DP[a][b]);
		}
	

    cout<<ans;
}
