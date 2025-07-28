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
#include <regex>

using namespace std;
#define MAXX 2147483647

int n;
int arr[65][65];
int visit[65][65];
queue<pair<int,int>> q;

int dx[2] = { 0,1 };
int dy[2] = { 1,0 };

bool bfs(int x, int y) {

	q.push(make_pair(x, y));
	visit[0][0] = 1;

	while (!q.empty()) 
    {
		int x = q.front().first;
		int y = q.front().second;
		int cur = arr[x][y];
		visit[x][y] = 1;
		q.pop();

		for (int a = 0; a < 2; a++) 
        {
			int nx = x + cur * dx[a];
			int ny = y + cur * dy[a];
			if (!visit[nx][ny] && nx < n && ny < n) 
            {
                visit[nx][ny] = 1;
                if (arr[nx][ny] == -1) // 도착시
                    return 1;
                
                q.push(make_pair(nx, ny));
			}
		}
	}
	return 0;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> n;

	for (int a= 0; a < n; a++) 
		for (int b = 0; b < n; b++) 
			cin >> arr[a][b];
		

	if (bfs(0,0)) 
		cout << "HaruHaru" ;
	
	else 
		cout << "Hing" ;
	

   
    return 0;
}

