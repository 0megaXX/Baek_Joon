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


bool visit[201][201][201];
int bottle1_max, bottle2_max, bottle3_max;
set<int>s;

void dfs()
{
	queue<pair<pair<int, int>, int>>q;
	q.push({ {0,0},bottle3_max });

	while (!q.empty())
	{
		int bt1_cur = q.front().first.first;
		int bt2_cur=q.front().first.second;
		int bt3_cur = q.front().second;

		q.pop();

		if(visit[bt1_cur][bt2_cur][bt3_cur])
			continue;
		visit[bt1_cur][bt2_cur][bt3_cur] = true;


		if (bt1_cur == 0)
			s.insert(bt3_cur);


		if (bt1_cur + bt2_cur <= bottle2_max) // 1의 물을 전부 2에 부을 수 있다면
			q.push({ {0,bt2_cur + bt1_cur},bt3_cur });
		else // 1의 물의 일부만 2에 부을 수 있다면
			q.push({ {(bt1_cur + bt2_cur)-bottle2_max,bottle2_max},bt3_cur });
		
		if (bt1_cur + bt3_cur <= bottle3_max) // 1의 물을 전부 3에 부을 수 있다면
			q.push({ {0,bt2_cur},bt3_cur + bt1_cur});
		else // 1의 물의 일부만 3에 부을 수 있다면
			q.push({ {(bt1_cur + bt3_cur)-bottle3_max,bt2_cur},bottle3_max });

		
		if (bt1_cur + bt2_cur <= bottle1_max) // 2의 물을 전부 1에 부을 수 있다면
			q.push({ {bt2_cur + bt1_cur,0},bt3_cur });
		else // 2의 물의 일부만 1에 부을 수 있다면
			q.push({ {bottle1_max,(bt1_cur + bt2_cur)- bottle1_max},bt3_cur });

		if (bt2_cur + bt3_cur <= bottle3_max) // 2의 물을 전부 3에 부을 수 있다면
			q.push({ {bt1_cur,0},bt3_cur + bt2_cur });
		else // 2의 물의 일부만 3에 부을 수 있다면
			q.push({{bt1_cur,(bt2_cur + bt3_cur)-bottle3_max},bottle3_max });

		if (bt1_cur + bt3_cur <= bottle1_max) // 3의 물을 전부 1에 부을 수 있다면
			q.push({ {bt3_cur + bt1_cur,bt2_cur},0 });
		else // 3의 물의 일부만 1에 부을 수 있다면
			q.push({ {bottle1_max,bt2_cur}, (bt1_cur + bt3_cur)-bottle1_max});

		if (bt2_cur + bt3_cur <= bottle2_max) // 3의 물을 전부 2에 부을 수 있다면
			q.push({ {bt1_cur,bt3_cur + bt2_cur},0 });
		else // 3의 물의 일부만 2에 부을 수 있다면
			q.push({ {bt1_cur,bottle2_max}, (bt2_cur + bt3_cur)-bottle2_max });
	}




}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(visit, false, sizeof(visit));

	cin>> bottle1_max>> bottle2_max>> bottle3_max;

	dfs();

	for (auto a = s.begin(); a != s.end(); a++)
		cout << *a << ' ';
	
}