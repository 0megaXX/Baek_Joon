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

char arr[100][100];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int t, len, sizz;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		len = s.length();
		sizz = sqrt(len);
		for (int a = 0; a < sizz; a++)
			for (int b = 0; b < sizz; b++)
				arr[a][b] = (char)s[sizz * a + b];

		for (int a = 0; a < sizz; a++)
			for (int b = 0; b < sizz; b++)
				cout << arr[b][sizz - a - 1];
		cout << '\n';
	}

    return 0;
}