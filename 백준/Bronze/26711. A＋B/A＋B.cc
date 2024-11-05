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
int N;
string A, B, ans;
int carry;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	while (A.length() < B.length()) A += "0";
	while (B.length() < A.length()) B += "0";
	int N = A.length();

	for (int i = 0; i < N; i++) {
		int cur = A[i] - '0' + B[i] - '0' + carry;
		if (cur > 9) carry = 1, cur -= 10;
		else carry = 0;
		ans += cur + '0';
	}

	if (carry) ans += '1';
	reverse(ans.begin(), ans.end());

	cout << ans;
}