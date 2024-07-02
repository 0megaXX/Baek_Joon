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
using namespace std;
int arr[21][21];



int row, col,rs=0;
void dfs(int r, int c, int range, int* vis)
{
	if (0 <= c && c < col && 0 <= r && r < row && !vis[arr[r][c]])
	{
		vis[arr[r][c]]++;
		range++;

		// 결과 값이 현재까지의 길이보다 더 작은 경우 초기화
		if (range > rs)
			rs = range;
		dfs(r + 1, c, range, vis);
		dfs(r - 1, c, range, vis);
		dfs(r, c + 1, range, vis);
		dfs(r, c - 1, range, vis);
		// 상하 좌우를 살폈는데 전부 봤었던 알파벳인 경우 이전 경로로 돌아가기 전 방문 체크 해제
		vis[arr[r][c]]--;
	
	}
		


}



int main(void)
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int visit[26]{ 0 };
	int range=0;
	cin >> row >> col;
	for (int a = 0; a < row; a++)
	{
		string s;
		cin >> s;
		for (int b = 0; b < col; b++)
			arr[a][b] = s[b] - 65;
	}
	dfs(0, 0, 0,visit);

	cout << rs;


}
