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

int gcd(int a, int b) 
{
    int t;

    while (b) 
    {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}


bool arr[1001][1001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int C, N;
    cin >> C;

    arr[1][1] = 1;
    for (int a = 1; a <= 1000; a++)
        for (int b = 1; b <= 1000; b++)
            if (gcd(a, b) == 1) arr[a][b] = 1;
        
    

    while (C--)
    {
        cin >> N;
        int result = 2; 
        for (int a = 1; a <= N; a++)
        {
            for (int b = 1; b <= N; b++)
            {
                if (arr[a][b])  result++;
            }
        }

        cout << result << "\n";
    }

    return 0;
}