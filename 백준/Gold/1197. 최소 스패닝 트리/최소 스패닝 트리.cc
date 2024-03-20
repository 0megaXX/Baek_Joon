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
int parent[10001];

int find_parent(int x) 
{
	if (parent[x] == x) // 현재 위치의 부모가 자기자신이면 더 찾을수 없음.
		return x;
	else 
		return parent[x] = find_parent(parent[x]); //아니라면 최상단 부모를 찾으로 탐색.
}

void change_parent(int x, int y) {
	x = find_parent(x);
	y = find_parent(y);
	parent[y] = x; // 뒤 부모를 앞 부모와 동일하게. 즉 연결
}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	int rs = 0;
	cin >> V >> E;
	vector<pair<int, pair<int, int>>>v;  // 거리 , 시작지점, 끝지점

	for (int a = 0; a < E; a++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		v.push_back({ cost,{ start,end } });
	}

	sort(v.begin(), v.end());
	
	for (int a = 1; a <= V; a++)
		parent[a] = a; //노드 a의 부모를 자기자신으로 초기화

	for (int a = 0; a < v.size(); a++)
	{
		if (find_parent(v[a].second.first)!= find_parent(v[a].second.second))//만약 시작점과 부모의 시작이 다르다면 . 즉 사이클이 형성 안되었다면
		{
			change_parent(v[a].second.first, v[a].second.second);
			rs += v[a].first;
		}
	}

	cout << rs;
}
