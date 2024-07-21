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

int parent[51];
vector<vector<int>>son(51);


int dfs(int start_node)
{
	if (son[start_node].size() == 0) // 자식이 없는 리프노드라면
	{
		return 1; // 최소 1분이 걸림
	}

	int min_time = 0;

	vector<int>v; // 현재 위치까지 최소 전화시간들에 대한 배열
	for (int a = 0; a < son[start_node].size(); a++) 
		v.push_back(dfs(son[start_node][a]));

	sort(v.rbegin(), v.rend()); // 내림차순 정렬
	
	for (int a = 0; a < v.size(); a++)
		min_time = max(min_time, v[a] + a); // 시간이 긴거부터 먼저 처리하여 최대시간을 줄임

	return min_time+1; // 올라가는거니 현재 노드의 모든 자식까지 전달하는 최소시간 + 1분

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N,gar;
	cin >> N>>gar;
	for (int a = 1; a < N; a++)
	{
		cin >> parent[a];
		son[parent[a]].push_back(a);

	}

	cout << dfs(0) - 1;
}
