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
#define MAXX 99999999

int row, col;
char arr[10][10];

// 빨간 구슬(R)과 파란 구슬(B)의 위치
pair<int, int> red_pos, blue_pos;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1}; // 남 북 동 서

bool visited[10][10][10][10];  // visited[rx][ry][bx][by] (빨간 구슬 위치, 파란 구슬 위치)

int bfs() {
    queue<tuple<int, int, int, int, int>> q;  // (빨간 구슬 x, 빨간 구슬 y, 파란 구슬 x, 파란 구슬 y, 이동 횟수)
    q.push({red_pos.first, red_pos.second, blue_pos.first, blue_pos.second, 0});
    visited[red_pos.first][red_pos.second][blue_pos.first][blue_pos.second] = true;

    while (!q.empty()) {
        auto [rx, ry, bx, by, moves] = q.front();
        q.pop();

        // 10번 이상 움직였으면 종료 (최대 10번)
        if (moves >= 10)
            continue;
 
        for (int dir = 0; dir < 4; dir++)
        {
            int nrx = rx, nry = ry, nbx = bx, nby = by;

            // 빨간 구슬 이동
            while (arr[nrx + dx[dir]][nry + dy[dir]] != '#' && arr[nrx][nry] != 'O')
            {
                nrx += dx[dir];
                nry += dy[dir];
            }

            // 파란 구슬 이동
            while (arr[nbx + dx[dir]][nby + dy[dir]] != '#' && arr[nbx][nby] != 'O')
            {
                nbx += dx[dir];
                nby += dy[dir];
            }

            // 파란 구슬이 탈출구에 도달하면 실패
            if (arr[nbx][nby] == 'O')
                continue;

            // 빨간 구슬이 탈출구에 도달했으면 게임 종료
            if (arr[nrx][nry] == 'O')
                return 1; // 탈출 가능하면 1
           
            // 구슬이 같은 위치에 있으면 한 구슬을 한 칸 뒤로 이동
            if (nrx == nbx && nry == nby)
            {
                if (dir == 0) // 남
                {
                    if(rx<bx)
                        nrx--;
                    else
                        nbx--;
                }
                else if (dir == 1) // 북
                {
                    if(rx>bx)
                        nrx++;
                    else
                        nbx++;
                }
                else if (dir == 2) // 동
                {
                    if(ry<by)
                        nry--;
                    else
                        nby--;
                }
                else if (dir == 3) // 서
                { 
                    if(ry>by)
                        nry++;
                    else
                        nby++;
                }
            }

            // 방문하지 않은 상태에서 새로운 위치로 큐에 삽입
            if (!visited[nrx][nry][nbx][nby])
            {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, moves + 1});
            }
        }
    }

    return 0;  // 탈출 불가능 하면 0
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> row >> col;

    for (int a = 0; a < row; a++) {
        for (int b = 0; b < col; b++)
        {
            cin >> arr[a][b];
            if (arr[a][b] == 'R')
                 red_pos = {a, b};
                 
            else if (arr[a][b] == 'B')
                 blue_pos = {a, b};
        }
    }

    int result = bfs();
    cout << result;

    return 0;
}