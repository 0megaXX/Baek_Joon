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

	int n, rt, cnt = 0;

	while (1) {
		cin >> n;
		if (!n)	//0 입력시 종료
			break;

		for (int i = n + 1; i <= 2 * n; i++) {
			rt = sqrt(i);
			if (rt == 1 && i != 1) {	//2,3인 경우
				cnt++;
				continue;
			}
			if (i % 2) {	//홀수일 경우
				for (int j = 2; j <= rt; j++) {
					if (!(i % j))
						break;
					if (j == rt) {
						cnt++;
					}
				}
			}
		}
		cout << cnt << '\n';
		cnt = 0;
	}
    return 0;
}

