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
#include <unordered_map>

using namespace std;


long long Sum[301][301];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int a = 1; a <= n; a++) {
		for (int B = 1; B <= m; B++) {
			cin >> Sum[a][B];
			Sum[a][B] += Sum[a][B - 1] + Sum[a - 1][B] - Sum[a - 1][B - 1];
		}
	}
	int k;
	cin >> k;

	for (int A = 0; A < k; A++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << Sum[c][d] - Sum[a - 1][d] - Sum[c][b - 1] + Sum[a - 1][b - 1] << '\n';
	}

}