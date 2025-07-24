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


long long n;
vector<long long> v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    
    for (int a = 0; a < n; a++)
    {
        int num;
        cin >> num;
        long long summ = 0;
        while (num--)
        {
            long long t; cin >> t;
            summ += t;
        }
        v.push_back(summ);
    }

    sort(v.begin(), v.end());

    long long ans = 0;
    for (int a = 0; a< n; a++)
        ans += v[a] * (n - a);
    
    cout << ans;

    
    return 0;
}

