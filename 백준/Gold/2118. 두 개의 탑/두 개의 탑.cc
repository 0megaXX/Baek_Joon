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


vector<int>dist; // 누적합

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
	cin >> N;

    dist.resize(N+1);
    dist[0] = 0;
    
	for (int a = 1; a <= N; a++)
	{
		cin >> dist[a];
		dist[a] += dist[a - 1]; 
	}

	int l = 1;
	int r = 2;
	int rs = 0;
	while (l <= r && r <= N)
	{
		int ClockWise = dist[r] - dist[l - 1];
		int CounterClock = dist[N] - ClockWise;

		int tmp = min(ClockWise, CounterClock);
		rs = max(tmp, rs);

		if (ClockWise <= CounterClock)
			r++;
		
		else
			l++;
		
	}

	cout << rs;
    return 0;
}

