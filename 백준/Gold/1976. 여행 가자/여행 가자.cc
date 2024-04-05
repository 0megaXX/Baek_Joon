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

int parent[201];

int find_pt(int a)
{
	if (parent[a] == a)
		return parent[a];
	else
		return parent[a] = find_pt(parent[a]);


}

void union_pt(int a, int b)
{
	
	a = find_pt(a);
	b = find_pt(b);
	if (a < b) parent[b] = a;

	else parent[a] = b;


}



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int city;
	cin >> city;

	for (int a = 1; a <= city; a++)
		parent[a] = a;

	int cass;
	cin >> cass;

	for (int a = 1; a <= city; a++)
	{
		for (int b = 1; b <= city; b++)
		{

			int c;
			cin >> c;
			if (c==1)
				union_pt(a, b);
			
		}
	}

	int start;
	for (int a = 1; a <= cass; a++)
	{
		int node;
		cin >> node;

		if (a == 1)
			start = find_pt(node);
		else if (start != find_pt(node))
		{
			cout << "NO";
			return 0;
		}
		

	}
	cout << "YES";

}
