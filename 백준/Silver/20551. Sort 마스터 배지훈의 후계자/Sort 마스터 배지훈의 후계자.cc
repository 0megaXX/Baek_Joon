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

vector<int> v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int a = 0; a < n; a++) 
    {
        int b;
        cin >> b;
        v.push_back(b);
    }
    sort(v.begin(), v.end());

    for (int a = 0; a < m; a++) 
    {
        int b;
        cin >> b;

        int ind = lower_bound(v.begin(), v.end(), b) - v.begin();
        if (ind != n && v[ind] == b) 
            cout << ind << "\n";
        
        else 
            cout << "-1\n";
        
    }

    return 0;
}