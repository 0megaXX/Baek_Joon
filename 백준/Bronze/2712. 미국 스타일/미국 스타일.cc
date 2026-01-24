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


set<string> Set;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;

    double val;
    string s;
    for (int a = 0; a < t; a++) 
    {
        cin >> val >> s;

        cout << fixed;

        cout.precision(4);

        if (s == "kg") 
            cout << val * 2.2046 << " lb\n";
        
        else if (s == "lb") 
            cout << val * 0.4536 << " kg\n";
        
        else if (s == "l") 
            cout << val * 0.2642 << " g\n";
        
        else if (s == "g") 
            cout << val * 3.7854 << " l\n";
        
    }
    return 0;
}