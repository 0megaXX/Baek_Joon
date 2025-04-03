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

using namespace std;
#define MAXX 2147483647


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    string a, b;
    cin >> a >> b;

    int start = 0;
    int minLen = min(a.length(), b.length());
    
    while (start < minLen && a[start] == b[start])
    {
        start++;
    }

    int eend = 0;

    while (eend < minLen && a[a.length() - 1 - eend] == b[b.length() - 1 - eend])
    {
        eend++;
    }
    
    if (start >= minLen - eend)
    {
        cout << (a.length() > b.length() ? 0 : b.length() - a.length());
    } 

    else 
    {
        cout << b.length() - eend - start ;
    }

    return 0;
}

