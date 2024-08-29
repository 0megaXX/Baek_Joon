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

#define MAXX 987654321
using namespace std;

vector<pair<int, int>>v;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;

	for (int a = 0; a < cass; a++)
	{

		int b, c;
		cin >> b >> c;
		v.push_back({ b,c });
	}

	sort(v.begin(), v.end());

	priority_queue<int, vector<int>, greater<>>pq;
	pq.push(v[0].second);

	int rs = 1; // 
	for (int a = 1; a < cass; a++)
	{
		int start = v[a].first;
		int eend = v[a].second;

		while (!pq.empty() && pq.top()<=start)
			pq.pop();

		pq.push(eend);
		rs = max(rs, (int)pq.size());
	}
	
	cout << rs;
}
