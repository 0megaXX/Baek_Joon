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
    cin.tie(nullptr);


    int n;
    cin >> n;

    int ct = 0;
    for (int a = 1; a <= 500; a++)        // A
        for (int b = 1; b <= 500; b++)    // B
            if (a * a == b * b + n)
                ct++;


    cout << ct;

    return 0;
}