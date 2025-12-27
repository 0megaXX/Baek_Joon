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

map <string,string> m;

int fn(string s1, string s2)
{
    while (s1.size())
    {
        if (s1==s2)
            return 1;
        s1 = m[s1];
    }
    return 0;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    int n;
    cin >> n;
    string s1, s2;
   
    for (int a=0; a<n-1; a++)
    {
        cin >> s1 >> s2;
        m[s1] = s2;
    }
   
    cin >> s1 >> s2;

    // 같아지는 경우 연결됐다는 의미
    if (fn(s1, s2) || fn(s2, s1))
        cout << 1;
    else
        cout << 0;
   

    return 0;
}