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


int arr[50][50];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int row, col;
	int ans;
	cin >> row >> col;
	for (int a = 0; a < row; a++)
	{
		cin >> s;
		for (int b = 0; b < col; b++)
			arr[a][b] = s[b] - '0';
	}
	int len;
	int maxx = min(row, col); // 최대 정사각형의 변길이

	int aa, bb, cc, dd; // 좌상, 좌하, 우상, 우하
	for (len = 1; len <= maxx; len++) // len은 변 길이
		for (int a = 0; a <= row - len; a++) // 시작 x
			for (int b = 0; b <= col - len; b++) // 시작 y
			{
				aa = arr[a][b]; // 좌상
				bb = arr[a + len - 1][b]; // 좌하
				cc = arr[a][b + len - 1]; // 우상
				dd = arr[a + len - 1][b + len - 1] ; // 우하

				if (aa ==bb && bb == cc && cc == dd) // 각 꼭지점의 수가 같다면
					ans = len;
			}

	cout << ans * ans; // 크기이기에 변 * 변
}