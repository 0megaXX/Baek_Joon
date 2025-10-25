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

int N, K, arr[50001];
int dp[50001][101];

int fn(int cur, int ct)
{
    if (cur > N - 1 || ct > K) 
        return 0; //범위 및 삭제 횟수 체크

    int rs = 0;

    if (dp[cur][ct]) 
        return dp[cur][ct];

    if (arr[cur] % 2) 
        rs = max(rs, fn(cur + 1, ct + 1)); //홀수 
    else 
        rs = max(rs, fn(cur + 1, ct) + 1); //짝수 

    dp[cur][ct] = rs; //값 저장

    return 
        dp[cur][ct];
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> K;

    for (int a = 0; a < N; a++)
        cin >> arr[a];

    int rs = 0;

    for (int a = 0; a < N; a++) 
        rs = max(rs, fn(a, 0)); 

    cout << rs;

    return 0;
}