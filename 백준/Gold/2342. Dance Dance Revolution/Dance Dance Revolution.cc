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

#define INF 987654321
using namespace std;

vector<int>v;
int dp[1000001][5][5];

int dist(int cur, int next)
{
	if (!cur) return 2;
	if (cur == next) return 1;
	if (cur == 1 && (next == 2 || next == 4)) return 3;
	if (cur == 2 && (next == 1 || next == 3)) return 3;
	if (cur == 3 && (next == 2 || next == 4)) return 3;
	if (cur == 4 && (next == 1 || next == 3)) return 3;
	return 4;
}

int step(int count, int left, int right)
{
	if (count == v.size()) //다 밟았다면
		return 0;

	int& power = dp[count][left][right];

	if (power != -1)       //만약 이미 현재 위치를 밟은 기록이 있다면 재기록 x
		return power;

	power = INF;

	return power = min({ power,step(count + 1,v[count],right) + dist(left,v[count]),
		step(count + 1,left,v[count]) + dist(right,v[count]) });


}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	
	int next;
	cin >> next;
	while (next!=0)
	{
		v.push_back(next);
		cin >> next;
	}
	cout << step(0, 0, 0);
}
