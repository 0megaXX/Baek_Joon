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

using namespace std;

char arr[12][6];
bool visit[12][6];
int row=12, col=6;
int combo = 0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
 


void Drop() {
    for (int c = 0; c < col; c++) 
    { // 각 열에 대해
        int empty_row = row - 1; // 아래에서부터 탐색

        for (int r = row - 1; r >= 0; r--) { // 아래에서부터 탐색
            if (arr[r][c] != '.') { // 블록이 있는 경우
                if (r != empty_row) { // 빈 공간이 아닌 곳에 블록이 있으면 아래로 내림
                    arr[empty_row][c] = arr[r][c];
                    arr[r][c] = '.';
                }
                empty_row--; // 아래에 블록이 채워졌으므로 한 칸 위로 이동
            }
        }
    }
}

void visit_clear()
{

    memset(visit, false, sizeof(visit));

}

bool boom(int x, int y) {
    bool is_boom = false;
    queue<pair<int, int>> q;
    queue<pair<int, int>> tmp_q;
    q.push({ x, y });
    tmp_q.push({ x, y });
    visit[x][y] = true;
    char color = arr[x][y];
    int ct = 1;

    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int a = 0; a < 4; a++) {
            int nx = cur_x + dx[a];
            int ny = cur_y + dy[a];

            if (nx >= 0 && ny >= 0 && nx < row && ny < col && arr[nx][ny] == color && !visit[nx][ny]) {
                visit[nx][ny] = true;
                q.push({ nx, ny });
                tmp_q.push({ nx, ny });
                ct++;
            }
        }
    }

    if (ct >= 4) { // 4개 이상 연쇄라면
        is_boom = true;
        while (!tmp_q.empty()) {
            int x = tmp_q.front().first;
            int y = tmp_q.front().second;
            tmp_q.pop();
            arr[x][y] = '.';
        }
    }

    return is_boom;
}



void Simul()
{
    while (true)
    {

    /*    for (int a = 0; a < row; a++)
        {
            for (int b = 0; b < col; b++)
                cout << arr[a][b] << ' ';
            cout << endl;
        }
        cout << endl << "-----------------------\n\n\n";
        */
        
        visit_clear();
        bool is_crash = false;
        for (int a = 0; a < row; a++)
            for (int b = 0; b < col; b++)
                if (arr[a][b] != '.' && !visit[a][b]) // 빈칸이 아니고 블록이라면
                    is_crash |= boom(a, b); // 한번이라도 연쇄가 일어나면 true

      
            if (!is_crash)
            { // 더 이상 연쇄가 일어나지 않으면 종료
                break;
            }
            else
                combo++;
        Drop(); // 연쇄가 일어난 후 블록을 아래로 내림
    }
    



}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   

    for (int a = 0; a < row; a++) 
        for (int b = 0; b < col; b++) 
            cin >> arr[a][b];
        
    
    Simul();
    cout << combo;

    return 0;
}
