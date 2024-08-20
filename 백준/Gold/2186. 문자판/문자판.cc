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

char arr[100][100];
int dp[100][100][80]; // dp[x][y][len] => (x, y)에서 시작해서 len번째 문자까지 찾은 경우의 수
int row, col, max_len;
string word;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int dfs(int x, int y, int index) {
    if (index == word.size()) // 단어를 완성한 경우
        return 1;

    if (dp[x][y][index] != -1) // 이미 계산한 적이 있는 경우
        return dp[x][y][index];

    int count = 0;
    for (int a = 0; a < 4; a++) {
        for (int step = 1; step <= max_len; step++) 
        {
            int nx = x + dx[a] * step;
            int ny = y + dy[a] * step;

            if (nx >= 0 && ny >= 0 && nx < row && ny < col && arr[nx][ny] == word[index]) {
                count += dfs(nx, ny, index + 1);
            }
        }
    }

    return dp[x][y][index] = count; // 메모이제이션
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> col >> max_len;

    for (int a = 0; a < row; a++) {
        for (int b = 0; b < col; b++) {
            cin >> arr[a][b];
        }
    }

    cin >> word;

    memset(dp, -1, sizeof(dp)); // dp 배열 초기화

    int result = 0;
    for (int a = 0; a < row; a++) 
        for (int b = 0; b < col; b++) 
            if (arr[a][b] == word[0]) 
                result += dfs(a, b, 1);
            
        
    

    cout << result ;

    return 0;
}
