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
#define MAXX 99999999

deque<int> dq;

int main() {

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; 
    cin >> N;
	dq.push_back(N);
    
	for (int a = N - 1; a> 0; a--) {
		dq.push_front(a);
		for (int b = 0; b < a; b++) 
        {
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}

	while (!dq.empty())
        {
		cout << dq.front() << ' ';
		dq.pop_front();
	}
}