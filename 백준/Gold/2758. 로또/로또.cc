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


long long dp[2001][11]; //dp[x][y] = 마지막 숫자가 x면서 y개의 숫자를 뽑은 경우의 수

void init()
{

    for (int a = 1; a < 2001; a++)
    {
        for (int b = 1; b < 11; b++)
        {
            if (b == 1) // 1개의 숫자를 넣는 경우 기본 1개
            {
                dp[a][b] = 1;
                continue;
            }
            if (a < pow(2, b - 1)) 
                break;

            // 1개 덜넣고 마지막이 절반 이하를 만드는 경우의 수들을 가산.
            for (int k = 1; k < a / 2 + 1; k++) 
                dp[a][b] += dp[k][b - 1];
            
        }
    }

    
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N, M;

    cin>>T;

    init(); 
    

    while(T--)
    {
        cin >> N >> M;

        long long summ = 0;
        
        for (int a = 1; a < M + 1; a++) 
            summ += dp[a][N];
        
        cout << summ << "\n";
    }


    return 0;
}

