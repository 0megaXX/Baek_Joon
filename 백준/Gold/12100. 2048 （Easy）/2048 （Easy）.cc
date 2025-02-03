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
#include <tuple>

using namespace std;
#define MAXX 99999999

int sizz,mxN;
int arr[20][20];

void shift(int num) {
    queue<int> q;
    switch (num) {
        case 0: // 왼쪽으로 미는 경우
            for (int a = 0; a < sizz; a++) {
                for (int b = 0; b < sizz; b++) {
                    if (arr[a][b] != 0) q.push(arr[a][b]);
                    arr[a][b] = 0;
                }
                int idx = 0;
                while (!q.empty()) {
                    int data = q.front(); q.pop();
                    if (arr[a][idx] == 0) 
                        arr[a][idx] = data;
                    else if (arr[a][idx] == data) {
                        arr[a][idx] *= 2;
                        idx++;
                    } else {
                        idx++;
                        arr[a][idx] = data;
                    }
                }
            }
            break;

        case 1: // 오른쪽으로 미는 경우
            for (int a = 0; a < sizz; a++) {
                for (int b = sizz - 1; b >= 0; b--) {
                    if (arr[a][b] != 0) q.push(arr[a][b]);
                    arr[a][b] = 0;
                }
                int idx = sizz - 1;
                while (!q.empty()) {
                    int data = q.front(); q.pop();
                    if (arr[a][idx] == 0)
                        arr[a][idx] = data;
                    else if (arr[a][idx] == data) {
                        arr[a][idx] *= 2;
                        idx--;
                    } else {
                        idx--;
                        arr[a][idx] = data;
                    }
                }
            }
            break;

        case 2: // 위로 미는 경우
            for (int b = 0; b < sizz; b++) {
                for (int a = 0; a < sizz; a++) {
                    if (arr[a][b] != 0) q.push(arr[a][b]);
                    arr[a][b] = 0;
                }
                int idx = 0;
                while (!q.empty()) {
                    int data = q.front(); q.pop();
                    if (arr[idx][b] == 0)
                        arr[idx][b] = data;
                    else if (arr[idx][b] == data) {
                        arr[idx][b] *= 2;
                        idx++;
                    } else {
                        idx++;
                        arr[idx][b] = data;
                    }
                }
            }
            break;

        case 3: // 밑으로 미는 경우
            for (int b = 0; b < sizz; b++) {
                for (int a = sizz - 1; a >= 0; a--) {
                    if (arr[a][b] != 0) q.push(arr[a][b]);
                    arr[a][b] = 0;
                }
                int idx = sizz - 1;
                while (!q.empty()) {
                    int data = q.front(); q.pop();
                    if (arr[idx][b] == 0)
                        arr[idx][b] = data;
                    else if (arr[idx][b] == data) {
                        arr[idx][b] *= 2;
                        idx--;
                    } else {
                        idx--;
                        arr[idx][b] = data;
                    }
                }
            }
            break;
    }
}

void dfs(int depth) {
    if (depth == 5) 
        return;
    
    int tmp_board[20][20];
    for (int a = 0; a < sizz; a++) 
        for (int b = 0; b < sizz; b++) 
            tmp_board[a][b] = arr[a][b];

    for (int a = 0; a < 4; a++) {
        shift(a);
        for (int a = 0; a < sizz; a++) 
            for (int b = 0; b < sizz; b++) 
                mxN = max(mxN, arr[a][b]);
        dfs(depth + 1);

        for (int a = 0; a < sizz; a++) 
            for (int b = 0; b < sizz; b++) 
                arr[a][b] = tmp_board[a][b];
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> sizz;

    for (int a = 0; a < sizz; a++)
        for (int b = 0; b < sizz; b++)
            cin >> arr[a][b];
           
     mxN = 0;
     dfs(0);

	cout << mxN ;
    return 0;
}
