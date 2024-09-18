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


vector<int> graph[2001];

bool visit[2001] = { 0 };


bool True = false; //  5명 연속 친구인지 확인하는 변수


void DFS(int cur_node, int cnt)  // cnt는 깊이 
{
	if (cnt == 4) // 5명 연속 친구라면
	{
		True = true;
		return;
	}



	for (int a = 0; a < graph[cur_node].size(); a++)
	{
		int next = graph[cur_node][a]; // 다음갈곳
		if (visit[next] == false) // 현재 위치에서 간적이 없다면
		{
			visit[next] = true;
			DFS(next, cnt + 1);
			visit[next] = false;
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int N, M;
	cin >> N >> M;

	for (int a = 0; a < M; a++)
	{
		int b, c;
		cin >> b >> c;
		graph[b].push_back(c);
		graph[c].push_back(b);
	}


	for (int a = 0; a < N; a++)
	{


		visit[a] = true;
		DFS(a, 0);
		visit[a] = false;



		if (True) //  5명 연속 친구라면
		{
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}