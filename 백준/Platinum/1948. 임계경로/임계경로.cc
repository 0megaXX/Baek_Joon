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


vector<vector<pair<int, int>>>son(10001); // 자식노드의 배열
int first[10001]; // 선행노드의 수    
int len[10001]; // 위치의 최대 도착시간
bool visit[10001]; //방문 체크
vector<vector<int>>v(10001); // @노드의 최장거리 선행노드 배열
int rs = 0; // 간선 수


void bfs(int end_node) // 도착 노드로부터 역추적
{

	queue<int>q;
	q.push(end_node);
	visit[end_node] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int a = 0; a < v[cur].size(); a++)
		{
			int before = v[cur][a]; // 현재 위치로 오는 최단노드의 선행 맴버
			rs++; // 연결된 노드는 방문 여부를 무시하고 체크
			if (!visit[before])
			{
				visit[before] = 1;
				q.push({ before });
			}

		
		}	
	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(len, 0, sizeof(len));
	memset(visit, false, sizeof(visit));
	memset(first, 0, sizeof(first));

	int city;
	cin >> city;
	int road;
	cin >> road;
	for (int a = 0; a < road; a++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		son[start].push_back({ end ,cost });
		first[end]++;

	}

	int start_node, end_node;
	cin >> start_node >> end_node;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq; // 거리가 낮은게 먼저 도착

	pq.push({ 0,start_node }); // 누적 길이, 현재 노드	

	while (!pq.empty())
	{
		int accumulate_cost = pq.top().first; // 누적 거리
		int cur = pq.top().second; // 현재 위치

		pq.pop();

		
		for (int a = 0; a < son[cur].size(); a++)
		{
			int next_node = son[cur][a].first;
			first[next_node]--; // 선행노드 하나 제거

			int sub = accumulate_cost + son[cur][a].second; // 현재 위치부터 연결된 다음 노드까지의 길이

			if (len[next_node] < sub) // 다음 노드까지의 최대 길이보다 sub의 길이가 더 길다면
			{

				len[next_node] = sub;
				v[next_node].clear();
				v[next_node].push_back(cur);
				//최장노드 테이블을 갱신
			}
			else if (len[next_node] == sub)
				v[next_node].push_back(cur);
				//최장노드 테이블에 추가

			if (first[next_node] == 0) // 선행이 더 이상 없다는 것은 마지막 도착이라는것 
			{
				//len[son[cur][a].first] = len[cur] + son[cur][a].second;
				//len[son[cur][a].first] = sub;
				pq.push({ len[next_node], next_node});
			}
		}
	}

	bfs(end_node);




	cout << len[end_node] << '\n' << rs;

}
