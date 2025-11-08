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

vector <pair<long long,long long>> v;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, t;    
    cin >> n >> t;
    v.resize(n);
   
    for(int a = 0; a < n; a++)
    {
        long long w,p;
        cin >> w >> p;
        v[a] = {p,w};
    }
   
    sort(v.begin(),v.end());
    long long rs = 0;
   
    for(int a = 0; a < n; a++)
    {
        long long w = v[a].second;
        long long p = v[a].first;
        rs += w + p * (a + t - n);
    }
    cout << rs;
   

    return 0;
}