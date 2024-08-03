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
#include <unordered_set>
#define MAXX 987654321
using namespace std;

int row, col;
char arr[101][101];
bool visit[101][101];
int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };
map<char, int>m;

void bfs(char who,int x, int y) 
{
	int ct = 1;
	queue<pair<int, int>>q;
	q.push({ x,y });
	
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
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visit[nx][ny] && arr[nx][ny]==who)
			{
				visit[nx][ny] = 1;
				ct++;
				q.push({ nx,ny });
			}


		}

	}

	m[who] += pow(ct,2);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(visit, false, sizeof(visit));

	cin  >> col>> row;
	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
			cin >> arr[a][b];
	}
	
	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
		{
			if (!visit[a][b])
			{
				visit[a][b] = 1;
				bfs(arr[a][b],a,b);
			}
		}
	
	}
	cout << m['W'] << ' ' << m['B'] ;


}