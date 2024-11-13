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

#define MAXX 1000000000
using namespace std;


int max_pos, max_h; // 최대 높이의 위치와 높이
int arr[1001];
int rs = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int N,L, H;
	cin >> N;

	for (int a = 0; a < N; a++)
	{
		cin >> L >> H;
		arr[L] = H;

		if (max_h < H)
		{
			max_pos = L;
			max_h = H;
		}
	}

	int L_h = 0; // 왼쪽 영역의 최고 높이
	for (int a = 1; a < max_pos; a++)
	{
		L_h = max(L_h, arr[a]);
		rs += L_h;
	}

	int R_h = 0; // 오른쪽 영역의 최고 높이

	for (int a = 1000; a > max_pos; a--)
	{
		R_h = max(R_h, arr[a]);
		rs += R_h;
	}

	cout << rs + max_h;
   
}


