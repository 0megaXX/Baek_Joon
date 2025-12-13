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

vector<int> v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int a, b, n;
	int rs = 0;

	cin >> a >> b >> n;
	if (a % b == 0) 
	{
		cout << 0;
		return 0;
	}

	if (a > b) 
		a = a % b;

	for (int i = 0; i < n; i++) {
		a *= 10;
		rs = (int)(a / b);
		a = a % b;
	}
	cout << rs;

    return 0;
}