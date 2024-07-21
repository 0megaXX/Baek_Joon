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

string s;
int dp[1001][1001]{0};

bool KOI(char a, char b) // 시작문자인 a와 끝문자인 b를 통해 KOI가 되는지 확인
{
	if ((a == 'a' && b == 't') || (a == 'g' && b == 'c'))
		return 1;
	else
		return 0;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> s;
	int len = s.length();

	


	for (int dif = 1; dif < len; dif++) // 처음 문자와의 간격 (a-1)
	{
		for (int start = 0; start + dif < len; start++) //시작 위치
		{
			int end = start + dif;
			if (KOI(s[start], s[end])) //b번째 글자와 끝의 문자가 KOI 라면
				dp[start][end] = dp[start + 1][end - 1] + 2; // 두 문자 사이에 있는 KOI의 길이 + 두 문자를 포함한 길이 2 
			
			for (int mid = start; mid < end; mid++) // dp테이블 갱신 
				dp[start][end] = max(dp[start][end], dp[start][mid] + dp[mid + 1][end]);

		}

			
	}

	cout << dp[0][len - 1];

}
