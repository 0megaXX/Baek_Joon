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

priority_queue<pair<int, int>> pqL, pqR; // 좌, 우 탐색

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long ans = 0;
	int N, K, S; 
    cin >> N >> K >> S;
    
	while (N--) 
    {
		int x, w; 
        cin >> x >> w;
		if (x < S)
            pqL.push(make_pair(S - x, w));
            
		else if (x > S) 
            pqR.push(make_pair(x - S, w));
	}

	int bus = 0; // 탑승인원
	while (!pqL.empty()) 
    {
		auto cur = pqL.top();
        pqL.pop();
		if (bus + cur.second < K)
        {
			if (bus == 0) 
                ans += cur.first * 2;
			bus += cur.second;
		}
		else
        {
			if (bus)
            {
				cur.second -= K - bus;
				bus = 0;
			}
			ans += cur.first * 2 * (cur.second / K);
			cur.second %= K;
			if (cur.second)
            {
				bus = cur.second;
				ans += cur.first * 2;
			}
		}
	}

	bus = 0;
	while (!pqR.empty())
        {
		auto cur = pqR.top(); pqR.pop();
		if (bus + cur.second < K)
        {
			if (bus == 0) 
                ans += cur.first * 2;
			bus += cur.second;
		}
		else 
        {
			if (bus)
            {
				cur.second -= K - bus;
				bus = 0;
			}
			ans += cur.first * 2 * (cur.second / K);
			cur.second %= K;
			if (cur.second) 
            {
				bus = cur.second;
				ans += cur.first * 2;
			}
		}
	}

	cout << ans;

    return 0;
}