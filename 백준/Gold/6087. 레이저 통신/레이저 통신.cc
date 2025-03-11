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

int w, h;
pair<int, int> startP, endP;
bool getStartPoint;
char arr[101][101];
int ct[101][101][4];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
// 동 서 남 북



void fn() {
    queue<pair<pair<int, int>, pair<int, int>>> q; // (거울 수, 방향), (x, y)

    // 4방향에 대해서 시작점에서 출발, 초기화
    for (int a = 0; a < 4; a++) {
        q.push(make_pair(make_pair(0, a),make_pair(startP.first, startP.second)));
        ct[startP.first][startP.second][a]=0;
    }

    while (!q.empty()) {

        int mirrorCount = q.front().first.first;
        int curDir = q.front().first.second;
        int curX = q.front().second.first;
        int curY = q.front().second.second;
        
        q.pop();

        // 4방향에 대해서 탐색
        for (int a = 0; a < 4; a++) {
            int nextX = curX + dx[a];
            int nextY = curY + dy[a];
            int nextCount = mirrorCount;

            // 경계 조건 및 벽 확인
            if (nextX < 0 || nextX >= h || nextY < 0 || nextY >= w)
                continue;
            if (arr[nextX][nextY] == '*')
                continue;

            // 방향을 바꿀 때마다 거울 수가 증가
            if (a != curDir) {
                nextCount = mirrorCount + 1;
            }

            // 더 적은 거울 수로 방문하면 큐에 넣고 갱신
            if (ct[nextX][nextY][a] == -1 || ct[nextX][nextY][a] > nextCount) {
                q.push(make_pair(make_pair(nextCount, a),make_pair(nextX, nextY)));
                ct[nextX][nextY][a] = nextCount;
             
            }

        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> w >> h;

    for(int a = 0; a < h; a++)
        for(int b = 0; b < w; b++)
        {
            cin >> arr[a][b];
            if(arr[a][b] == 'C')
            {
                if(!getStartPoint)
                {
                    getStartPoint = true;
                    startP.first = a;
                    startP.second = b;
                }
                else
                {
                    endP.first = a;
                    endP.second = b;
                } 
            }
        }
    
    memset(ct, -1, sizeof(ct));
    fn();
    
 for (int a = 0; a < 4; a++)
     if(ct[endP.first][endP.second][a]==-1)
         ct[endP.first][endP.second][a]=MAXX;
   
   int rs = min({ct[endP.first][endP.second][0],ct[endP.first][endP.second][1],
   ct[endP.first][endP.second][2],ct[endP.first][endP.second][3]});
   cout << rs;
}