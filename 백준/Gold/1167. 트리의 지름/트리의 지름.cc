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



vector<vector<pair<int,int>>>rel(100001);
int Node;

int  Max_dist=0, maxNode; 
bool visit[100001]; 

void dfs(int node, int dist)
{
	// 방문한 노드면 return
	if (visit[node])
		return;

	// maxDist 갱신
	if (Max_dist < dist)
	{
		Max_dist = dist;
		maxNode = node;
	}
	visit[node] = true; //방문 체크

	for (int a = 0; a < rel[node].size(); a++)
	{
		int nextIndex = rel[node][a].first;
		int nextDist = rel[node][a].second;
		dfs(nextIndex, nextDist + dist);
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
		int start_node;
		cin >> start_node;

		int  end_node, degree;
		cin >> end_node;

		while (end_node!=-1)
		{
			cin >> degree;
			rel[start_node].push_back({ end_node,degree });
		//	rel[end_node].push_back({ start_node,degree });
			cin >> end_node;

		}

	}

	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	Max_dist = 0;

	dfs(maxNode, 0);

	cout << Max_dist;
		
}