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

	vector<int>v(100001, 0);
	vector<int>parent(100001, 0);

	int parent_find(int a)
	{
		if (parent[a] != a)
			return parent_find(parent[a]);
		else
			return a;
	}

	void union_find(int a, int b)
	{
		int a_p = parent_find(a);
		int b_p = parent_find(b);

		if (v[a_p] < v[b_p])
		{
			parent[b_p] = parent_find(a_p);
			v[b] = v[a];
		}
		else
		{
			parent[a_p] = parent_find(b_p);
			v[a] = v[b];
		}
	
	
	}

	int main() {
		ios_base::sync_with_stdio(false);
		cin.tie(0);
		cout.tie(0);
	
		int people, cass, money;
		cin >> people >> cass >> money;
		for (int a = 1; a <= people; a++)
		{
			cin >> v[a];
			parent[a] = a;
		}
		
		for (int a = 1; a <= cass; a++)
		{
			int b, c;
			cin >> b >> c;
			union_find(b, c);
		}
		long long summ = 0;
		for (int a = 1; a <= people; a++)
		{
			if (parent_find(a) == a)
				summ += v[a];

		}
		if (summ <= money)
			cout << summ;
		else
			cout << "Oh no";
	}