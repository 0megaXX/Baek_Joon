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

    long long n;
    long long num = 1;
    int ct = 1;
    while (cin >> n) {
        num = 1;
        ct = 1;
        while (1) 
        {
            num = num % n;
            if (num == 0) 
                break;
            
            num = (num * 10) % n + 1 % n; 
            ct++;
        }
        cout << ct << '\n';
    }

    return 0;
}