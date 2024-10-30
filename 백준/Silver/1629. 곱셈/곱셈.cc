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

#define MAXX 1000000000
using namespace std;

long long a, b, c;

long long power(long long b)
{
	if (b == 0)
		return 1;

	else if (b == 1)
		return a % c;

	long long rs;
	rs = power(b / 2) % c;
	if (b % 2 == 0) return rs * rs % c;
	return rs* rs % c * a % c;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> a >> b >> c;
	cout << power(b);

    return 0;
}