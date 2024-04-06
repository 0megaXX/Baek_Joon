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


int parent[100001];
int time_[100001];
bool visit[100001]{ false };
vector<int> ans;
vector<int> path;

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int sister, brother;
	cin >> sister >> brother;
	memset(parent, 0, sizeof(parent));
	memset(time_, 0, sizeof(time_));
	queue<int>q;

	q.push( sister);
	visit[sister] = true;
	int rs;
	while (!q.empty())
	{
		
		int cur = q.front();
		q.pop();

	
		int cass[3] = { cur - 1,  cur + 1, cur * 2 };
		for (int a = 0; a < 3; a++)
		{
			if (cass[a] <= 100000 && cass[a]>=0 && !visit[cass[a]])
			{
				q.push(cass[a]);
				parent[cass[a]] = cur;
				visit[cass[a]] = true;
				time_[cass[a]] = time_[cur] + 1;
			}

			if (cass[a] == brother) {
				rs = time_[cass[a]];
				break;
			}
		}
		
	}

	cout << rs << "\n";


	path.push_back(brother);
	for (int i = 0; i < rs; i++) {
		path.push_back(parent[brother]);
		brother = parent[brother];
	}
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << ' ';
	

}
