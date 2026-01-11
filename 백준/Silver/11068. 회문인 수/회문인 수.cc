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

bool fn(int n) {
    for (int a = 2; a <= 64; a++) 
    {
        int num = n;
        string s;
        string ts;

        while (num != 0) 
        {
            s.push_back(num % a);
            num /= a;
        }

        for (int i = s.length() - 1; i >= 0; i--) 
            ts += s[i];
        

        if (s == ts) 
            return 1;
        
    }
    return 0;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        cin >> n;

        if (fn(n)) 
            cout << 1 << "\n";
        
        else 
            cout << 0 << "\n";
        

    }

    return 0;
}