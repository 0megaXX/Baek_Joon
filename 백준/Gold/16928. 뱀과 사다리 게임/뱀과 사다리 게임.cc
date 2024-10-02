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

vector<int>Map(101, MAXX);
map<int, int>m_rope;
map<int, int>m_snake;

void fn()
{
	queue<int>q;
	q.push(1);

	while (!q.empty())
	{
		int cur = q.front();

		if (cur == 100)
			return;
		q.pop();


		if (m_snake.find(cur) != m_snake.end()) // 현재 위치에 대한 뱀이 있으면 있다면 강제 이동임
		{
			if (Map[m_snake.find(cur)->second] > Map[cur]) // 최단경로 갱신 가능이라면
			{
				Map[m_snake.find(cur)->second] = Map[cur];
				q.push(m_snake.find(cur)->second);
			}
			continue; // 뱀은 반드시 떨어지기만 하기에 여기서 더 이동못함
		}

		else if (m_rope.find(cur) != m_rope.end()) // 현재 위치에 대한 사다리나 정보가 있다면
		{
			if (Map[m_rope.find(cur)->second] > Map[cur]) // 최단경로 갱신 가능이라면
			{
				Map[m_rope.find(cur)->second] = Map[cur];
				q.push(m_rope.find(cur)->second);
			}
		}
		int next;

		for (int a = 1; a <= 6; a++)
		{
			next = cur + a; // 다음 도착지는 a만큼 더 간 칸

			if (next <= 100 && Map[cur] + 1 < Map[next]) // 최단경로 갱신 가능이라면
			{
				Map[next] = Map[cur] + 1;
				q.push(next);
			}


		}

	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int rope, snake;
	cin >> rope >> snake;

	for (int a = 0; a < rope; a++)
	{
		int start, end;
		cin >> start >> end;
		m_rope[start] = end;

	}

	for (int a = 0; a < snake; a++)
	{
		int start, end;
		cin >> start >> end;
		m_snake[start] = end;
	}

	Map[1] = 0; // 시작위치의 값을 0
	fn();


	cout << Map[100];


}