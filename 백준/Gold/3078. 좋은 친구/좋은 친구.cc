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
#define MAXX 987654321
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	string str;
	queue<int> q[21];
	long long ans = 0;

	cin >> n >> k;
	for (int a = 0; a < n; a++) {

		cin >> str;

		int len = str.length(); //이름의 길이

		while (!q[len].empty() && a - q[len].front() > k)  //이름의 길이에 맞는 큐가 존재하고 등수 차이가 k보다 크면
			q[len].pop();	 //맨 앞에있는 애 빼기
		
		ans += q[len].size(); //큐에 들어있는 개수 더하기
		q[len].push(a);

	}

	cout << ans;
}