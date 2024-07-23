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
#define MAXX 987654321
using namespace std;


vector<vector<int>>node(1001);
vector<int> first(1001);
vector<pair<int,int>>len(1001);

void clear()
{

	for (int a = 0; a < 1001; a++)
		node[a].clear();


}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cass;
	cin >> cass;
	while (cass--)
	{
	//	clear();
		int K, M, P;
		cin >> K >> M >> P;
		int maxx = 1;
		for (int a = 0; a < P; a++)
		{
			int b, c;
			cin >> b >> c;
			node[b].push_back(c);
			first[c]++;
		}

		queue<int>q;


		for (int a = 1; a <= M; a++)
		{
			if (first[a] == 0)
			{
				len[a] = { 1,1 };
				q.push(a);
			}
			else
				len[a] = { 0,0 };

		}

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			

			for (int a = 0; a < node[cur].size(); a++)
			{
				int next = node[cur][a];
				first[next]--;
				
				if (len[next].first < len[cur].first)
					len[next] = len[cur];

				else if (len[next].first == len[cur].first)
					len[next].second += len[cur].second;

				if (first[next] == 0)
				{
					
					if (node[next].size() == 0) // 끝나는 곳이면
					{

						maxx = len[next].second >= 2 ? len[next].first +1 : len[next].first;
						/*cout << next << " 의 길이는 " << len[next].first << ' ' <<
							len[next].second << endl;*/
						break;
					}
					else
					{
						len[next] = { (len[next].second>=2 ?  len[next].first + 1
							: len[next].first) ,1};
						q.push(next);
					/*	cout << next << " 의 길이는 " << len[next].first <<' '<<
							len[next].second <<endl;*/
					
					}
				}


			}
		}

		cout << K << ' ' << maxx << '\n';
		clear();
	}
}
