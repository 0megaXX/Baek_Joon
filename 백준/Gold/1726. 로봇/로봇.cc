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
#define MAXX 987654321
using namespace std;

int row, col;
int arr[101][101];
int dist[101][101][5];
int turn[3] = { 1, -1, 0 };  // 오른쪽 회전, 왼쪽 회전, 그대로

pair<int, int> start_pos;
pair<int, int> end_pos;
int start_front, end_front;

int ans = MAXX;
void bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({ {0, start_front}, start_pos });
    dist[start_pos.first][start_pos.second][start_front] = MAXX;

    while (!q.empty())
    {
        int commands = q.front().first.first;
        int way = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;

        q.pop();

        if (x == end_pos.first && y == end_pos.second) {
           
           
            int rotations = abs(way - end_front);
            if (rotations == 3)
                rotations = 1;  // 3칸 차이 나는 경우 1번 회전

             ans=min( commands + rotations,ans);
       
        }

        for (int a = 0; a < 3; a++)
        {
            int next_cmd = commands + 1;
            int way_sub = (way + turn[a]) % 4;
            if (way_sub == 0)
                way_sub = 4;

            if (way_sub == way)
                next_cmd--;

            for (int b = 1; b <= 3; b++) {
                int nx = x, ny = y;
                switch (way_sub) {
                case 1: // 동쪽
                    ny += b;
                    break;
                case 2: // 남쪽
                    nx += b;
                    break;
                case 3: // 서쪽
                    ny -= b;
                    break;
                case 4: // 북쪽
                    nx -= b;
                    break;
                }

                // if (arr[nx][ny] == 1)
                  //   goto ex;

                if (nx <= 0 || ny <= 0 || nx > row || ny > col || arr[nx][ny] == 1)
                    break;

                if (dist[nx][ny][way_sub] == -1 || dist[nx][ny][way_sub] > next_cmd + 1)
                {
                    dist[nx][ny][way_sub] = next_cmd + 1;
                    q.push({ {next_cmd + 1, way_sub}, {nx, ny} });
                }

                //ex:;

            }

        }

        // 180도 회전 처리
            int next_cmd = commands + 3;
            int way_sub = (way + 2) % 4;
            if (way_sub == 0)
                way_sub = 4;


            for (int b = 1; b <= 3; b++)
            {
                int nx = x, ny = y;
                switch (way_sub) {
                case 1: // 동쪽
                    ny += b;
                    break;
                case 2: // 남쪽
                    nx += b;
                    break;
                case 3: // 서쪽
                    ny -= b;
                    break;
                case 4: // 북쪽
                    nx -= b;
                    break;
                }

                // if (arr[nx][ny] == 1)
                  //   goto ex;

                if (nx <= 0 || ny <= 0 || nx > row || ny > col || arr[nx][ny] == 1)
                    break;

                if (dist[nx][ny][way_sub] == -1 || dist[nx][ny][way_sub] > next_cmd)
                {
                    dist[nx][ny][way_sub] = next_cmd;
                    q.push({ {next_cmd, way_sub}, {nx, ny} });
                }
            }






        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dist, -1, sizeof(dist));

    cin >> row >> col;
    for (int a = 1; a <= row; a++)
        for (int b = 1; b <= col; b++)
            cin >> arr[a][b];

    int startX, startY, endX, endY;
    cin >> startX >> startY >> start_front;

    start_pos = { startX, startY };
    int temp = start_front;
    switch (temp)
    {
    case 1:
        start_front = 1;
        break;
    case 2:
        start_front = 3;
        break;
    case 3:
        start_front = 2;
        break;
    case 4:
        start_front = 4;
        break;

    }
    cin >> endX >> endY >> end_front;
    end_pos = { endX, endY };

    temp = end_front;
    switch (temp)
    {
    case 1:
        end_front = 1;
        break;
    case 2:
        end_front = 3;
        break;
    case 3:
        end_front = 2;
        break;
    case 4:
        end_front = 4;
        break;

    }

    if (startX == endX && startY == endY)
    {
        int rotations = abs(start_front - end_front);
        if (rotations == 3)
            rotations = 1;  // 3칸 차이 나는 경우 1번 회전
        cout << rotations;
        return 0;
    }

    bfs();
    cout << ans << endl;;
 
  /* cout << endl;
    for (int a = 1; a <= row; a++)
    {
        for (int b = 1; b <= col; b++)
        {
            if (a == start_pos.first && b == start_pos.second)
                cout << "# ";
            else
            cout << dist[a][b] << ' ';
        }cout << endl;
    }*/
    return 0;
}