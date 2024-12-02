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


vector<int>v(100001,1);

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k, b;
	cin >> n >> k >> b;
	
	for (int a = 0; a < b; a++)
	{
		int num;
		cin >> num;
		v[num]=0; // 부셔진 신호등은 0으로 취급.

	}
	
	
	for (int a = 2; a <= n; a++)
		v[a] += v[a - 1]; // 현 구간까지 있는 신호등의 수

	int maxx = 0;
	
	for (int a = k; a <= n; a++)
		maxx = max(maxx, v[a] - v[a - k]); // 길이가 k인 구간합의 최대합 (존재하는 신호등의 수)

	cout << k - maxx;
	
	
}