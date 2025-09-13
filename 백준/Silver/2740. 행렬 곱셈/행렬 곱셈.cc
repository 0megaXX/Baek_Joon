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


int arr1[100][100] = {};
int arr2[100][100] = {};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n, m, k;


	cin >> n >> m;
	for (int a = 0; a < n; a++)
		for (int b = 0; b < m; b++)
			cin >> arr1[a][b];


	cin >> m >> k;
	for (int a = 0; a < m; a++)
		for (int b = 0; b < k; b++)
			cin >> arr2[a][b];


	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < k; b++) {
			int mul = 0;

			for (int c = 0; c < m; c++)
				mul += arr1[a][c] * arr2[c][b];

			cout << mul << ' ';
		}
		cout << '\n';
	}

    return 0;
}