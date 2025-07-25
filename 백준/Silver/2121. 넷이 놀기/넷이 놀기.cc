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


set<pair<int, int>> Set;
vector<pair<int, int>> v;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
	int x, y;
    
	cin >> n >> x >> y;
	v.resize(n);
    
	for (int a = 0; a < n; a++) 
    {
		cin >> v[a].first >> v[a].second;
		Set.insert({ v[a].first,v[a].second });
	}
    
	int f, s;
	int rs = 0;
    
	for (int a = 0; a < n; a++) 
    {
		f = v[a].first;
		s = v[a].second;

        // 이미있다면 증가x
		if (Set.find({ f + x,s }) == Set.end())
            continue;
        
		if (Set.find({ f,s + y }) == Set.end())
            continue;
        
		if (Set.find({ f + x,s + y }) == Set.end())
            continue;
        
		rs++;
	}
    
	cout << rs;
	return 0;
}