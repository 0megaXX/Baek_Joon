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

const int MAX = 101;
int sizz;
int MAP[MAX][MAX];
bool visit[MAX][MAX];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void bfs(int x, int y, int h)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    visit[x][y] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int ny, nx;
        for (int a = 0; a < 4; a++) {
            nx = x + dx[a];
            ny = y + dy[a];
           

            if (nx < 0 || ny < 0 || nx >= sizz || ny >= sizz)  continue;
            if (visit[nx][ny]) continue;
            if (MAP[nx][ny] <= h) continue;

            visit[nx][ny] = true;
            q.push({nx , ny});
        }
    }
}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> sizz;
    for (int y = 0; y < sizz; y++)
        for (int x = 0; x < sizz; x++)
            cin >> MAP[y][x];

    int max_ct = 1;
    for (int height = 1; height <= 100; height++) 
    {
        int ct = 0;
        memset(visit, false, sizeof(visit)); //방문 초기화
        for (int x = 0; x < sizz; x++) 
            for (int y = 0; y < sizz; y++)  
                if (!visit[x][y] && MAP[x][y] > height) //안잠기고 방문을 안했다면
                {
                    bfs(x, y, height);
                    ct++;
                }
            
        

        if (ct == 0) //모두 잠겼다면 정지
            break;

        if (ct > max_ct)
            max_ct = ct;
    }

    cout << max_ct;


}