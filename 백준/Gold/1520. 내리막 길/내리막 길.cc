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




int arr[501][501]{ 0 };
int dp[501][501]{ 0 };
bool visit[501][501];

int dx[4]{ -1,1,0,0 };
int dy[4]{ 0,0,1,-1 };
int row, col;


int DFS(int x, int y)
{
    

    visit[x][y] = 1;

    if (x == row && y == col)
        return 1;


    int nx, ny;

    for (int a = 0; a < 4; a++)
    {


        nx = x + dx[a];
        ny = y + dy[a];
        if (nx >= 1 && ny >= 1 && nx <= row && ny <= col && arr[x][y] > arr[nx][ny]) 
        {


            if (!visit[nx][ny]) // 아직 방문한 적이 없다면
            {
                
                if ( DFS(nx, ny) ) // 목표에 도달 가능하다면
                    dp[x][y]  +=  dp[nx][ny];

            }
            else // 이미 준비중이라면
                dp[x][y] += dp[nx][ny];
        }

    }

    return dp[x][y];


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    memset(visit, false, sizeof(visit));

    cin >> row >> col;

    

    for (int a = 1; a <= row; a++)
    {
        for (int b = 1; b <= col; b++)
        {
            int mem;
            cin >> mem;
            arr[a][b] = mem;

        }
    }


    dp[row][col] = 1;
    DFS(1, 1);

 

    /*for (int a = 1; a <= row; a++)
    {
        for (int b = 1; b <= col; b++)
        {
            cout << dp[a][b] << " ";

        }
    cout <<"\n";
    }*/

    cout << dp[1][1];

}