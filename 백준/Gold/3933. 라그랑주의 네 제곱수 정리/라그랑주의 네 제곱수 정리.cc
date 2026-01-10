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

int dp[5][50001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   
    dp[0][0] = 1;
    for (int a = 1; a * a < 50001; a++)
        for (int b = 1; b < 5; b++)
            for (int c = a * a; c < 50001; c++)      
                dp[b][c] += dp[b - 1][c - a * a];

    int n;
    cin >> n;
   
    while (n)
    {
        cout << dp[1][n] + dp[2][n] + dp[3][n] + dp[4][n] << '\n';
        cin >> n;
    }

    return 0;
}