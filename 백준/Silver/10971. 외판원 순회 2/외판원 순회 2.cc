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




bool ch[11] = { 0, };
int n = 0, ans = MAXX;
int v[10][10];

void fn(int start, int index, int cnt, int sum)
{
	if (cnt == n) {
		if (v[index][start] == 0)
			return; // 중요
		if (ans > sum + v[index][start]) 
			ans = sum + v[index][start];
		return;
	}
	for (int a = 0; a < n; a++) {
		if (ch[a] || v[index][a] == 0) continue;
		ch[a] = true;
		fn(start, a, cnt + 1, sum + v[index][a]);
		ch[a] = false;
	}
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
	for (int a = 0; a < n; a++) 
		for (int b = 0; b < n; b++) 
			cin >> v[a][b];
		
	
	for (int a = 0; a < n; a++) 
	{
		ch[a] = true;
		fn(a, a, 1, 0); //출발지점, 현재 위치, 지나간 수, 이동비용
		ch[a] = false;
	}
	cout << ans ;

    return 0;
}