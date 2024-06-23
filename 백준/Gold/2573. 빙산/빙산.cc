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

using namespace std;

int row, col;
int arr[300][300];;
int arr_b[300][300];
bool visit[300][300];
int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };
int rs = 0;

bool check_arr()
{
	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
			if (arr[a][b] > 0)
				return 0;

	return 1;
}


int bfs()
{
	int ct = 0;
	queue<pair<int, int>>q;
	memset(visit, false, sizeof(visit));


	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
		{
			if (visit[a][b] == false && arr[a][b] >0)
			{
				ct++;
				q.push({ a,b });
				visit[a][b] = true;
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					int nx, ny;
					for (int c = 0; c < 4; c++)
					{
						nx = x + dx[c];
						ny = y + dy[c];

						if (nx >= 0 && ny >= 0 && x < row && y < col && !visit[nx][ny])
						{
							if (arr[nx][ny] <= 0)
								arr_b[x][y]--;
							else
							{
								visit[nx][ny] = true;
								q.push({ nx,ny });
							}
						}
					}
				}
			}
		}

	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
			arr[a][b] = arr_b[a][b];


	return ct;
}



void dikstra()
{




}



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> row >> col;
	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
		{
			cin >> arr[a][b];
			arr_b[a][b] = arr[a][b];
		}


	while (!check_arr())
	{
		
		int cur = bfs();
		//cout << cur << endl;
		if (cur >= 2)
			goto ex;
		rs++;
	}

		cout << 0;
		return 0;
	ex:;
		cout << rs;

}
