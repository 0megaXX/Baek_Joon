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
#include <chrono>
#include <tuple>

using namespace std;
#define MAXX 2147483647

int x_1, y_1, x_2, y_2, y, x, ny, nx;
int N, M;
bool found = false;
char graph[304][304];
bool visited[304][304];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int sy, int sx)
{

	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	visited[sy][sx] = 1;

	while (!q.empty())
    {
		y = q.front().first; x = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
        {
			ny = y + dy[d];
			nx = x + dx[d];
			if (graph[ny][nx] == '#') // 찾았다면
            {
				found = true;
				return;
			}
			if (ny >= 1 && ny <= N && nx >= 1 && nx <= M && !visited[ny][nx]) // 안갔다면
            {
				visited[ny][nx] = true;
               
				if (graph[ny][nx] == '1') // 있다면 넘어뜨리기
                    graph[ny][nx] = '0';
                   
				else if (graph[ny][nx] == '0') // 아무것도 없다면 파동이 전파
                    q.push({ ny,nx });
			}
		}
	}
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M;
	cin >> x_1 >> y_1 >> x_2 >> y_2;

	for (int a = 1; a <= N; a++)
		for (int b = 1; b <= M; b++)
            cin >> graph[a][b];

    int rs = 0;
	while (1)
    {
		rs++;
		bfs(x_1, y_1);
       
		if (found) // 찾았다면 탈출
            break;
	}
	cout << rs;
}
