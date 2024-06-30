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
using namespace std;


vector<int> small, large;
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    small.resize(min(n, m));
    large.resize(max(n, m));
     
    for (int a = 0; a < n; a++)
    {
        int input;
        cin >> input;
        (n <= m ? small : large)[a] = input;
    }
    for (int a = 0; a < m; a++)
    {
        int input;
        cin >> input;
        (m <= n ? small : large)[a] = input;
    }

    sort(small.begin(), small.end());
    sort(large.begin(), large.end());


    for (int a = 0; a <= small.size(); a++) 
        for (int b = 0; b <= large.size(); b++) 
            dp[a][b] = 987654321;
        
    

    dp[0][0] = 0;

    for (int a = 0; a <= small.size(); a++) 
        for (int b = a; b <= large.size(); b++) {
            if (a > 0 && b > 0) 
                dp[a][b] = min(dp[a][b], dp[a - 1][b - 1] + abs(small[a - 1] - large[b - 1]));
            
            if (b > 0) 
                dp[a][b] = min(dp[a][b], dp[a][b - 1]);
            
        }
    
    cout << dp[small.size()][large.size()] << endl;

    return 0;
}