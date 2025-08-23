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

    int K = 0, N = 0, M = 0;

    cin >> K >> N >> M;

    if (K * N > M)
        cout << K * N - M;
    else
        cout << 0;


    return 0;
}