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


int dx[8]{ 0,0,1,-1,-1,-1,1,1 };
int dy[8]{ 1,-1,0,0,-1,1,-1,1 };
int row, col,ct=0;
int MAP[50][50];
vector<pair<int, int>>shark;

void bfs()
{
    queue<pair<int, int>>q;
    for (auto i : shark)
        q.push(i);

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int cur = MAP[x][y];
        ct = max(ct, cur);
        q.pop();
        int nx, ny;
        for (int a = 0; a < 8; a++)
        {
            nx = x + dx[a];
            ny = y + dy[a];
            if (nx >= 0 && ny >= 0 && nx < row && ny < col)
            {
                if (MAP[nx][ny] == 0)
                {
                    MAP[nx][ny] = cur + 1;
                    q.push({ nx,ny });


                }


            }

        }

    }




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
            if (MAP[a][b] == 1)
                shark.push_back({ a,b });
        }

    bfs();

    cout << ct - 1;
    
}