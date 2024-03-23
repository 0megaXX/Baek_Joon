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

int Map[10][10];
vector<pair<int, int>> empty_arr;
bool Possible(int x, int y, int k)
{
	for (int i = 1; i <= 9; i++) {
		
		if (Map[x][i] == k && i != y) return false; // 같은 행에 현재위치를 제외하고 이미 k가 있다면

		if (Map[i][y] == k && i != x) return false; // 같은 열에 현재위치를 제외하고 이미 k가 있다면

		int nx = (x - 1) / 3 * 3 + 1 + (i - 1) / 3;
		int ny = (y - 1) / 3 * 3 + 1 + (i - 1) % 3;
		if (Map[nx][ny] == k && !(nx == x && ny == y)) return false;
	}
	return true;

}


void backTracking(int start)
{
	if (start == empty_arr.size()) // 0인 칸을 모두 다 채웠다면
	{
		for (int a = 1; a <= 9; a++)
		{
			for (int b = 1; b <= 9; b++)
				cout << Map[a][b];
			cout << endl;
		}

		exit(0);
	}

	int x = empty_arr[start].first;
	int y = empty_arr[start].second;
	for (int k = 1; k <= 9; k++)
	{
		if (Possible(x, y, k)) {
			Map[x][y] = k;
			backTracking(start + 1);
			Map[x][y] = 0;
		}
	}
}


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int a = 1; a <= 9; a++)
	{
		string s;
		cin >> s;
		for (int b = 1; b <= 9; b++)
		{
			Map[a][b] = s[b-1] - '0';

			if (Map[a][b] == 0)
				empty_arr.push_back({ a,b });
		}
	}
	backTracking(0);
}
