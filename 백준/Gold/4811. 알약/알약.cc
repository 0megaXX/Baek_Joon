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


using namespace std;

long long dp[31][31]; // dp[p][h]는 W 가 p개, H가 h개 남았을 때 만들 수 있는 개수
int ct;
void pick_half(int one, int half);

void fnc()
{
	for (int a = 0; a <= 30; a++)
		dp[0][a] = 1; //한쪽알이 없는 경우 반쪽짜리 알약이 몇개든 나오는 조합은 1개

	for (int p = 1; p <= 30; p++)
	{
		for (int h = 0; h <= 30; h++) {
			if (h == 0)
				dp[p][h] = dp[p - 1][1];
			else
				dp[p][h] = dp[p - 1][h + 1] + dp[p][h - 1];
		}
	}

}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	fnc();
	int cases;
	cin >> cases;
	while (cases!=0)
	{

	
		
		cout << dp[cases][0] << '\n';
		cin >> cases;
	}
}
