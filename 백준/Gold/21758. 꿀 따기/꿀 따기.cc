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

int honey[100001]; // 해당 위치의 꿀량
int summ[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int cass;
	cin >> cass;
	int rs=0;
	for (int a = 1; a <= cass; a++)
	{
		cin >> honey[a];
		summ[a] = summ[a - 1] + honey[a]; // 누적합 생성
	}


	// 1. 벌 - 꿀통 - 벌
	for (int a = 2; a < cass; a++) 
	{
		int cur = (summ[a] - summ[1]) + (summ[cass - 1] - summ[a - 1]);
		rs = max(rs, cur);
	}

	// 2. 벌 - 벌 - 꿀통
	for (int a = 2; a < cass; a++)
	{
		int cur = (summ[cass] - summ[1] - honey[a]) + (summ[cass] - summ[a]);
		rs = max(rs, cur);
	}

	// 3. 꿀통 - 벌 - 벌
	for (int a = 2; a < cass; a++)
	{
		int cur = (summ[cass - 1] - honey[a]) + summ[a - 1];
		rs = max(rs, cur);
	}

	cout << rs;
}

