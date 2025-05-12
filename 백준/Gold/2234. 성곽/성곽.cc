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
#define MAXX 2147483647

int N, M;
int arr[51][51];
int visit[51][51];

int offset_x[4] = { -1,1,0,0 };
int offset_y[4] = { 0,0,1,-1 };
int masks[4] = {1,4,8,2}; // 서동남북
int compSize[2501];

int dfs(int x, int y, int ct) 
{
	if (visit[y][x]) 
        return 0;
    
	visit[y][x] = ct;
	int ret = 1;
    
	for (int i = 0; i < 4; ++i)
    {
		int nx = x+offset_x[i];
		int ny = y+offset_y[i];
		if (nx < 0 || nx > N - 1 || ny < 0 || ny > M - 1)
            continue;
        
		if (visit[ny][nx])
            continue;
        
		if (arr[y][x] & masks[i]) 
            continue;
		ret += dfs(nx, ny,ct);
	}
    
	return ret;
}


int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


    int room_ct = 0;
    int max_area_original = 0;
    int max_area_last = 0;
    
    cin >> N >> M;
	for (int a = 0; a < M; a++) 
		for (int b = 0; b < N; b++) 
			cin >> arr[a][b];
		
	

	for (int a = 0; a < M; a++) 
		for (int b = 0; b < N; b++)
        {
			if (visit[a][b]) 
                continue;
			room_ct += 1;
			compSize[room_ct] = dfs(b,a, room_ct);
			max_area_original = max(max_area_original, compSize[room_ct]);
		}
	
	for (int a = 0; a < M; a++) 
		for (int b = 0; b < N; b++) 
        {
            
			if (a + 1 < M) 
            {
				int c = visit[a + 1][b];
				int d = visit[a][b];
				if (c != d) 
					max_area_last = max(max_area_last, compSize[c] + compSize[d]);
				
			}
			if (b + 1 < N) {
				int c = visit[a][b + 1];
				int d = visit[a][b];
				if (c != d) {
					max_area_last = max(max_area_last, compSize[c] + compSize[d]);
				}
			}


    	}
	
	cout << room_ct << "\n" << max_area_original<< "\n" << max_area_last;

	return 0;
}