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
#define MAXX 987654321
using namespace std;

int sizz;
int T=0, S=0;
char arr[7][7];
bool visit[7][7];
vector<pair<int, int>>teacher;

int dx[4]{ 0,0,1, - 1 };
int dy[4]{ 1,-1,0,0 };
bool ask = false;

bool Search()
{

	queue<pair<int, int>>q;
	for (int a = 0; a < teacher.size(); a++)
		q.push(teacher[a]);

	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int a = 0; a < 4; a++)
		{
			int nx = cur_x + dx[a];
			int ny = cur_y + dy[a];

			while (nx >= 0 && ny >= 0 && nx < sizz && ny < sizz && arr[nx][ny] != 'O')
			{
				if (arr[nx][ny] == 'S')
					return false;
				nx += dx[a];
				ny += dy[a];
			}


		}
	}

	return true;

}


void back(int start,int block)
{
	
	if(block == 3)
	{
		/*for (int a = 0; a < sizz; a++)
		{
			for (int b = 0; b < sizz; b++)
			{
				cout << arr[a][b] << ' ';
			}
			cout << endl;
		}
		cout << endl;*/

		if (Search())
		{
			cout << "YES";
			exit(0);
		}
		return;
	}

	for (int a = start; a < (sizz*sizz); a++)
	{
		int r = a / sizz;
		int c = a % sizz;
		
		if (!visit[r][c] && arr[r][c]=='X')
		{
			visit[r][c] = true;
			arr[r][c] = 'O';
			back(start + 1, block + 1);
			visit[r][c] = false;
			arr[r][c] = 'X';
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visit, false, sizeof(visit));
	
	cin >> sizz;
	for(int a=0;a<sizz;a++)
		for (int b = 0; b < sizz; b++)
		{
			cin >> arr[a][b];
			if (arr[a][b] == 'S')
				S++;
			else if (arr[a][b] == 'T')
			{
				T++;
				teacher.push_back({ a,b });
			}
		}


	back(0,0);

	cout << "NO";

}
