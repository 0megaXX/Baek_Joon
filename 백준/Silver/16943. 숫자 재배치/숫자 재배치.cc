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

vector<char> v;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int num;
    cin >> s >> num;

    sort(s.begin(), s.end());

    int maxAns = 0;

    do 
    {

        int number = stoi(s);

        if (s[0] == '0')
            continue;

        if (number < num) 
            maxAns = number;
        

    } while (next_permutation(s.begin(), s.end()));

    if (maxAns != 0) 
        cout << maxAns << "\n";
    
    else 
        cout << -1 << "\n";
    

    return 0;
}