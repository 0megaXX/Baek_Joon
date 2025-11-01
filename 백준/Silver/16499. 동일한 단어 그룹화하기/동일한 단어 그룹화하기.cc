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


map<string,int> Map;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int n;
    cin >> n;
    for(int a = 0; a < n; a++)
    {
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        Map[s] = 1;
    }
    cout << Map.size();

    return 0;
}