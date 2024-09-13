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

	int N, M, L;
	cin >> N >> M>>L;




	for (int a = 0; a < N; a++)
	{
		int b;
		cin >> b;
		v.push_back(b);
	}
	v.push_back(0);
	v.push_back(L);

	sort(v.begin(), v.end());

	int start = 1; 
	int eend = L-1;
	int rs = MAXX;

	int mid; // 휴게소를 지을 간격

	while(start <= eend)
	{
		int total = 0;
		mid = (start + eend) / 2;

		for (int a = 1; a < v.size(); a++)
		{
			int diff = v[a] - v[a - 1]; // 두 휴게소 사이의 간격
			
			int tmp = diff / mid; // 두 휴게소 사이에 현재 diff 간격으로 지을수 있는 갯수

			if (tmp > 0) // 휴게소를 추가로 짓는게 가능하다면
			{
				if (diff % mid == 0) // 나누어 떨어진다는 것은 휴게소 하나는 하나의 휴게소와 겹친다는 이야기
					total += tmp - 1;
				else
					total += tmp;
			}
		}


		if (total > M) // 총 지을수 있는 휴게소의 수가 증설예정의 휴게소보다 많다면 간격을 늘려야함
			start = mid + 1;

		else // 아니라면 간격을 줄여서 더 짓게 해야함
		{
			eend = mid - 1;

			
			rs= mid;
		
		
		}



	}

	cout << rs;
}