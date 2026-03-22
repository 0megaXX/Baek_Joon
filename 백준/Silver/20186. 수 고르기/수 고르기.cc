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

vector<int>v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    cin >> n >> k;

    int ct = n - 1;

    for(int a = 0; a < n; a++)
    {
        int b;
        cin >> b;
        v.push_back(b);
    }

    sort(v.begin(), v.end());

    int ans = 0;
   
    for(int a = 0; a < k; a++)
        ans += (v[ct--] - a);

     cout<< ans;
   
    return 0;
}