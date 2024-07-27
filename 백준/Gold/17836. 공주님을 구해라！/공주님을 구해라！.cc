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

int row, col,limit;
int arr[100][100];
int arr_2[100][100];
int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };
pair<int, int>Gram;
bool visit[100][100];

bool check()
{
	if (arr_2[row - 1][col - 1]!=MAXX)
		return true;
	else
		return false;
}

int no_break_bfs()
{

	queue<pair<int, int>>q;
	q.push({ 0,0 });
	visit[0][0] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int nex = arr_2[x][y] + 1;
		q.pop();
			
		int nx, ny;
		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && ny >= 0 && nx < row && ny < col && !visit[nx][ny] && (arr[nx][ny]==0 || arr[nx][ny]==2))
			{
				visit[nx][ny] = true;
				arr_2[nx][ny] = nex;
				q.push({ nx,ny });

			}
		}
	}

	return arr_2[row - 1][col - 1];
}


int Gram_bfs()
{

	queue<pair<int, int>>q;
	q.push({ 0,0 });
	visit[0][0] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		int nex = arr_2[x][y] + 1;
		q.pop();

		int nx, ny;
		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && ny >= 0 && nx < row && ny < col && !visit[nx][ny])
			{
				if (arr[nx][ny] == 0)
				{
					visit[nx][ny] = true;
					arr_2[nx][ny] = nex;
					q.push({ nx,ny });
				}
				else if (arr[nx][ny] == 2)
				{
					return nex + (((row - 1) - nx) + (col - 1) - ny);
				}
			}
		}
	}

	return MAXX;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(arr_2, 0, sizeof(arr_2));
	memset(visit, false, sizeof(visit));

	cin >> row >> col >> limit;
	arr_2[row - 1][col - 1] = MAXX;
	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
		{
			cin >> arr[a][b];
			if (arr[a][b] == 2)
				Gram = { a,b };
		}

	int rs = MAXX;
	int no_break = no_break_bfs();
	rs = min(no_break, rs);

	memset(arr_2, 0, sizeof(arr_2));
	memset(visit, false, sizeof(visit));
	arr_2[row - 1][col - 1] = MAXX;


	rs = min(rs, Gram_bfs());

	if (rs == MAXX || rs>limit)
		cout << "Fail";
	else
		cout << rs;



}