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



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n, r, summ;
    cin >> t;
    while (t--) 
    {
        cin >> n;
        summ = n;
        r = 0;
        while (n) 
        {
            r *= 10;
            r += n % 10;
            n /= 10;
        }
        summ += r;
        string s = to_string(summ);
        reverse(s.begin(), s.end());
        cout << (to_string(summ) == s ? "YES" : "NO") << '\n';
    }

    return 0;
}