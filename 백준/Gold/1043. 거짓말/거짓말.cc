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
#include <unordered_map>


using namespace std;

int parent[51];

int find_parent(int son)
{
	if (parent[son] != son)
		return parent[son] = find_parent(parent[son]);
	else
		return son;
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;



}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int human, cass;
	cin >> human >> cass;

	int Lie_know_Group=0;
	for (int a = 0; a <= human; a++)
		parent[a] = a;

	int I_Know_Lie;
	cin >> I_Know_Lie;

	if (I_Know_Lie > 0)
	{
		int center;
		cin >> center;
		for (int a = 1; a < I_Know_Lie; a++)
		{
			int b;
			cin >> b;
			union_parent(center, b);
		}
		Lie_know_Group = parent[center];
	}

	vector<vector<int>>v(cass + 1);

	for (int a = 0; a < cass; a++)
	{
		int mem;
		cin >> mem;

		int center;
		cin >> center;
		v[a].push_back(center);
		for (int b = 1; b < mem; b++)
		{
			int who;
			cin >> who;
			union_parent(center, who);
			v[a].push_back(who);

		}

	}
	int ct = 0;
	for (int a = 0; a < cass; a++)
	{
		for (int b = 0; b < v[a].size(); b++)
		{
			if ( find_parent(parent[v[a][b]] )== find_parent (parent[Lie_know_Group]))
				goto run;
		}

		ct++;
	run:;

	}


	cout << ct;
	
	return 0;
}