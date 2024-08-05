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

int sizz, cass;


vector<set<int>> v;
queue<int>q;
queue<int>rs_q;

void bfs()
{
	for (int a = 0; a < cass; a++)
	{
		int b;
		cin >> b;
		q.push(b);
	}

	if (q.front() != 1)
	{
		cout << 0;
		return;
	}
	rs_q.push(q.front());
	q.pop();

	while (!rs_q.empty())
	{
		int cur = rs_q.front();
		rs_q.pop();

		for (auto a = v[cur].begin(); a != v[cur].end(); a++)
		{

			if (v[cur].find(q.front()) != v[cur].end()) // 다음 가야할 노드가 현재 노드에 연결되어있다면
			{
				rs_q.push(q.front());
				//cout << q.front() << "에 도착\n";
				q.pop();
			}


		}



	}
	if (q.empty())

		cout << 1;

	else
		cout << 0;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> cass;

	v.resize(cass + 1);


	for (int a = 0; a < cass - 1; a++)
	{
		int b, c;
		cin >> b >> c;
		v[b].insert(c);
		v[c].insert(b);
	}
	bfs();


}