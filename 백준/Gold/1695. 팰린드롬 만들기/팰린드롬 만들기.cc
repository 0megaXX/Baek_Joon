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
#define MAXX 987654321
using namespace std;

vector<int>v;
int dp[5001][5001]; 

int fn(int start, int end)
{

	if (start >= end) // 더이상 탐색을 진행할 수 없다는 것은 팰린드롬이 완성되었을 경우
		return 0;

	if (dp[start][end] != -1) // 이미 이 경우 팰린드롬을 완성한 적이 이미 있다면 정지
		return dp[start][end];
	
	int ct = 0;

	if (v[start] == v[end]) // 끝이 같다면
		ct = fn(start + 1, end - 1);
	else // 끝이 다르다면
	{
		ct = min(fn(start + 1, end), fn(start, end - 1)) + 1; 
		//맨뒤에 맨 앞글자를 삽입한 경우와, 맨 앞에 맨뒤의 글자를 삽입한 경우 중 편집횟수가 더 작은경우
	}

	return dp[start][end] = ct; // dp[시작글자][끝글자] 가 팰린드롬이 되기위한 삽입 횟수
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int len;
	cin >> len;
	for (int a = 0; a < len; a++)
	{
		int b;
		cin >> b;
		v.push_back(b);
	}
	for (int a = 0; a < len; a++)
		for (int b = 0; b < len; b++)
		{
			dp[a][b] = -1;
		}

	cout<<fn(0, len - 1);

}
