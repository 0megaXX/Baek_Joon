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



vector<vector<int>>v(51);
int root, del_node;;
int Parent[51];
int ct = 0;


void dfs(int node)
{

	if (node == del_node) // 만약 삭제된 노드라면 탐색중지
		return;

	if (v[node].size() == 0) // 리프노드면 카운터 증가
	{	
		ct++;
		return;
	}

	for (int a = 0; a < v[node].size(); a++)
	{
		if (v[node].size() == 1 && v[node][a] == del_node) // 자식이 있지만 그 자식이 삭제될 노드라면
		{
			ct++;
			return;
		}
		dfs(v[node][a]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int node;
	cin >> node;
	for (int a = 0; a < node; a++)
	{
		int parent;
		cin >> parent;
		if (parent == -1) // -1 이면 루트노드
			root = a;
		else
			v[parent].push_back(a); // 아니라면 부모임
	}

	cin >> del_node;

	dfs(root);

	cout << ct;
}