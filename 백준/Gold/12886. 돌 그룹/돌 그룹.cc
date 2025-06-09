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


bool visited[1501][1501]; // 3차원배열을 안하는 이유는 두 값만 알아도 남은 한 값의 값을 알 수 있음.

bool bfs(int val1, int val2, int val3)
{
	int summ = val1 + val2 + val3;
    
	if (summ % 3 != 0) // 3등분이 안된다면 답에 도달 불가능
        return false;

	queue<pair <int, int>> q;
	q.push(make_pair(val1, val2));
	visited[val1][val2] = true;

	while (!q.empty()) 
    {
		int num1 = q.front().first;
		int num2 = q.front().second;
		int tmp[3] = { num1, num2, summ - (num1 + num2) };
        
		q.pop();
        
		for (int i = 0; i < 3; i++) 
        {
			for (int j = 0; j < 3; j++) 
            {
				if (tmp[i] < tmp[j]) // 양쪽의 크기가 다르다면 연산
                {
					int x = tmp[i] * 2;
					int y = tmp[j] - tmp[i];

					if (visited[x][y]) // 방문한적있음 통과
                        continue;
                    
					visited[x][y] = true;
					q.push(make_pair(x,y));
				}
			}
		}

    if (visited[summ / 3][summ / 3]) // 3등분으로 한 값이 도달한 적 있다면
        return true;
        
	}
    
	

    
	return false;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(visited, false, sizeof(visited));
	int val1, val2, val3;
	
    cin >> val1 >> val2 >> val3;
	cout << bfs(val1, val2, val3);
    

    return 0;
}

