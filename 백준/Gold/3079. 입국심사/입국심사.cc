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


vector<unsigned long long > v;
unsigned long long n, m;

bool fn(unsigned long long mid) // mid 시간내로 모든 심사대에서 심사를 다 마치는지 여부
{
	unsigned long long number = 0;
	for (int a = 0; a < n; a++)
		number += (mid / v[a]); // mid 시간내로 v[a]의 사람이 몇번 들어갈 수 있는지 가산


	return (number >= m);// 들어가는 사람의 수가 가야하는 사람의 수 이상이라면 시간내로 전부 가능
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
//	v.resize(n, 0);

	unsigned long long low, high, rs;
	low =0;

	for (int a = 0; a < n; a++)
	{
		unsigned long long b;
		cin >> b;
		v.push_back(b);
	}

	sort(v.begin(), v.end());

	high = v[n-1] * m; // 최장시간

	rs = high; 

	while (low <= high)
	{
		unsigned long long mid = (low + high) / 2; // 절반시간

		if (fn(mid))  // 시간을 절반으로 줄여도 수용이 가능하다면
		{
			high = mid - 1;
			rs = mid;
		}
		else 
			low = mid + 1;
	}
	cout << rs;


}