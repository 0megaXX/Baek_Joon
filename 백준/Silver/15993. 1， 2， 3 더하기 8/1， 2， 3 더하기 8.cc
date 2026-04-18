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

int dp[100001][2];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    dp[1][1] = dp[2][1] = dp[2][0] = dp[0][0] = 1;
   
    int t;
    cin >> t;
    for(int a = 3; a <= 100000; a++)
    {
        dp[a][0] = ((dp[a - 1][1] + dp[a - 2][1]) % 1000000009 + dp[a - 3][1]) % 1000000009;
        dp[a][1] = ((dp[a - 1][0] + dp[a - 2][0]) % 1000000009 + dp[a - 3][0]) % 1000000009;
    }

    int n;
    while(t--)
    {
        cin >> n;
        cout << dp[n][1] << " " << dp[n][0] << "\n";
    }
    return 0;
}