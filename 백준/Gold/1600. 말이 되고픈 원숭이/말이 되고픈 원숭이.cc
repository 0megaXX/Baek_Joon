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
int arr[200][200];
int visit[32][200][200];

//int sub[100][100];
int dx[8]{ -2,-1 ,1, 2,-2,-1,1,2};
int dy[8]{ -1,-2,-2,-1, 1,2,2,1};
int ddx[4]{ -1,1,0,0 };
int ddy[4]{ 0,0,1,-1 };

struct MyStruct
{
	int ct, x, y;
};

void bfs()
{
	queue<MyStruct>q;

	q.push({ 0,0,0 });

	
	
	int maxx = 0;
	while (!q.empty())
	{
		
		int x = q.front().x;
		int y = q.front().y;
		int cur = q.front().ct;
		int cct = visit[cur][x][y]+1;
	
		q.pop();
		int nx, ny,nnx,nny;

		for (int a = 0; a < 4; a++)
		{

			nnx = x + ddx[a];
			nny = y + ddy[a];
			if (nnx >= 0 && nnx < row && nny >= 0 && nny < col && (arr[nnx][nny] != 1) && !(nnx==0 &&nny==0))
			{

				if(visit[cur][nnx][nny]==0 || visit[cur][nnx][nny] > cct)
				{
					visit[cur][nnx][nny] = cct;
					q.push({ cur,nnx,nny });
				}
			}

		}

		for (int a = 0; a < 8; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];

			
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && (arr[nx][ny]!=1)&& !(nx == 0 && ny == 0))
			{
				if (cur < K)
				{

					if (visit[cur + 1][nx][ny] == 0 || visit[cur + 1][nx][ny] > cct)
					{
						visit[cur + 1][nx][ny] = cct;
						q.push({ cur + 1,nx,ny });
					}
				}
			}
		}

		

	}


}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	memset(visit, 0, sizeof(visit));

	cin >>K>> col>> row;
	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
			cin >> arr[a][b];

	if (row == 1 && col == 1 && arr[0][0] == 0)
	{
		cout << 0;
		return 0;
	}


	bfs();

	int minn = 99999999;
	for (int a = 0; a <= K; a++)
	{
		
		if (visit[a][row - 1][col - 1] == 0)
			continue;
		else
			minn = min(minn, visit[a][row - 1][col - 1]);
	}

	
	/*for (int a = 0; a <= K; a++)
	{
		for (int b = 0; b < row; b++)
		{
			for (int c = 0; c < col; c++)
			{
				cout << visit[a][b][c] << ' ';
			}
			cout << endl;
		}
		cout << endl << endl;
	}*/


	if (minn == 99999999)
		cout << -1;
	else
		cout << minn;
	
}