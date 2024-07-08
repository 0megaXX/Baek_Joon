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
#define MAXX 987654321
using namespace std;

int row, col;
char MAP[20][20];
int ans = MAXX;
vector<pair<int, int>> coin;

int dx[4] { 0,0,1,-1 }; 
int dy[4] { 1,-1,0,0 };

bool escape(int x, int y) // 떨어졌는지 확인하는 펑션
{
    if (x >= row || y >= col || x < 0 || y < 0)
        return 1;
    else
        return 0;


}


void bfs(int x1, int y1, int x2, int y2, int click, int Where)
{
    if (ans < click) //최소 횟수보다 길면 의미없음
        return;

    if (click > 10)
    {
        ans = min(ans, click);
        return;
    }

    int nx1 = x1 + dx[Where];
    int ny1 = y1 + dy[Where];
    int nx2 = x2 + dx[Where];
    int ny2 = y2 + dy[Where];

    if (escape(nx1, ny1) && escape(nx2, ny2)) //둘다 떨어지면
        return;

    if (escape(nx1, ny1) && !escape(nx2, ny2)) //하나만 떨어지면
    {
        ans = min(ans, click);
        return;
    }

    if (!escape(nx1, ny1) && escape(nx2, ny2)) //하나만 떨어지면
    {
        ans = min(ans, click);
        return;
    }

    if (MAP[nx1][ny1] == '#') //벽이면 그대로
    {
        nx1 = x1;
        ny1 = y1;
    }
    if (MAP[nx2][ny2] == '#')//벽이면 그대로
    {
        nx2 = x2;
        ny2 = y2;
    }

    for (int a = 0; a < 4; a++) //4방으로 이동
        bfs(nx1, ny1, nx2, ny2, click + 1, a);

}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    cin >> row >> col;

    for (int a = 0; a < row; a++)
        for (int b = 0; b < col; b++)
        {
            cin >> MAP[a][b];
            if(MAP[a][b] == 'o')
                coin.push_back(make_pair(a,b));
       
        }


    for (int a = 0; a < 4; a++)
    {
        int x1 = coin[0].first;
        int y1 = coin[0].second;
        int x2 = coin[1].first;
        int y2 = coin[1].second;

        bfs(x1, y1, x2, y2, 1, a);
    }

    if (ans > 10)
        cout << -1;
    else
        cout << ans;
}