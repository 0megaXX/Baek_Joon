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

using namespace std;
#define MAXX 2147483647


vector<int> v;

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n;
	cin >> n;

	v.resize(n);
	for (int a = 0; a < n; a++)
		cin >> v[a];

	sort(v.begin(), v.end());

	int score = 0;
	long long rs = 0;
	for (auto& a : v) 
    {
		if (a <= score)
			continue;
		
		score++;

		if (score < a)
			rs += a - score;
	}

	cout << rs;
	return 0;

}