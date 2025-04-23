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

int n, k, x;
vector<int> v;
vector<vector<bool>> dp;

void fn(int p) 
{
    for (int a = k - 1; a >= 1; a--) 
        for (int b = x * k; b >= p; b--) 
            if (dp[a][b - p]) 
                dp[a + 1][b] = true;
            
    dp[1][p] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> x;

    v.resize(n);
    dp.assign(k + 1, vector<bool>(x * k + 1, false));

    for (int i = 0; i < n; i++) 
    {
        int a, b;
        cin >> a >> b;  // a알면 b도 알음
        v[i] = a;
    }

    for (int p : v) 
        fn(p);
    

    int rs = 0;
    
    for (int a = 0; a <= x * k; a++) 
        if (dp[k][a]) 
            rs = max(rs, a * (x * k - a));
        
    
    cout << rs ;
    return 0;
}
