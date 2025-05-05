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
	
	int dot = 2;
	int n;
	cin >> n;

	while (n--) 
		dot = dot * 2 - 1;
	cout << dot * dot;

}

 