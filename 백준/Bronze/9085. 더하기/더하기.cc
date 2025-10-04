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

	int c, n, num;
	int summ = 0;
	cin >> c;
	for (int a = 0; a < c; a++) {
		cin >> n;
		for (int b = 0; b < n; b++) 
		{
			cin >> num;
			summ += num;
		}
		cout << summ << '\n';
		summ = 0;
	}

    return 0;
}