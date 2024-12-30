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
#include <chrono>

using namespace std;
#define MAXX 99999999


int parent[100001];

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
	if (a < b)
		parent[b] = a;

	else parent[a] = b;


}



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node,edge;
	cin >> node>>edge;

	for (int a = 1; a <= node; a++)
		parent[a] = a;


	int ct = 0;

	for (int a = 1; a <= edge; a++)
	{
		int b, c;
		cin >> b >> c;

		if (find_pt(b) != find_pt(c)) // 연결이 안되어있다면 연결
			union_pt(b, c);
		else // 사이클이 존재하기에 연결하면 안됨
			ct++;
			
	}

	int root = 1;

	for (int a = 1; a <= node; a++)
	{
		int cur_p = find_pt(a);
		if (cur_p != root)
		{
			union_pt(cur_p, root);
			ct++;
		}

	}

	cout << ct;
}
