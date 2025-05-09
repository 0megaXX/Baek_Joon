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

using namespace std;
#define MAXX 2147483647



vector<pair<int, int>> v;

int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int N;
    cin >> N;
    v.reserve(N);

    for (int a = 0; a < N; a++)
    {
        int b,c;
        cin >> b >> c;
        v.push_back({b,c});
    }
    
    long long ans = 0;
    for (int a = N - 2; a >= 0; a--)
        ans += (long long)v[a].first * v[a].second * v[N - 1].second;
    

    cout << ans;
    return 0;
    

    return 0;
}