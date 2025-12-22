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



int n, rs = 0;
int visit[1001];
int rome[4] = { 1,5,10,50 };

void dfs(int m, int depth, int summ) {
	if (depth == n) {

		if (!visit[summ]) {

			visit[summ] = 1;
			rs++;
		}
		return;
	}
	for (int a = m; a < 4; a++)
		dfs(a, depth + 1, summ + rome[a]);
} 

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


	cin >> n;
	dfs(0, 0, 0);
	cout << rs;


    return 0;
}