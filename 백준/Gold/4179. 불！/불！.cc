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

char arr[1001][1001];

int visit_human[1001][1001];
int visit_fire[1001][1001];

int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };
int row, col;

void bfs_fire()
{

	queue<pair<int, int>>q;

	for(int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
			if (arr[a][b] == 'F')
			{
				q.push({ a,b });
				visit_fire[a][b] = 1;
			}
		
	while (!q.empty())
	{

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int nx, ny;
		int ct = visit_fire[x][y]+1;
		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];

			if (nx < 0 || nx >= row || ny < 0 || ny >= col)//탈출했다면 
				continue;
			if (arr[nx][ny] == '#' || visit_fire[nx][ny])//벽이거나 이미 불붙었다면
				continue;
			q.push({ nx,ny });
			visit_fire[nx][ny] = ct;
		}

	}

}
int bfs_human()
{

	queue<pair<int, int>>q;

	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
			if (arr[a][b] == 'J')
			{
				q.push({ a,b });
				visit_human[a][b] = 1;
			}


	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int nx, ny;
		int ct = visit_human[x][y] + 1;
		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];

			if (nx < 0 || nx >= row || ny < 0 || ny >= col)//탈출했다면 
				return visit_human[x][y];
			if (arr[nx][ny] == '#' || visit_human[nx][ny])
				continue;
			if (ct >= visit_fire[nx][ny] && visit_fire[nx][ny]) // 불이 더 빨리 도착했다면
				continue;
			q.push({ nx,ny });
			visit_human[nx][ny] = ct;
		}

	}
			return- 1;
}






int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	cin >> row >> col;

	for (int a = 0; a < row; a++)
	{
		string s;
		cin >> s;
		for (int b = 0; b < col; b++)	
			arr[a][b] = s[b];

		
	}
	bfs_fire();
	int rs=bfs_human();
	
	/*for (int a = 0; a < row; a++)
	{
		
		for (int b = 0; b < col; b++)
		{
			cout << visit_fire[a][b] << ' ';
		}
		cout << endl;


	}
	cout << endl;
	for (int a = 0; a < row; a++)
	{

		for (int b = 0; b < col; b++)
		{
			cout << visit_human[a][b] << ' ';
		}
		cout << endl;


	}*/

	if (rs == -1)
		cout << "IMPOSSIBLE";
	else
		cout << rs;


}