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


struct MyStruct
{
	int row;
	int col;
	int count;
	int type;
};
int sizz, cass , later;
int target_x, target_y;
int arr[200][200];
int dx[4] = { -1, 1, 0,0 };
int dy[4] = {0,0, 1, -1 };

struct compare
{
	bool operator()(MyStruct a, MyStruct b)
	{
		if (a.count != b.count)
			return a.count > b.count;  // 더 작은 count가 먼저 오도록
		else if (a.type != b.type)
			return a.type > b.type;  // 더 작은 type가 먼저 오도록
		else if (a.row != b.row)
			return a.row > b.row;    // 오류 안나기 위함. 의미X
		else
			return a.col > b.col;    // 오류 안나기 위함. 의미X

	}
};

priority_queue<MyStruct,vector<MyStruct>,compare>pq;

void bfs()
{
	while (!pq.empty())
	{
		int x = pq.top().row;
		int y = pq.top().col;
		int type = pq.top().type;
		int cur_ct = pq.top().count;
		pq.pop();


		int nx, ny;

		for (int a = 0; a < 4; a++)
		{
			nx = x + dx[a];
			ny = y + dy[a];
			if (nx >= 0 && nx < sizz && ny >= 0 && ny < sizz && later>cur_ct)
				if (arr[nx][ny] == 0 )
				{
					arr[nx][ny] = type;
					pq.push({ nx,ny,cur_ct + 1,type });
				}

		}
	}
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	cin >> sizz>>cass;
	for (int a = 0; a < sizz; a++)
		for (int b = 0; b < sizz; b++)
		{
			cin >> arr[a][b];
			if (arr[a][b] != 0)
				pq.push({ a,b,0,arr[a][b] });
		}

	
	cin >> later >> target_x >> target_y;
	target_x -= 1;
	target_y -= 1;
	bfs();

	/*for (int a = 0; a < sizz; a++)
	{
		for (int b = 0; b < sizz; b++)
		{
			cout << arr[a][b] << ' ';
		}
		cout << endl;
	}*/
	cout << arr[target_x][target_y];
}