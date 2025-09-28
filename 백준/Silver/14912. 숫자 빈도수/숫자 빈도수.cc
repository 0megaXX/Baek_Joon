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

    int n;
    char check;
    cin >> n >> check;
    int ct = 0;

    for (int a = 1; a <= n; a++) {
        string str = to_string(a);
        for (int b = 0; b < str.size(); b++)
            if (str[b] == check) 
                ct++;
            
        
    }
    cout << ct;

    return 0;
}