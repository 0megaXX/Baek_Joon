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
using namespace std;

int arr[1001][1001]; 
int arr2[1001][1001];
int Answer[1001][1001];
bool visit[1001][1001];
int row, col;
int ct = 1;
int dx[4]{ 0,0,-1,1 };
int dy[4]{ -1,1,0,0 };
map<int, int>m;

void bfs(int x, int y,int ct)
{
	arr2[x][y] = ct;
	m[ct]++;
	int nx, ny;
	for (int a = 0; a < 4; a++)
	{
		nx = x + dx[a];
		ny = y + dy[a];
		if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visit[nx][ny] && arr[nx][ny] == 0)
		{
			visit[nx][ny] = true;
			bfs(nx, ny,ct);
		}
	}
	



}



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visit, false, sizeof(visit));
	memset(arr2, 0, sizeof(arr2));
	memset(Answer, 0, sizeof(Answer));
	cin >> row >> col;
	m[0] = 0;
	cin.ignore();

	for (int a = 0; a < row; a++)
	{
		string s;
		cin >> s;
		for (int b = 0; b < col; b++)
			arr[a][b] = s[b] - '0';
	}

	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
		{
			if (!visit[a][b] && arr[a][b] == 0)
			{
				visit[a][b] = true;
				bfs(a, b,ct);
				ct++;
			}

		}


	//cout << endl;
	//for (int a = 1; a <= ct; a++)
	//{
	//	cout << m[a] << " ";
	//}
	//cout << endl;

	//cout << endl;
	//for (int a = 0; a < row; a++)
	//{
	//	for (int b = 0; b < col; b++)
	//	{
	//		cout << arr2[a][b] << ' ';
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	for (int a = 0; a < row; a++)
	{
		for (int b = 0; b < col; b++)
		{
			int summ = 0;
			if (arr[a][b] == 1)
			{
				set<int> Search;
				
				for (int c = 0; c < 4; c++)
				{
					int nx = a + dx[c];
					int ny = b + dy[c];
					if (nx >= 0 && nx < row && ny >= 0 && ny < col && arr2[nx][ny]!=0)
					{
						if (arr[nx][ny] == 0)
						{
							if (Search.find(arr2[nx][ny]) == Search.end())
							{
								Search.insert(arr2[nx][ny]);
								summ += m[arr2[nx][ny]];
							}
						}
					}
				}
				//Answer[a][b] = summ;
				summ++;
			}
			cout << summ%10;
		}
		cout << endl;
	}

	

}
