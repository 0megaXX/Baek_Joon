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

int row, col;
int arr[101][101];
bool visit[101][101];
int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };
vector<pair<int, int>>Land;

int Land_rel[8][8];

int parent[8]; // 크루스칼에 사용할 부모정보


int find_parent(int x)// Find 함수: 특정 노드의 루트를 찾음
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find_parent(parent[x]); // 경로 압축
}

// Union 함수: 두 섬을 연결 (합침)
void union_parent(int x, int y) 
{
	x = find_parent(x);
	y = find_parent(y);
	if (x != y)
		parent[y] = x; // 루트가 다르면 합침
}

bool isConnected(int x, int y) 
{
	return 
		find_parent(x) == find_parent(y);
}

// 간선 정보 (거리, 섬1, 섬2)
vector<pair<int, pair<int, int>>> edges;

void goto_front(int x, int y, int front, int start)
{
	int len = 0;
	


	while (x >= 0 && y >= 0 && x < row && y < col &&
		arr[x][y] == 0) // 안벗어나고 바다라면
	{
		x += dx[front];
		y += dy[front];
		len++;

		if (len!=1 && arr[x][y] != 0 && arr[x][y] != start) // 직진으로 도착한 섬이 다른 섬이라면
		{

			Land_rel[start][arr[x][y]] = min(Land_rel[start][arr[x][y]], len); // 갱신
			Land_rel[arr[x][y]][start] = min(Land_rel[arr[x][y]][start], len); // 갱신
			return; 
		}

	}



}

void makeLoad(int start_land)
{
	int move = 0;
	queue<pair<int, int>>q;

	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
			if (arr[a][b] == start_land) //현재 위치가 현재 내가 있는 섬에 속해있다면
			{
				visit[a][b] = 1;
				q.push({ a,b });
			}

	while (!q.empty())
	{


		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int nx, ny;
		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];

			if (nx >= 0 && ny >= 0 && nx < row && ny < col
				&& arr[nx][ny]==0 ) // 갈 곳이 바다라면
				goto_front(nx, ny, a, start_land); // 그 방향으로 직진


		}

		move++;
	}



}



void LandArea(int x, int y, int Area)
{
	queue<pair<int, int>>q;
	q.push({ x, y });

	visit[x][y] = true;
	arr[x][y] = Area;

	while (!q.empty())
	{

		int x = q.front().first;
		int y = q.front().second;

		q.pop();


		int nx, ny;
		for (int a = 0; a < 4; a++)
		{

			nx = x + dx[a];
			ny = y + dy[a];

			if (nx >= 0 && ny >= 0 && nx < row && ny < col && !visit[nx][ny] && arr[nx][ny] == 1)
			{
				visit[nx][ny] = 1;
				q.push({ nx,ny });
				arr[nx][ny] = Area;
			}



		}

	}


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> row >> col;

	memset(visit, false, sizeof(visit));

	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
		{
			cin >> arr[a][b];
			if (arr[a][b] == 1) // 땅이면
				Land.push_back({ a,b });
		}



	int Area = 2;

	for (int a = 0; a < Land.size(); a++)
	{
		int x = Land[a].first;
		int y = Land[a].second;

		if (!visit[x][y])
		{
			LandArea(x, y, Area);
			Area++;
		}
	}



	//거리 초기화
	for (int a = 0; a < 8; a++)
		for (int b = 0; b < 8; b++)
			Land_rel[a][b]=MAXX ;


	memset(visit, false, sizeof(visit)); // 방문배열 초기화

	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
		{
			if (!visit[a][b] && arr[a][b] != 0) // 간적없는 섬이라면
			{			
				visit[a][b] = true;
				makeLoad(arr[a][b]); 
			}
		}
	}


	
	for (int a = 2; a < Area; a++) 
		for (int b = a + 1; b < Area; b++)
			if (Land_rel[a][b] < MAXX)  // 간선 리스트 생성
				edges.push_back({ Land_rel[a][b], {a, b} });
			

	
	sort(edges.begin(), edges.end()); // 간선 정렬

	// Union-Find 초기화
	for (int a = 2; a < Area; a++) 
		parent[a] = a;

	int totalCost = 0; // 최소 스패닝트리의 거리
	int edgeCount = 0; // 간선갯수

	// 크루스칼 알고리즘 적용
	for (auto edge : edges) 
	{
		int cost = edge.first;
		int start = edge.second.first;
		int eend = edge.second.second;
		if (!isConnected(start, eend)) // 연결확인
		{
			union_parent(start, eend); // 연결
			totalCost += cost; // 거리연결
			edgeCount++;			//cout << "간선 연결: 섬 " << start << " - 섬 " << eend << ", 거리: " << cost << "\n";
		
		}
	}

	
	//cout << "최소 스패닝 트리의 총 비용: " << totalCost << "\n";

	if (edgeCount!=(Area-3) || totalCost == 0) // 스패닝트리는 n-1개의 간선이 있어야함. 섬은 1부터 시작하니 Area-3;
		cout << -1;
	else
		cout << totalCost;


}