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
#include <chrono>

#define MAXX 1000000005
using namespace std;

int N, M, K;

// 상하좌우
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int arr[101][101];
bool visit[101][101];

int Dfs(int x, int y)
{
	int cnt = 1;
	stack<pair<int, int>> s;
	s.push({ x , y });
	visit[x][y] = 1;
	while (!s.empty())
	{
		int x = s.top().first;
		int y = s.top().second;
	
		s.pop();
		if (visit[x][y] == 0)
			cnt++;
		visit[x][y] = 1;

		int nx, ny;
		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) // 범위 벗어나면 
				continue;

			if (arr[nx][ny] == 1 || visit[nx][ny] == 1) // 방문처리 
				continue;

			s.push({ nx, ny });
		}
	}
	return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	vector<int> v;

	// M 세로 N 가로 K갯수
	cin >> M >> N >> K;

	for (int a = 0; a < K; a++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int y = y1; y < y2; y++)
			for (int x = x1; x < x2; x++)
				arr[x][y] = 1; // 영역처리
	
	}

	for (int y = M - 1; y >= 0; y--)
		for (int x = 0; x < N; x++)
			if (arr[x][y] == 0 && visit[x][y] == 0) // 방문처리 안된 빈영역이면
				v.push_back(Dfs(x, y));

	sort(v.begin(), v.end()); // 오른차순을 위한 정렬

	cout << v.size() << '\n';
	for (int a = 0; a < v.size(); a++)
		cout << v[a] <<' ';
	

    return 0;

}