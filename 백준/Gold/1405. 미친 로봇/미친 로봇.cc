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

#define MAXX 987654321
using namespace std;

double EWSN[4];
bool visit[31][31];
int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };
int deep;
double rs = 0;
void fn(int cur_deep, int x, int y, double val)
{

    if (cur_deep == deep) // 횟수를 만족할경우
    {
            rs += val;
            return; 
    }

    int nx, ny;
    for (int a = 0; a < 4; a++) // 이동방향은 동서남북
    {
        nx = x + dx[a];
        ny = y + dy[a];

        if (nx >= 0 && ny >= 0 && nx <= 29 && ny <= 29 && !visit[nx][ny]) // a를 방문하지 않았다면 방문처리
        {
            visit[nx][ny] = true;
            fn(cur_deep + 1, nx, ny,val*EWSN[a]);
            visit[nx][ny] = false;
        }

    }

}





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> deep;

    for (int a = 0; a < 4; a++)
    {

        cin >> EWSN[a];
        EWSN[a] /= 100;
    }

    visit[15][15] = 1; // 시작위치 방문처리

    fn(0, 15, 15, 1);
    cout.precision(10);
    cout << fixed << rs;

    return 0;
}