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
#include <unordered_map>

using namespace std;

int row, col,K;
char arr[50][50];
int water[50][50];
int Move[50][50];

vector<pair<int, int>>water_pos;
pair<int, int>start_pos,end_pos;

int dx[4]{ -1,1,0,0 };
int dy[4]{ 0,0,1,-1 };


void water_bfs()
{
	queue<pair<int, int>>q;

	for(int a=0;a<water_pos.size();a++)
		q.push({ water_pos[a].first,water_pos [a].second});

	while (!q.empty())
	{
		
		int x = q.front().first;
		int y = q.front().second;	
		q.pop();
		int nx, ny;
		int cur = water[x][y] + 1;
		for (int a = 0; a < 4; a++)
		{

			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && arr[nx][ny]!='X'&&water[nx][ny]==0 && arr[nx][ny] != 'D')
			{
				water[nx][ny] = cur;
				q.push({ nx,ny });	
			}

		}

	}

}

bool Move_bfs()
{
	queue<pair<int, int>>q;

	q.push(start_pos);
	while (!q.empty())
	{

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int nx, ny;
		int cur = Move[x][y] + 1;
		for (int a = 0; a < 4; a++)
		{

			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && arr[nx][ny] != 'X' && Move[nx][ny] == 0 )
			{
				if (water[nx][ny] ==0|| water[nx][ny] > cur)
				{
					if (arr[nx][ny] == 'D')
					{
						Move[nx][ny] = cur;
						return 1;
					}

					Move[nx][ny] = cur;
					q.push({ nx,ny });
				}
			}

		}

	}


	return 0;
}






int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(water, 0, sizeof(water));
	memset(Move, 0, sizeof(Move));

	cin >> row >> col;
	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
		{
			cin >> arr[a][b];
			if (arr[a][b] == '*')
			{
				water_pos.push_back({ a,b });
				water[a][b] = 1;
			}
			else if (arr[a][b] == 'S')
			{
				start_pos = { a,b };
				Move[a][b] = 1;
			}
			else if (arr[a][b] == 'D')
				end_pos = { a,b };
		}

	water_bfs();
	if (Move_bfs())
	{
		cout << Move[end_pos.first][end_pos.second] - 1;
	}
	else
		cout << "KAKTUS";

	/*cout << endl;
	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
		{
			cout << water[a][b]<<' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
		{
			cout << Move[a][b] << ' ';
		}
		cout << endl;
	}*/
}