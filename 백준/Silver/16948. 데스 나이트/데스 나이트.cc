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



pair<int, int>start;
pair<int, int>eend;
int dx[6]{ -2,-2,0,0,2,2 };
int dy[6]{ -1,1,-2,2,-1,1 };
bool visit[201][201];
int sizz;

void bfs()
{

    queue<pair<int, int>>q;
    q.push(start);
    int ct = 0;
    
    while (!q.empty())
    {

        int sizzz = q.size();
        for (int a = 0; a < sizzz; a++)
        {
            int x = q.front().first;
            int y = q.front().second;
         

            q.pop();


            if (x == eend.first && y == eend.second)
            {
                cout << ct;
                return;
            }

            int nx, ny;
            for (int b = 0; b < 6; b++)
            {
                nx = x + dx[b];
                ny = y + dy[b];
               
                if (nx >= 0 && nx < sizz && ny >= 0 && ny < sizz && !visit[nx][ny])
                {
                   
                    visit[nx][ny] = 1;
                    q.push({ nx,ny });
                }
            }


        }
        ct++;
    }
    cout << -1;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    memset(visit, false, sizeof(visit));
    cin >> sizz;



    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    start = { sx,sy };
    eend = { ex,ey };

    bfs();
}