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
    cin >> n;

    int ct = 0;
    int mx = 0, mn = 0;

    while (n--) 
    {
		int cur; 
        cin >> cur;
		if (cur == 1)
            ct++;
		else 
            ct--;
		mx = max(mx, ct);
        mn = min(mn, ct);
	}

	cout << mx - mn;

    return 0;
}

