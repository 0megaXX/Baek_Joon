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

#define MAXX 987654321
using namespace std;

string s;
map<set<string>, int> Set;

void dfs(int left, int right, string now, set<string> temp)
{
    if (now.length() >= s.length()) {
        if (now == s) Set[temp] = 1;
        return;
    }
    if (left > 0) {
        temp.insert(s[left - 1] + now);
        dfs(left - 1, right, s[left - 1] + now, temp);
        temp.erase(s[left - 1] + now);
    }
    if (right < s.length()) {
        temp.insert(now + s[right + 1]);
        dfs(left, right + 1, now + s[right + 1], temp);
        temp.erase(now + s[right + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (int a = 0; a < s.length(); a++)
    {
        string temp = "";
        set<string> set_temp = { temp + s[a] };
        dfs(a, a, temp + s[a], set_temp);
    }
    cout << Set.size();
}