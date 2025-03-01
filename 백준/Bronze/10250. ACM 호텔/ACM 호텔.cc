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

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	int h, w, n, y, x;

	for (int a = 0; a < t; ++a) {
		cin >> h >> w >> n;

		x = n / h + 1;
		y = n % h;

		if (y == 0)
		{
			y = h;
			x -= 1;
		}

		printf("%d%02d\n", y, x);
	}

    return 0;
}

