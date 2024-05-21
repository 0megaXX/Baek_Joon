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
#include <unordered_map>
#include <numeric>

using namespace std;

int N, L, R;
int arr[50][50];
bool visited[50][50];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void bfs(int x, int y, vector<pair<int, int>>& union_countries, int& sum) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	union_countries.push_back({ x, y });
	sum += arr[x][y];

	while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();
		for (int d = 0; d < 4; ++d) {
			int nx = cx + dx[d], ny = cy + dy[d];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
				int diff = abs(arr[cx][cy] - arr[nx][ny]);
				if (diff >= L && diff <= R) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
					union_countries.push_back({ nx, ny });
					sum += arr[nx][ny];
				}
			}
		}
	}
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < N; ++j) 
            cin >> arr[i][j];
        
    

    int days = 0;
    while (true) {
        bool moved = false;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!visited[i][j]) {
                    vector<pair<int, int>> union_countries;
                    int sum = 0;
                    bfs(i, j, union_countries, sum);
                    if (union_countries.size() > 1) {
                        moved = true;
                        int avg = sum / union_countries.size();
                        for (auto& p : union_countries) 
                            arr[p.first][p.second] = avg;
                        
                    }
                }
            }
        }
        if (!moved) break;
        days++;
    }

    cout << days;
    return 0;

}