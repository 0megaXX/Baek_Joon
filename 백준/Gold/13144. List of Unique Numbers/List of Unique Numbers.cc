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

vector<int>v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	for (int a = 0; a < cass; a++)
	{
		int b;
		cin >> b;
		v.push_back(b);
	}

	int start = 0, endd = 0;
	long long rs = 0;

	map<int, int>m;

	m[v[start]] = 1;

	while (1)
	{
		while (endd<cass-1 && m[v[endd+1]] == 0 ) // 범위를 안벗어나고 다음 숫자가 포함이 안되어있다면
		{
			endd++; // 뒤로 이동
			m[v[endd]]++;  // 추가
		}

		if (start >= cass || endd >= cass) // 하나라도 끝나면 종료
			break;

		rs += endd - start + 1; // 경우의 수 추가
		m[v[start]]--; // 시작 위치는 포함 안할 예정이니 제거
		start++; // 시작위치 변경


	}

	cout << rs;
}
