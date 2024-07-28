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

int row, col;
int arr[1001][1001];
int len[2][1001][1001];
pair<int, int>start;
pair<int, int>endd;
int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> row >> col;
	
	int sx, sy;
	cin >> sx>> sy;
	start = { sx,sy };
	int ex,ey;
	cin >> ex >> ey;
	endd = { ex,ey };


	for (int a = 1; a <= row; a++)
		for (int b = 1; b <= col; b++)
		{
			cin >> arr[a][b];
			len[0][a][b] = MAXX;
			len[1][a][b] = MAXX;
		}
	len[0][sx][sy] = 1;
	len[1][sx][sy] = 1;
	queue<pair<int, pair<int, int>>>q;
	q.push({ 0,start });
	while (!q.empty())
	{
		int x = q.front().second.first;
		int y = q.front().second.second;
		int broken = q.front().first;
		int next = len[broken][x][y]+1;
		q.pop();
		int nx, ny;
		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];

			if (nx >= 1 && ny >= 1 && nx <= row && ny <= col)
			{
				if (arr[nx][ny] == 0) //움직일 곳이 길이라면
				{
					if (len[broken][nx][ny] > next) // 현재위치에서 움직이는게 더 짧다면
					{
						len[broken][nx][ny] = next;
						q.push({ broken,{nx,ny} });

					}
				}
				else // 움직일 곳이 벽이라면
				{
					if (broken == 0 && len[broken + 1][nx][ny]>next)
					{
						len[broken+1][nx][ny] = next;
						q.push({ broken+1,{nx,ny} });
					}
				}

			}

		}
	}

	/*cout << "========================================\n";
	for (int a = 1; a <= row; a++)
	{
		for (int b = 1; b <= col; b++)
		{
			cout << len[0][a][b]<<' ';
		}
		cout << endl;
	}
	cout << "========================================\n";
	for (int a = 1; a <= row; a++)
	{
		for (int b = 1; b <= col; b++)
		{
			cout << len[1][a][b] << ' ';
		}
		cout << endl;
	}*/

	int rs = min(len[0][endd.first][endd.second], len[1][endd.first][endd.second]);
	if (rs == MAXX)
		cout << -1;
	else
		cout << rs-1;

}