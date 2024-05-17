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

int row, col;
int ct = 0;
int arr[100][100];
//int sub[100][100];
int dx[4]{ 0,0,-1,1 };
int dy[4]{ -1,1,0,0 };
bool visit[100][100];
int last_ct;


void bfs()
{
	queue<pair<int, int>>q;
	visit[0][0] = true;
	q.push({ 0,0 });
	memset(visit, false, sizeof(visit));
	ct++;
	last_ct = 0;
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
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visit[nx][ny] )
			{

				if (arr[nx][ny] == 1)
				{
					arr[nx][ny] = 0;
					last_ct++;
					visit[nx][ny] = true;
				}
				else
				{
					visit[nx][ny] = true;
					q.push({ nx,ny });
				}
			}
		}

	}

}

bool scan()
{
	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
			if (arr[a][b] == 1)
				return 0;
		
	return 1;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> row >> col;
	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
			cin >> arr[a][b];

	while (!scan())
	{
		bfs();
	}
	cout << ct << '\n' << last_ct;
}