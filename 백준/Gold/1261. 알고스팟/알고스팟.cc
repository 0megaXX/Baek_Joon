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

int row, col;
int arr[100][100];
int visit[100][100];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs()
{
	queue<pair<int, int>> q;
	q.push({0,0});
	visit[0][0] = 0;

	while (!q.empty())
	{
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
		int next = visit[x][y] + 1;
		int nx, ny;
		for (int a = 0; a < 4; ++a)
		{
			nx = x + dx[a];
		    ny = y + dy[a];
			if (nx >= 0 && nx < col && ny >= 0 && ny < row ) 
			{
				if (arr[nx][ny] == 0 && visit[nx][ny] > visit[x][y])
				{
					visit[nx][ny] = visit[x][y];
					q.push({ nx,ny });
				}
				else if (arr[nx][ny] == 1 &&  visit[nx][ny] > next)
				{
					visit[nx][ny] = next;
					q.push({ nx,ny });
				}
			}
		}
	}
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



    cin >> row >> col;
    for (int a = 0; a < col; ++a)
    {
        string s;
        cin >> s;
		for (int b = 0; b < row; b++)
		{
			arr[a][b] = s[b] - '0';
			visit[a][b]= 987654321;
		}
    }
	bfs();

	/*for (int a = 0; a < col; a++)
	{
		for (int b = 0; b < row; b++)
			cout << visit[a][b]<<' ';
		cout << endl;
	}*/
	cout << visit[col - 1][row - 1];
}