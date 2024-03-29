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

char arr[1001][1001];
int arr2[1001][1001];
bool visit[1001][1001];
int row, col;
int ct = 0;
int ar_ct = 1;


void bfs(int x, int y, int arr_ct)
{

	arr2[x][y] = arr_ct;
	switch (arr[x][y])
	{
	case 'U': if (x - 1 >= 0 && !visit[x - 1][y])
	{
		visit[x - 1][y] = true;
		bfs(x - 1, y, arr_ct);

	}
			else if (x - 1 >= 0 && arr2[x - 1][y] != arr_ct)
		ct--;

		break;
	case 'D': if (x + 1 < row && !visit[x + 1][y])
	{
		visit[x + 1][y] = true;
		bfs(x + 1, y, arr_ct);

	}
			else if (x + 1 < row && arr2[x + 1][y] != arr_ct)

		ct--;

		break;
	case 'L': if (y - 1 >= 0 && !visit[x][y - 1])
	{
		visit[x][y - 1] = true;
		bfs(x, y - 1, arr_ct);

	}
			else if (y - 1 >= 0 && arr2[x][y - 1] != arr_ct)

		ct--;

		break;
	case 'R': if (y + 1 < col && !visit[x][y + 1])
	{
		visit[x][y + 1] = true;
		bfs(x, y + 1, arr_ct);

	}
			else if (y + 1 < col && arr2[x][y + 1] != arr_ct)

		ct--;

		break;


	default:
		break;
	}




}



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visit, false, sizeof(visit));
	memset(arr2, 0, sizeof(arr2));
	cin >> row >> col;
	cin.ignore();

	for (int a = 0; a < row; a++)
	{
		string s;
		cin >> s;
		for (int b = 0; b < col; b++)
			arr[a][b] = s[b];
	}

	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
		{
			if (!visit[a][b])
			{
				//cout << a << ' ' << b << endl;
				visit[a][b] = true;

				bfs(a, b, ar_ct);
				ct++;
				ar_ct++;
			}

		}

	cout << ct;


}
