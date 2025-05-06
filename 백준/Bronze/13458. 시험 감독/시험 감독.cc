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

vector <int> v;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long long n; 
	cin >> n;
	v.resize(n);
	for (int a  = 0; a < n; a++)
		cin >> v[a];
	int b, c; 
	cin >> b >> c;
	long long rs = n;
	for (int a = 0; a < n; a++)
	{
		v[a] -= b;  
		if (v[a] <= 0)
			continue;
		rs += v[a] / c;
		if (v[a] % c)
			rs += 1;
	}
	cout << rs;

}

 