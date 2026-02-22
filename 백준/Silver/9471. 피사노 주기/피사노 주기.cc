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

int fn(int m) {
	int ct = 0, m1 = 0, m2 = 1;
	do {
		int tmp = m1;
		m1 = m2;
		m2 = (tmp + m1) % m;
		ct++;
	} while (m1 != 0 || m2 != 1);   


	return ct;
}



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int p;
	cin >> p;
	for (int a = 0; a < p; a++) {
		int n, m;
		cin >> n >> m;
		cout << n << " " << fn(m) << endl;
	}

    return 0;
}