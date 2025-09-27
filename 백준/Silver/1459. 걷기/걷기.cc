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

    long long X, Y, W, S;
    cin >> X >> Y >> W >> S;


    long long a = (X + Y) * W;
    long long b = min(X, Y) * S;
    b += min(abs(X - Y) * W, (abs(X - Y) % 2 == 1 ? (abs(X - Y) - 1) * S + W : abs(X - Y) * S));

    cout << min(a, b);

    return 0;
}