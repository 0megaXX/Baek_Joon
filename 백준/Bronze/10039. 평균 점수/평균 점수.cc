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

    int summ = 0;
    int ct = 5;
    while (ct--)
    {
        int a;
        cin >> a;
        if (a < 40)
            a = 40;
        summ += a;
    }
    cout << summ / 5;
}