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


char c1[10001], c2[10001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t, n, k, c, rs;
    cin >> t;
    while (t--)
    {
        rs = 0;
        cin >> n >> k;
        while (n--)
        {
            cin >> c;
            rs += c / k;
        }
        cout << rs << '\n';
    }
    return 0;
}