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




char arr[51][51];
bool visit[51][51];

int dx[4]{ -1,1,0,0 };
int dy[4]{ 0,0,1,-1 };
int row, col;


bool DFS(int x, int y, char c)
{


	pair<int, int>start = { x,y };

	stack<pair<int, pair<int, int>>>st;
	st.push({ 1, { x,y } });

	visit[x][y] = true;

	while (!st.empty())
	{

		int x = st.top().second.first;
		int y = st.top().second.second;
		int ct = st.top().first;
		visit[x][y] = true;
		st.pop();

		int nx, ny;
		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];
			if (nx == start.first && ny == start.second) // 다음 갈곳이 처음 위치라면 (사이클)
				if (ct >= 4) // 4개 이상이라면
					return true;


			if (nx >= 0 && ny >= 0 && nx < row && ny < col && arr[nx][ny] == c) // 이동 가능하고 같은 문자라면
				if (!visit[nx][ny]) // 간적이 없다면
					st.push({ ct + 1,{nx,ny} });

		}





	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);





	cin >> row >> col;



	for (int a = 0; a < row; a++)
	{
		string s;
		cin >> s;
		for (int b = 0; b < col; b++)
			arr[a][b] = s[b];
	}

	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
		{
			memset(visit, false, sizeof(visit));

			if (DFS(a, b, arr[a][b]))
			{
				cout << "Yes";
				return 0;
			}
			else
				arr[a][b] = '@';
		}

	}
	cout << "No";
}