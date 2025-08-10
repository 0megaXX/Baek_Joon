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

pair<long long, long long> fn(long long x)
{
    long long Two = 0, Five = 0;

    for (long long a = 2; a <= x; a *= 2)
        Two += x / a;

    for (long long a = 5; a <= x; a *= 5)
        Five += x / a;

    return { Two, Five };
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    long long a, b;
    cin >> a >> b;
    pair<long long, long long> lhs = fn(a);
    pair<long long, long long> rhs = fn(b);
    pair<long long, long long> chs = fn(a - b);
    cout << min(lhs.first - rhs.first - chs.first, lhs.second - rhs.second - chs.second);

    return 0;
}