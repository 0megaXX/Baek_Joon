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

int N, M, ans=987654321;
int Map[50][50];
bool visit[50][50];
bool choose[10];
int dx[4]{ 0,0,1,-1 };
int dy[4]{ -1,1,0,0 };
vector<pair<int,int>>v;
vector<pair<int, int>>choose_v;


bool check_map()
{
	for (int a = 0; a < N; a++)
	{
		for (int b = 0; b < N; b++)
		{
			if (Map[a][b] == 1) // 벽이면 통과
				continue;
			if (!visit[a][b])//벽이 아닌데 바이러스가 간적이 없다면
				return 0;
		}
	}
	return 1;


}


void bfs()
{
	queue<pair<int, int>>q;
	for (int a = 0; a < choose_v.size(); a++)
	{
		int x = choose_v[a].first;
		int y = choose_v[a].second;
		q.push({ x,y });
		visit[x][y] = true;
	}

	int ct = 0;
	while (!q.empty())
	{

		int sub = q.size();
		for (int i = 0; i < sub; i++)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			int nx, ny;
			for (int a = 0; a < 4; a++)
			{
				nx = x + dx[a];
				ny = y + dy[a];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N)
				{
					if (!visit[nx][ny] && Map[nx][ny] != 1)
					{
						visit[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
		if (q.size() != 0) // 퍼져나갈수 있다면
			ct++;

	}
	if (check_map())
		ans = min(ans, ct);
	

}

void choose_virus(int idx, int cnt) // 브루드
{

	if (cnt == M)
	{
		memset(visit, false, sizeof(visit));
		bfs();
		return;
	}

	for (int a = idx; a < v.size(); a++)
	{
		if (choose[a]) //이미 조합에 포함됐다면 넘김
			continue;
		choose[a] = 1;
		choose_v.push_back(v[a]);
		choose_virus(a, cnt + 1);
		choose_v.pop_back();
		choose[a] = 0;

	}

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	memset(choose, false, sizeof(choose));

	cin >> N >> M;
	for (int a = 0; a < N; a++)
	{
		for (int b = 0; b < N; b++)
		{
			cin >> Map[a][b];
			if (Map[a][b] == 2)
				v.push_back({ a,b });
		}
	}
	choose_virus(0, 0);


	if (ans == 987654321)
		ans = -1;
	cout << ans;
}