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



string s, ans;
int cnt0, cnt1;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> s;
    for (const char& c : s)
        if (c == '0')
            ++cnt0;


    cnt1 = s.size() - cnt0;
    cnt1 /= 2, cnt0 /= 2;
    for (const char& c : s)
    {
        if (c == '0')
        {
            if (cnt0-- > 0)
                ans.push_back('0');
        }
        else
        {
            if (cnt1-- > 0)
                continue;
            ans.push_back('1');
        }
    }

    cout << ans;

    return 0;
}