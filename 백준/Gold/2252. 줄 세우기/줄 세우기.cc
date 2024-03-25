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

	int people, cass;
	cin >> people >> cass;

	vector<vector<int>>back_people(people + 1);
	vector<int>first(people + 1, 0);
	for (int a = 0; a < cass; a++)
	{
		int f, s;
		cin >> f >> s;
		back_people[f].push_back(s);
		first[s]++;
	}


	priority_queue<int,vector<int>,greater<>>pq;

	for (int a = 1; a <= people; a++)
	{
		sort(back_people[a].begin(), back_people[a].end());
		if (first[a] == 0)
		{
			pq.push(a);
		}
	}

	while (!pq.empty())
	{
		int cur = pq.top();
		pq.pop();
		cout << cur << ' ';

		for (int a = 0; a < back_people[cur].size(); a++)
		{
			first[back_people[cur][a]]--;
			if (first[back_people[cur][a]] == 0)
				pq.push(back_people[cur][a]);



		}


	}

}
