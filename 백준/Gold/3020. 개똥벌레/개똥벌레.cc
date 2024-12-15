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

using namespace std;
#define MAXX 99999999


int arr[501][501];


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int n, h;
	cin >> n >> h;
	vector<int> bottom(h + 1, 0);
	vector<int> top(h + 1, 0);
	vector<int> rs(h + 1, 0);

	for (int a = 0; a < n / 2; a++) 
	{
		int b, c; 
		cin >> b >> c;
		bottom[b]++;
		top[h + 1 - c]++;
	}
	for (int a = h - 1; a >= 1; a--) 
		bottom[a] += bottom[a + 1];
	
	int min_num = MAXX;
	int ct = 0;
	for (int a = 1; a <= h; a++) {
		top[a] += top[a - 1];
		rs[a] += top[a] + bottom[a];

		if (min_num > rs[a]) 
		{
			ct = 1;
			min_num = rs[a];
		}
		else if (rs[a] == min_num)
			ct++;
	}
	cout << min_num << " " << ct;
}
