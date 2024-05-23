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

int row, col, answer;
char arr[10000][500];
bool visit[10000][500];
int dx[4] = { -1, 0, 1 };
int dy[4] = { 1, 1, 1 };
bool ans;

void dfs(int x, int y)
{
	visit[x][y] = true;
	if (y == col - 1)
	{
		ans = true;
		answer++;
		return;
	}

	int nx, ny;
		
	for (int a = 0; a < 3; a++)
	{
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col)
			if (arr[nx][ny] == '.' && !visit[nx][ny])
			{
				dfs(nx, ny);
				if (ans)
					return;
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
			cin>>arr[a][b];
	

	for (int a = 0; a < row; a++)
	{
		ans = false;
		dfs(a, 0);
	}
	cout << answer;
}