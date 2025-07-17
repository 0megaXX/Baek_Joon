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
#include <regex>

using namespace std;
#define MAXX 2147483647

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

vector<pair<int, int>> arr[101][101];
bool light[101][101];// 불 켜진 방
bool visit[101][101];// 실제 방문 (불 켜짐) 
bool arrive[101][101];// 이론상 도착 가능한 방(불이 꺼져 못들어간)

queue<pair<int, int>> q;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,M;
	cin >> N >> M;
    
	int x, y, a, b;
	int ans = 0;
    
	for (int i = 0; i < M; i++) 
    {
		cin >> x >> y >> a >> b;
		arr[y][x].push_back({ b,a });
	}

	q.push({ 1,1 }); // 1,1 에서 시작
    // 1,1은 전부 처리
	visit[1][1] = 1;
	light[1][1] = 1;
	arrive[1][1] = 1;
	ans++; // 켜진 불의 수
	
	while (!q.empty()) 
    {
		int y = q.front().first;
        int x = q.front().second;
		q.pop();
		pair<int, int> next_room;
 
		// 불이 꺼져있다면 키고, 이미 이전에 방문 가능했지만, 불이 꺼져 도달 못했던 방을 추가
		for (int i = 0; i < arr[y][x].size(); i++)
        {
			next_room = arr[y][x][i]; // y,x 에서 갈 수 있는 다음 방
            
			// 이미 불이켜져있다면 continue
			if (light[next_room.first][next_room.second] == 1)
                continue;
            
			light[next_room.first][next_room.second] = 1;
			ans++;

			// 이미 이전에 방문 가능하지만, 불이 꺼져 도달 못했던 방이라면 추가
			if (arrive[next_room.first][next_room.second]  &&
				!visit[next_room.first][next_room.second] )
				q.push({ next_room.first ,next_room.second });
		}

		for (int i = 0; i < 4; i++) 
        {
			int ny = y + dy[i];
            int nx = x + dx[i];
			if (ny>=1 && nx>=1 && ny<=N && nx<= N && !visit[ny][nx]) // 범위안에 있고 방문처리가 아직이라면 
            {       
    			arrive[ny][nx] = 1; // 방문은 이론상 가능하다
    			if (light[ny][nx] != 1) // 하지만 불이 안켜져있다면 들어가지는 못함
                    continue;
                
    			visit[ny][nx] = 1; // 방문처리
    			q.push({ ny,nx });
            }
		}
        
	}
	cout << ans;

    return 0;
}

