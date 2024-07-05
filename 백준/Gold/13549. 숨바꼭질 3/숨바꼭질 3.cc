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

int arr[100001];
bool visit[100001];
int sister, brother;
int want = 100001;


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fill_n(arr, 100001, 100001);
	memset(visit, false, sizeof(visit));

	cin >> sister >> brother;

	queue<pair<int, int>>q;
	q.push({sister, 0});

	while (!q.empty())
	{
		
		int cur = q.front().first;
		int ct = q.front().second;
		q.pop();
		

		visit[cur] = true;
		if (arr[cur] < ct)
			continue;
		arr[cur] = ct;

		if (cur == brother)
		{	
			want = min(want, ct);
		}
	
		
		if (cur * 2 <= 100000 && !visit[cur * 2])
		{
			//visit[cur * 2] = true;
			q.push({ cur * 2,ct });
		}
		if (cur + 1 <= 100000&& !visit[cur +1])
		{
			//visit[cur+1] = true;
			q.push({ cur +1,ct + 1 });
		}
		if (cur-1 >=0 && !visit[cur -1])
		{
			//visit[cur-1] = true;
			q.push({ cur - 1,ct+1 });
		}


	}

	cout << want;
}
