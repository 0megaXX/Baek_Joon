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


using namespace std;

int cost[1001][1001];
int dp[1001][1001][4];

int row, col;

//pos는 방향 1이면 왼똑 대각선 2면 밑 3이면 오른쪽 대각선
int solve(int x, int y, int z)
{
    if (x == row + 1)
    {
        return 0;
    }

    if (dp[x][y][z] != 99999999)
    {
        return dp[x][y][z];
    }

    // 왼쪽
    if (z != 1 && y - 1 >= 1)
    {
        dp[x][y][z] = solve(x + 1, y - 1, 1) + cost[x][y];
    }

    // 중앙 
    if (z != 2)
    {
        dp[x][y][z] = min(dp[x][y][z], solve(x + 1, y, 2) + cost[x][y]);
    }

    // 오른쪽
    if (z != 3 && y + 1 <= col)
    {
        dp[x][y][z] = min(dp[x][y][z], solve(x + 1, y + 1, 3) + cost[x][y]);
    }

    return dp[x][y][z];
}
int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	cin >> row >> col;

	for (int a = 1; a <= row; a++)
        for (int b = 1; b <= col; b++)
        {
            cin >> cost[a][b];
            for (int c = 1; c <= 4; c++)
            {
                dp[a][b][c] = 99999999;
            }
        }
    int Min = 99999999;
    for (int i = 1; i <= col; i++)
    {

        Min = min(Min, solve(1, i, 4));
    }

    cout << Min;
}
