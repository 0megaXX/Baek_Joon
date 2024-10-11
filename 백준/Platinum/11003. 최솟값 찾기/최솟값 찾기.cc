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

int cass, dif;
vector<int>v;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> cass;

	cin >> dif;


	for (int a = 0; a < cass; a++)
	{
		int b;
		cin >> b;
		v.push_back(b);
	}


	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<>>pq;
	// < 값, 순서 >의 오름차순 우선순위큐
	for (int a = 0; a < cass; a++)
	{
		pq.push({ v[a],a });  // 값과 순서 삽입

		if (pq.size() < dif)  // 차이보다 양이 적다면 그냥 출력 가능
			cout << pq.top().first << ' ';

		else
		{
			if (pq.top().second <= a - dif) // 우선순위큐에서 가장 작은 값이 사용할 범위에서 벗어났다면
				while (pq.top().second <= a - dif) // 가장 작은 값이 범위에 있을때까지 pop
					pq.pop();

			cout << pq.top().first << ' '; // 가장 작은값 출력

		}

	

	}

	return 0;
}