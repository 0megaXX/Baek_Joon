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

int sizz;
int arr[100][100];
bool visit[100][100];
int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };
vector<pair<int, int>>Land;

void LandArea(int a, int b, int num)
{
	arr[a][b] = num;
	visit[a][b] = 1;
	queue<pair<int, int>>q;
	q.push({ a,b });
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

			if (nx >= 0 && ny >= 0 && nx < sizz && ny < sizz && !visit[nx][ny] && arr[nx][ny] == 1)
			{
				visit[nx][ny] = 1;
				arr[nx][ny] = num;
				q.push({ nx,ny });
			}

		}
	}

}


int BFS(int land)
{

	int move = 0;
	queue<pair<int, int>>q;

	for (int a = 0; a < sizz; a++)
		for (int b = 0; b < sizz; b++)
			if (arr[a][b] == land) //현재 위치가 현재 내가 있는 섬에 속해있다면
			{
				visit[a][b] = 1;
				q.push({ a,b });
			}

	while (!q.empty())
	{
		int E = q.size(); // q는 동적으로 늘어가기 때문에 미리 현재 움직일 애들을 수를 저ㅜ장

		for (int b = 0; b < E; b++)
		{

			int x = q.front().first;
			int y = q.front().second;
			q.pop();


			int nx, ny;
			for (int a = 0; a < 4; a++)
			{
				nx = x + dx[a];
				ny = y + dy[a];

				if (nx >= 0 && ny >= 0 && nx < sizz && ny < sizz) //맵 벗어나지 않고
				{
					if (arr[nx][ny] == 0 && !visit[nx][ny]) // 이동할 곳이 강이며 간적이 없다면
					{
						visit[nx][ny] = 1;
						q.push({ nx,ny });
					}

					else if (arr[nx][ny] != land && arr[nx][ny] != 0) // 이동할곳이 강도 아니고 현재 내가있는 섬도 아니라면
						return move;
				}

			}

		}
		move++;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> sizz;

	memset(visit, false, sizeof(visit));

	for (int a = 0; a < sizz; a++)
		for (int b = 0; b < sizz; b++)
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
	

	int rs = MAXX;

	for (int a = 2; a < Area; a++)
	{
		memset(visit, false, sizeof(visit)); // 방문배열 다시 초기화
		rs=min(rs,BFS(a));
	}

	cout << rs;
	/*for (int a = 0; a < sizz; a++)
	{
		for (int b = 0; b < sizz; b++)
			cout << arr[a][b] << ' ';
		cout << endl;
	}*/
}