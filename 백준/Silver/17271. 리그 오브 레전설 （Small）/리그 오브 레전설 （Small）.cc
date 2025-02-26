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


vector<int>dp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;
    cin>>n>>m;
    dp.resize(n+1);

    dp[0]=1;
    dp[1]=1;
    for (int a=2;a<=n ;a++ )
    {

        dp[a]=(dp[a-1]+dp[a]) % 1000000007;
        if(a>=m)
            dp[a] = (dp[a]+dp[a-m]) % 1000000007;
            
    }

    cout<<dp[n];
    
    
    return 0;
   
}


