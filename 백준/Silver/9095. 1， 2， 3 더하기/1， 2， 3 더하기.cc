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
#include <numeric>
#include <stack>

using namespace std;



int dp[15]{ 0,1,1,1 };



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    for (int a = 1; a <= 12; a++)
    {
        dp[a + 1] = max(dp[a + 1] + 1, dp[a] + dp[a + 1]);
        dp[a + 2] = max(dp[a + 2] + 1, dp[a] + dp[a + 2]);
        dp[a + 3] = max(dp[a + 3] + 1, dp[a] + dp[a + 3]);

    }
    int b;
    cin >> b;
    while (b--)
    {
        int c;
        cin >> c;
        cout << dp[c] <<"\n";
    }
    
}