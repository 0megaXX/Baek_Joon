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

    int n, rs=0;

    cin >> n;

    for (int a = 1; a < n; a++) 
    {
        for (int b = a; b < n; b++) 
        {
            int k = n - a - b;

            if (b > k)
                break;
            if (a + b > k)
                rs++;
        }
    }
    cout << rs;

    return 0;
}