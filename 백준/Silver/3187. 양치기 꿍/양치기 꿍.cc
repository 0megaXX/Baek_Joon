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
char arr[251][251];
bool visit[251][251];
int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };
int total_v = 0;
int total_k = 0;


void bfs(int x, int y) 
{
	int v_ct = 0;
	int k_ct = 0;
	queue<pair<int, int>>q;
	q.push({ x,y });
	

	if (arr[x][y] == 'k')
		k_ct++;
	else if (arr[x][y] == 'v')
		v_ct++;
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
			if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visit[nx][ny] && arr[nx][ny]!='#')
			{
			
				visit[nx][ny] = 1;

				if (arr[nx][ny] == 'k')
					k_ct++;
				else if (arr[nx][ny] == 'v')
					v_ct++;

				q.push({ nx,ny });
			}


		}

	}

	if (k_ct > v_ct)
		total_k += k_ct;
	else
		total_v += v_ct;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(visit, false, sizeof(visit));

	cin  >> row>> col;
	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
			cin >> arr[a][b];
	}
	
	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
		{
			if (!visit[a][b] && arr[a][b]!='#')
			{
				visit[a][b] = 1;
				bfs(a,b);
			}
		}
	
	}
	cout << total_k << ' ' << total_v ;


}