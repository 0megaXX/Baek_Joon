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
int arr[101][71];
bool visit[101][71];



int dx[8]{ 0,0,-1,1,-1,1,-1,1 };
int dy[8]{ 1,-1,0,0,-1,1,1,-1 };


bool bfs(int sx, int sy)
{
	queue<pair<int, int>>q;
	q.push({ sx,sy });
	int height = arr[sx][sy];
	bool rs = true;
	while (!q.empty())
	{

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		int nx, ny;
		for (int a = 0; a < 8; a++)
		{

			nx = x + dx[a];
			ny = y + dy[a];

			if (nx >= 0 && ny >= 0 && nx < row && ny < col && arr[nx][ny]) // 인접한지 확인
			{

				if (arr[nx][ny] > height) // 크면 봉우리 못됨
					rs = false;

				else if (arr[nx][ny] == height && !visit[nx][ny]) 
					// 높이가 같고 방문한적없는 산이면 산봉우리에 포함
				{
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}


			}

		}

	}

	return rs;


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> row >> col;

	for(int a=0;a<row;a++)
		for (int b = 0; b < col; b++)
			cin >> arr[a][b];
		


	int rs=0;
	memset(visit, false, sizeof(visit)); // 초기화
	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
		{
			if(!visit[a][b]) // 방문하지 않은 산이면
				if (bfs(a, b)) // 그 산이 봉우리를 만들수 있다면
				{
					//cout << a << ' ' << b << endl;
					rs++;
				}
		}

	cout << rs;
	return 0;
}