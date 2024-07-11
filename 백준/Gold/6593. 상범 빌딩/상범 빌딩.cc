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





int L, R, C;
char building[31][31][31];
bool visit[31][31][31];
int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };
pair<int, pair<int, int>>Start;




int BFS()
{

    queue<pair<pair<int, int>, pair<int, int>>>q;
    q.push({ { 0,Start.first },{Start.second.first,Start.second.second} });
    while (!q.empty())
    {
        int ct= q.front().first.first;
        int floor = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
       // cout << "현재 위치 " << floor << ' ' << x << ' ' << ' ' << y << ' ' << building[floor][x][y]
         // <<' '<<ct<< endl;
        q.pop();
        if (building[floor][x][y] == 'E')
            return ct;
        int nx, ny;
        for (int a = 0; a < 4; a++)
        {
            nx = x + dx[a];
            ny = y + dy[a];

            if (nx >= 0 && ny >= 0 && nx < R && ny < C && !visit[floor][nx][ny]
                && building[floor][nx][ny] != '#')
            {
                visit[floor][nx][ny] = true;
                q.push({ {ct+1,floor},{nx,ny} });
            }

            if(floor+1<L && !visit[floor+1][x][y] && building[floor+1][x][y] != '#')
            {
                visit[floor+1][x][y] = true;
                q.push({ {ct + 1,floor + 1},{x,y} });
            }

            if (floor - 1>=0&& !visit[floor -1][x][y] && building[floor-1][x][y] != '#')
            {
                visit[floor - 1][x][y] = true;
                q.push({ {ct + 1,floor - 1},{x,y} });
            }
        }

        
    }

    return 0;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true)
    {


        memset(visit, false, sizeof(visit));

        cin >> L >> R >> C;

        if (!(L || R || C))
            return 0;
        for (int a = 0; a < L; a++)
            for (int b = 0; b < R; b++)
            {
                for (int c = 0; c < C; c++)
                {
                    cin >> building[a][b][c];
                    if (building[a][b][c] == 'S')
                        Start = { a,{b,c} };
                }
            }


        int rs = BFS();
        if (rs != 0)
            cout << "Escaped in " << rs << " minute(s).\n";
        else
            cout << "Trapped!\n";
    }
}