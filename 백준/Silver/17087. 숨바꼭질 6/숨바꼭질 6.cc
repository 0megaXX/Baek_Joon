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


int arr[100001];

int fn(int a, int b)
{
	if (b == 0) 
		return a;

	else 
		return fn(b, a % b);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n, s, x, rs;

	cin >> n >> s;

	for (int a = 0; a < n; a++)
	{
		cin >> x;
		x = abs(s - x);
		arr[a] = x;
	}

	rs = arr[0];

	for (int a = 1; a < n; a++)
		rs = fn(rs, arr[a]);
	

	cout << rs;

    return 0;
}