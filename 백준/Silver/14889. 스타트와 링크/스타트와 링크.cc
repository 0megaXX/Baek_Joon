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

using namespace std;
#define MAXX 99999999



int stats[21][21];
bool visit[22];
int n;
int ans = MAXX; 

void DFS(int x, int pos) // x는 카운트, pos는 다음 값
{
	if (x == n / 2) // 카운트수가 정원의 1/2이 됐을 때 능력치합 계산
	{
		int start, link;
		start = 0;
		link = 0;

		for (int a = 1; a <= n; a++)
			for (int b = 1; b <= n; b++)
			{
				if (visit[a] == true && visit[b] == true) 
					start += stats[a][b];
				if (visit[a] == false && visit[b] == false)
					link += stats[a][b];
			}
		

		int temp = abs(start - link);
		if (ans > temp)
			ans = temp;

		return;
	}

	for (int a = pos; a < n; a++)
	{
		visit[a] = true;
		DFS(x + 1, a + 1);
		visit[a] = false;
	}

}


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	cin >> n;

	for (int a = 1; a <= n; a++)
		for (int b = 1; b <= n; b++)
			cin >> stats[a][b];


	DFS(0, 1); // 카운트 0회부터 숫자는 1부터 시작

	cout << ans;
	return 0;

}
