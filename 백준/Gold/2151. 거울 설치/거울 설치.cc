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

#define MAXX 1000000000
using namespace std;

int sizz;
char arr[50][50];
int visit[50][50][4]; // 각 방향에 대해 최소 거울 개수를 기록
int dx[4] = { 0, 0, 1, -1 }; // 동 서 남 북
int dy[4] = { 1, -1, 0, 0 };

struct State {
    int x, y, dir, mirrors;
}; // x, y, 방향, 거울 갯수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> sizz;
    pair<int, int> start, end;
    bool found_start = false;

    // 입력 처리 및 시작과 끝 위치 저장
    for (int a = 0; a < sizz; a++) {
        string s;
        cin >> s;
        for (int b = 0; b < sizz; b++) 
        {
            arr[a][b] = s[b];
            if (s[b] == '#' && !found_start) // 첫 위치는 시작
            {
                start = { a, b };
                found_start = true;
            }
            else if (s[b] == '#' && found_start) // 다음 위치는 끝
                end = { a, b };
            
        }
    }

    // 방문 배열 초기화
    memset(visit, -1, sizeof(visit));
    queue<State> q;

    // 시작점에서 4방향에 대해 BFS 초기화
    for (int a = 0; a < 4; a++) {
        int nx = start.first + dx[a];
        int ny = start.second + dy[a];
        if (nx >= 0 && nx < sizz && ny >= 0 && ny < sizz && arr[nx][ny] != '*') 
            // 시작위치에서 갈 수 있는 길 혹은 거울이라면 ( 벽 제외)
        {
            q.push({ nx, ny, a, 0 });
            visit[nx][ny][a] = 0;
        }
    }

    int rs = MAXX;
    // BFS 탐색
    while (!q.empty()) 
    {
        State cur = q.front();
        q.pop();

        // 도착점에 도달하면 종료
        if (cur.x == end.first && cur.y == end.second)
        {
           // cout << cur.mirrors ;
            rs = min(rs, cur.mirrors);
            continue;
        }

        // 현재 방향으로 직진
        int nx = cur.x + dx[cur.dir];
        int ny = cur.y + dy[cur.dir];

        if (nx >= 0 && nx < sizz && ny >= 0 && ny < sizz && arr[nx][ny] != '*')
        // 안벗어나고 길 혹은 거울이라면 ( 벽 제외)
        {
            if (visit[nx][ny][cur.dir] == -1 || visit[nx][ny][cur.dir] > cur.mirrors)
                // 방문한적이 없거나 최소거리(거울)갱신이라면
            {
                visit[nx][ny][cur.dir] = cur.mirrors;
                q.push({ nx, ny, cur.dir, cur.mirrors });
            }
        }

        // 거울을 놓아 방향 전환
        if (arr[cur.x][cur.y] == '!') {
            int new_dir1, new_dir2;

            // 동서남북에 대해 방향 전환 설정
            if (cur.dir == 0 || cur.dir == 1) { // 동 또는 서일 때, 남북으로 전환
                new_dir1 = 2;
                new_dir2 = 3;
            }
            else { // 남 또는 북일 때, 동서로 전환
                new_dir1 = 0;
                new_dir2 = 1;
            }

            // 새로운 방향으로 전환하여 큐에 추가
            for (int new_dir : {new_dir1, new_dir2}) 
            {
                nx = cur.x + dx[new_dir];
                ny = cur.y + dy[new_dir];

                if (nx >= 0 && nx < sizz && ny >= 0 && ny < sizz && arr[nx][ny] != '*')
                    // 안벗어나고 길 혹은 거울이라면 ( 벽 제외)
                    if (visit[nx][ny][new_dir] == -1 || visit[nx][ny][new_dir] > cur.mirrors + 1)
                        // 방문한적이 없거나 최소거리(거울)갱신이라면
                    {
                        visit[nx][ny][new_dir] = cur.mirrors + 1;
                        q.push({ nx, ny, new_dir, cur.mirrors + 1 });
                    }
                
            }
        }
    }

    cout << rs;
    return 0;
}