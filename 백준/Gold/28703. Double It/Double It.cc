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

priority_queue<int> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
   
	int n, num;
	cin >> n;

	for(int a = 0; a < n; a++)
    {
		cin >> num;
		max_pq.push(num);
		min_pq.push(num);
	}
	
	int limit = max_pq.top();
	int dif = MAXX;
	while(min_pq.top() <= limit)
    {
		int mn = min_pq.top();
		int mx = max_pq.top();
		dif = min(dif, mx-mn);
		min_pq.pop();
		min_pq.push(mn*2);
		max_pq.push(mn*2);
	}
	cout << dif;
}