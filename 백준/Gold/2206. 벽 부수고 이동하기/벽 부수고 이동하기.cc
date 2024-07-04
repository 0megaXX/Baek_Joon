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
using namespace std;

int arr[1000][1000];
int len [2][1000][1000];
bool visit[2][1000][1000];
int row, col;
int dx[4]{ 0,0,1,-1 };
int dy[4]{ -1,1,0,0 };

struct MyStruct
{
	int row, col, ct,len;
};

int main(void)
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(visit, false, sizeof(visit));
	memset(len, -1, sizeof(len));
	cin >> row >> col;
	string s;
	for (int a = 0; a < row; a++)
	{
		cin >> s;
		for (int b = 0; b < col; b++)
			arr[a][b] = s[b] - '0';
	}


	queue<MyStruct>q;
	q.push({ 0,0,0,1 });
	len[0][0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().row;
		int y = q.front().col;
		int ct = q.front().ct;
		int lenn = q.front().len;
		q.pop();
		int nx, ny;
		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];

			if (nx >= 0 && nx < row && ny >= 0 && ny < col &&ct==0&& !visit[0][nx][ny]) // 벽을 안뚫었을때
			{

				if (arr[nx][ny] == 0)
				{
					visit[0][nx][ny] = true;
					len[0][nx][ny] = lenn + 1;
					q.push({ nx,ny,0,lenn+1 });
				}
				else
				{
					visit[1][nx][ny] = true;
					len[1][nx][ny] = lenn + 1;
					q.push({ nx,ny,1,lenn + 1 });
				}
			}
			else if (nx >= 0 && nx < row && ny >= 0 && ny < col&&arr[nx][ny]==0 &&ct==1&& !visit[1][nx][ny]) // 벽을 뚫었을때
			{
				visit[1][nx][ny] = true;
				len[1][nx][ny] = lenn + 1;
				q.push({ nx,ny,1,lenn + 1 });
			}

		}
	}
	
	if (len[0][row - 1][col - 1] != -1 && len[1][row - 1][col - 1] != -1)
	{
		int minn = min(len[1][row - 1][col - 1], len[0][row - 1][col - 1]);
		cout << minn;
	}
	else if (len[0][row - 1][col - 1] != -1)
	{
		cout << len[0][row - 1][col - 1];
	}
	else if (len[1][row - 1][col - 1] != -1)
	{
		cout << len[1][row - 1][col - 1];
	}
	else
		cout << -1;


	/*for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
			cout << len[0][a][b] << " ";
		cout << endl;
	}
	cout << endl << endl;
	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
			cout << len[1][a][b] << " ";
		cout << endl;
	}*/


	//cout << len[0][row - 1][col - 1]<<"    " << len[1][row - 1][col - 1];

}
