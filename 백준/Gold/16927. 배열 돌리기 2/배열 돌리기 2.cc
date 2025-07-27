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

int n, m, r;
int arr[301][301];


// 돌리는 함수
void fn(int start, int len){
   
	int t = r % len;

   
	for(int a = 0; a < t; a++)
    {
		int tmp = arr[start][start];

        // 좌로 이동
		for(int b = start + 1; b <= m - start + 1; b++)
			arr[start][b - 1] = arr[start][b];

        // 상으로 이동
		for(int b = start + 1; b <= n - start + 1; b++)
			arr[b - 1][m - start + 1] = arr[b][m - start + 1];

        // 우로 이동
		for(int b = m - start + 1; b >= start + 1; b--)
			arr[n - start + 1][b] = arr[n - start + 1][b - 1];

        // 하로 이동
		for(int b = n - start + 1; b >= start + 2; b--)
			arr[b][start] = arr[b - 1][start];

        // 마무리 이동
		arr[start + 1][start] = tmp;
	}
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;
	for(int a = 1; a <= n; a++)
		for(int b = 1; b <= m; b++)
			cin >> arr[a][b];
		
	
	
	int cnt = min(n, m) / 2;
   
	int N = n, M = m;

    // 테두리 하나씩 안으로 들어가면서 회전
	for(int a = 1; a <= cnt; a++)
    {
		fn(a, 2 * N + 2 * M - 4); // 가장 밖 테두리의 박스 수. 4는 중복되는 모서리
		N -= 2; // 테두리가 줄어드니 2씩 감소
		M -= 2; // 테두리가 줄어드니 2씩 감소
	}

	for(int a = 1; a <= n; a++){
		for(int b = 1; b <= m; b++)
			cout << arr[a][b] << " ";
		
		cout << '\n';
	}

    return 0;
}