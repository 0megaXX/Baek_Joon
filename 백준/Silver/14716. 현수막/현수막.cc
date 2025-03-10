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
int arr[250][250];
//int sub[100][100];
int dx[8]{ 0,0,-1,1,-1,-1,1,1 };
int dy[8]{ -1,1,0,0,-1,1,-1,1 };

void bfs(int sx,int sy)
{
    
	queue<pair<int, int>>q;
	q.push({ sx,sy });
    
	while (!q.empty())
	{
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int nx, ny;
		for (int a = 0; a < 8; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && arr[nx][ny]==1)
			{
				arr[nx][ny]=0;
				q.push({ nx,ny });
				
			}
		}

	}

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
			if (arr[a][b] == 1)
			{
                arr[a][b]=0;
                bfs(a,b);
    			rs++;
			}

	cout << rs;
}