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


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int singer, cass;
	cin >> singer >> cass;
	vector<vector<int>>back_list(singer+1);
	vector<int>first_ct(singer + 1,0);
	vector<int>rsv;

	for (int a = 0; a < cass; a++)
	{
		int people;
		cin >> people;
		vector<int>vv;
		vv.push_back(0);
		for (int b = 1; b <= people; b++)
		{
			int c;
			cin >> c;
			vv.push_back(c);

		}
		for (int b = 2; b <= people; b++)
		{
			back_list[vv[b - 1]].push_back(vv[b]);
			first_ct[vv[b]]++;
		}
	}

	queue<int>q;
	for (int b = 1; b <= singer; b++)
		if (first_ct[b] == 0)
			q.push(b);


	while (!q.empty())
	{
		int cur = q.front();
		rsv.push_back(cur);
		q.pop();
		for (int a = 0; a < back_list[cur].size(); a++)
		{
			first_ct[back_list[cur][a]]--;
			if (first_ct[back_list[cur][a]]==0)
			{
				q.push(back_list[cur][a]);
			}
		}
	}

	if (rsv.size() == singer)
		for (int i = 0; i < rsv.size(); i++)
			cout << rsv[i] << '\n';
	else
		cout << 0;


}
