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


vector<int> cards; 
vector<int> dp;


int fn(int n) // Brian Kernighan algorithm
{
    int ct = 0;
    while (n > 0) 
    {
        n &= (n - 1);
        ct++;
    }
    return ct;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    cards.resize(n + 1);
    dp.resize(n + 1); 

    // 역순으로 입력 받기: cards[n] 부터 cards[1] 까지
    for (int a = n; a >= 1; a--) 
        cin >> cards[a];
    
    
    if (n >= 2) 
    {
        // xor 연산
        dp[2] = fn(cards[1] ^ cards[2]); 
        if (n >= 3) 
            dp[3] = fn(cards[1] ^ cards[2] ^ cards[3]);
        
        if (n >= 4)
            dp[4] = fn(cards[3] ^ cards[4]) + dp[2]; // 1개가 남으면 0점이기에 반드시 2개 2개로 해야함.
    }
    
    for (int a = 5; a <= n; a++) 
    {
        int xor1 = cards[a - 1] ^ cards[a]; // 2개 xor
        int xor2 = cards[a - 2] ^ cards[a - 1] ^ cards[a]; // 3개 xor
        
        dp[a] = max(dp[a - 2] + fn(xor1),dp[a - 3] + fn(xor2)); // 3개 + @와 2개 + @의 비트 수 비교.
    }

    cout << dp[n];


    return 0;
}

