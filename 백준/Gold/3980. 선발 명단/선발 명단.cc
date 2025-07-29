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

int rs = 0;
int arr[11][11] = {0};
bool visit[11];

void back(int ct, int total) 
{
	if (ct == 11) 
    {
		rs = max(rs, total); // 최대 능력치 갱신
		return;
	}

	for (int a = 0; a < 11; a++) 
    {
		if (arr[ct][a] == 0) // 각 선수는 능력치가 0인 포지션에 배치될 수 없다.
			continue;
        
		if (visit[a] == 0) // 조합에 포함이 안되었다면 이 조합으로 탐색
        {
            // 백트래킹
			visit[a] = 1;
			back(ct + 1, total + arr[ct][a]);
			visit[a] = 0;
		}
	}
    
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;
    cin >> t;

	while (t--) 
    {
        rs = 0;
		for (int a = 0; a < 11; a++)
			for (int b = 0; b < 11; b++)
				cin >> arr[a][b];
        
		memset(visit, 0, sizeof(visit)); // 방문초기화
        
		back(0, 0);
		cout << rs << '\n';
	}

    return 0;
}

