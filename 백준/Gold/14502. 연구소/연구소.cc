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

int arr[10][10];
int arr2[10][10];
int row, col;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
vector<pair<int, int>>virus;



void dfs(int x, int y)
{
	int X, Y;
	for (int i = 0; i < 4; i++)
	{
		X = x + dx[i];
		Y = y + dy[i];

		if (X >= 0 && X < row && Y >= 0 && Y < col && !arr2[X][Y]) {
			arr2[X][Y] = 2;
			dfs(X, Y);
		}
	}
}




int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x1, x2, x3, y1, y2, y3;
	int ans = 0;
	
	cin >> row >> col;
	int MAX = row * col;

	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
		{
			cin >> arr[a][b];
			arr2[a][b] = arr[a][b];
			if (arr[a][b] == 2)
				virus.push_back({ a,b });
		}

	for (int one = 0; one < MAX; one++)
	{
		x1 = one / col;
		y1 = one % col;
		if (!arr2[x1][y1])
		for (int two = one + 1; two < MAX; two++)
		{
			x2 = two / col;
			y2 = two % col ;
			if(!arr2[x2][y2])
			for (int three = two + 1; three < MAX; three++)
			{
				x3 = three / col ;
				y3 = three % col ;
				if (!arr2[x3][y3])
				{
					arr2[x1][y1] = 1;
					arr2[x2][y2] = 1;
					arr2[x3][y3] = 1;

					for (int a = 0; a < virus.size(); a++)
						dfs(virus[a].first, virus[a].second);

					int cnt = 0;

					for (int a = 0; a<row; a++)
						for (int b = 0; b <col; b++)
							if (0==arr2[a][b])
								cnt++;

					if (ans < cnt)
					{
					//	cout <<cnt<<": " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
						ans = cnt;
					}
					for (int a = 0; a < row; a++)
						for (int b = 0; b < col; b++)
							arr2[a][b] = arr[a][b];

				}
			}
		}
	}
	cout << ans;

}
