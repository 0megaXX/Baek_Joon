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

int row, col, K;
char arr[1000][1000];
int Fire[1000][1000];
int Move[1000][1000];

vector<pair<int, int>>Fire_pos;
pair<int, int>start_pos;

int dx[4]{ -1,1,0,0 };
int dy[4]{ 0,0,1,-1 };


void Fire_bfs()
{
	queue<pair<int, int>>q;

	for (int a = 0; a < Fire_pos.size(); a++)
		q.push({ Fire_pos[a].first,Fire_pos[a].second });

	while (!q.empty())
	{

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int nx, ny;
		int cur = Fire[x][y] + 1;
		for (int a = 0; a < 4; a++)
		{

			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && arr[nx][ny] != '#' &&Fire[nx][ny]==0)
			{
				Fire[nx][ny] = cur;
				q.push({ nx,ny });
			}

		}

	}

}

void Move_bfs()
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
			
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && arr[nx][ny] == '.' && Move[nx][ny] == 0)
			{
				if (Fire[nx][ny] == 0 || Fire[nx][ny] > cur)
				{
					Move[nx][ny] = cur;
					q.push({ nx,ny });
				}
			}
			else if(!(nx >= 0 && nx < row && ny >= 0 && ny < col))
			{
				cout << cur-1<<'\n';
				return;
			}
		}

	}

	cout << "IMPOSSIBLE\n";
	return ;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cass;
	cin >> cass;
	while (cass--)
	{


		memset(Fire, 0, sizeof(Fire));
		memset(Move, 0, sizeof(Move));
		memset(arr, 0, sizeof(arr));


		cin >> col >> row;
		for (int a = 0; a < row; a++)
			for (int b = 0; b < col; b++)
			{
				cin >> arr[a][b];
				if (arr[a][b] == '*')
				{
					Fire_pos.push_back({ a,b });
					Fire[a][b] = 1;
				}
				else if (arr[a][b] == '@')
				{
					start_pos = { a,b };
					Move[a][b] = 1;
				}

			}

		Fire_bfs();
		Move_bfs();


		/*cout << endl;
		for (int a = 0; a < row; a++)
		{
			for (int b = 0; b < col; b++)
			{
				cout << Fire[a][b]<<' ';
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

		Fire_pos.clear();
	}
}