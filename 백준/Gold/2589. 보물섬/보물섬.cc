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
char arr[50][50];
//int sub[100][100];
int dx[4]{ 0,0,-1,1 };
int dy[4]{ -1,1,0,0 };
int visit[50][50];


int bfs(int xx,int yy)
{
	queue<pair<int, int>>q;
	visit[xx][yy] = 1;
	q.push({ xx,yy });
	memset(visit, false, sizeof(visit));
	int maxx = 0;
	while (!q.empty())
	{
		
		int x = q.front().first;
		int y = q.front().second;
		if (xx == x && yy == y)
			visit[x][y] = 0;
		maxx = max(maxx, visit[x][y]);
		q.pop();
		int nx, ny;
		int cur = visit[x][y]+1;
		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && visit[nx][ny]==0 &&arr[nx][ny]=='L')
			{
				visit[nx][ny] = cur;
				q.push({ nx,ny });
				
			}
		}

	}

	return maxx;
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

	int rs = 0;
	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
			if (arr[a][b] == 'L')
			{
				memset(visit, 0, sizeof(visit));
				rs = max(rs, bfs(a,b));
			}

	cout << rs;
}