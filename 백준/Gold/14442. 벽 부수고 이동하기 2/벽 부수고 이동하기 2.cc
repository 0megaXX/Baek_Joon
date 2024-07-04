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

int MAP[1001][1001];
int len[11][1001][1001];
bool visit[11][1001][1001];
int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };

struct MyStruct
{
	int x, y, ct, floor;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(visit, false, sizeof(visit));
	memset(len, -1, sizeof(len));

	int row, col, max_break;

	cin >> row >> col >> max_break;

	for (int a = 0; a < row; a++)
	{
		string s;
		cin >> s;
		for (int b = 0; b < col; b++)
			MAP[a][b] = s[b] - '0';
	}



	queue<MyStruct>q;
	q.push({ 0,0,1,0 });
	len[0][0][0] = 1;
	visit[0][0][0] = true;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int ct = q.front().ct;
		int floor = q.front().floor;

		q.pop();
		int nx, ny;
		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];

			if (nx >= 0 && ny >= 0 && nx < row && ny < col) //맵을 벗어나지 않는다면
			{
				if (MAP[nx][ny] == 1) //벽일 경우
				{
					if (floor < max_break) // 벽을 더 뚫을 수 있다면
					{
						if (!visit[floor + 1][nx][ny])
						{
							visit[floor + 1][nx][ny] = true;
						//	visit[floor][nx][ny] = true;
							len[floor + 1][nx][ny] = ct + 1;
							q.push({ nx,ny,ct + 1,floor + 1 });
						}
					}
				}
				else if (!visit[floor][nx][ny] && MAP[nx][ny]==0) // 벽을 안뚫는 다면
				{
					visit[floor][nx][ny] = true;
					visit[floor+1][nx][ny] = true;
					len[floor][nx][ny] = ct + 1;
					q.push({ nx,ny,ct+1 ,floor });
				}


			}


		}


	}

	int minn = MAXX;
	for (int a = 0; a <= max_break; a++)
	{
		if (len[a][row - 1][col - 1] == -1)
			continue;
		minn=min(minn, len[a][row - 1][col - 1]);


	}
	if (minn == MAXX)
		cout << -1;
	else
		cout << minn;


}