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
#include <numeric>

using namespace std;



int row, col, height;
int Time = 0;
int target_x, target_y;
int arr[100][100][100];
int dx[4] = { -1, 1, 0,0 };
int dy[4] = { 0,0, 1, -1 };
int dz[3] = { -1,0,1 };

struct three_int
{
	int x, y, z;
};

queue<three_int>q;

void bfs()
{
	queue<three_int>sub_q;

	while (!q.empty())
	{

		sub_q = q;
		while (!q.empty())
			q.pop();

		while (!sub_q.empty())
		{
			int x = sub_q.front().x;
			int y = sub_q.front().y;
			int z = sub_q.front().z;
			sub_q.pop();


			int nx, ny, nz;

			for (int a = 0; a < 4; a++)
			{

				nx = x + dx[a];
				ny = y + dy[a];
				if (nx >= 0 && nx < row && ny >= 0 && ny < col)
					if (arr[z][nx][ny] == 0)
					{

						arr[z][nx][ny] = 1;
						q.push({ nx,ny,z });
					}

			}

			for (int zz = 0; zz < 3; zz++)
			{	
				nz = z + dz[zz];
				if (nz >= 0 && nz < height)
				{
					if (arr[nz][x][y] == 0)
					{
						arr[nz][x][y] = 1;
						q.push({ x,y,nz });
					}
				}
			}
		}

		if (q.empty())
		{
			return;
		}
		Time++;
		

		/*cout << Time << "차 일 때 \n\n-------------\n";
		for (int a = 0; a < height; a++)
		{
			for (int b = 0; b < row; b++)
			{
				for (int c = 0; c < col; c++)
				{
					cout << arr[a][b][c] << ' ';
				}cout << endl;
			}
		}*/


	}





	
}


bool Search()
{
	for (int a = 0; a < height; a++)
		for (int b = 0; b < row; b++)
			for (int c = 0; c < col; c++)
				if (arr[a][b][c] == 0)
					return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	cin >> col >> row >> height;
	for (int a = 0; a < height; a++)
		for (int b = 0; b < row; b++)
			for (int c = 0; c < col; c++)
			{
				cin >> arr[a][b][c];
				if (arr[a][b][c] == 1)
					q.push({ b,c,a });
			}


	if (Search())
	{
		cout << Time;
		return 0;
	}
	bfs();

	/*for (int a = 0; a < height; a++)
	{
		for (int b = 0; b < row; b++)
		{
			for (int c = 0; c < col; c++)
			{
				cout << arr[a][b][c] << ' ';
			}cout << endl;
		}

	}*/

	if (Search())
		cout << Time;
	else
		cout << -1;
}