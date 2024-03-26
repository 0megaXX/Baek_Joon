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

vector<int> arr[100001];
bool visit[100001];
bool finished[100001]; // 사이클 확인을 위한 배열
int cnt;

void dfs(int node) {
	visit[node] = true;
	int next = arr[node][0];

	if (!visit[next]) //연결된 다음 노드를 방문 안했다면
		dfs(next);
	
	else if (!finished[next]) {
		// 사이클을 찾았을 경우
		for (int i = next; i != node; i = arr[i][0]) {
			cnt++;
		}
		cnt++; // 사이클을 이루는 노드 수를 카운트
	}

	finished[node] = true; // 현재 노드의 처리가 끝났음을 표시
}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	while (cass--)
	{
		int people;
		cin >> people;
		for (int a = 1; a <= people; a++)
		{
			arr[a].clear();
			visit[a] = finished[a] = false;
		}

		for (int a = 1; a <= people; a++)
		{
			int b;
			cin >> b;
			arr[a].push_back(b);
		}


		cnt = 0;
		for (int a = 1; a <= people; a++) {
			if (!visit[a])
				dfs(a);
		}

		cout << people - cnt << '\n'; // 전체 노드 수에서 사이클을 이루는 노드 수를 빼서 출력
	}
}
