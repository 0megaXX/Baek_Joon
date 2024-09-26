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

int row, col;
int arr_a[51][51];
int arr_b[51][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> row >> col;


	for (int a = 0; a < row; a++)
	{
		string s;
		cin >> s;
		for (int b = 0; b < col; b++)
			arr_a[a][b]=s[b] - '0';

	}

	for (int a = 0; a < row; a++)
	{
		string s;
		cin >> s;
		for (int b = 0; b < col; b++)
		{
			int cur = s[b] - '0';
			if (arr_a[a][b] == cur) // 기존 배열과 숫자가 같다면 0 다르면 1
				arr_b[a][b] = 0;

			else
				arr_b[a][b] = 1;

		}
	}
	int ct = 0;


	if (row < 3 || col < 3) // 3 * 3 이 안된다면 뒤집기가 불가능하기에 뒤집지 않고 비교
		for (int a = 0; a < row; a++)
			for (int b = 0; b < col; b++)
				if (arr_b[a][b])
				{
					cout << -1;
					return 0;
				}


	for (int a = 0; a < row; a++)
		for (int b = 0; b < col; b++)
			if (arr_b[a][b]) // 현재 위치가 다르다면
			{
				//3*3 범위내라면 뒤집기
				if (a < row - 2 && b < col - 2) // 범위벗어나는거 방지
				{

					for (int x = a; x < a + 3; x++) {
						for (int y = b; y < b + 3; y++) {
							arr_b[x][y] = !arr_b[x][y];
						}
					}

					ct++;
				}
				//범위 밖이라면 더이상 뒤집을 수 없음
				else
				{
					cout << -1;
					return 0;
				}

			}

	cout << ct ;
}