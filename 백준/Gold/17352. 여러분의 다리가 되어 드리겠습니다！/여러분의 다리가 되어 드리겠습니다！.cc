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

int parent[300001];

int find_parent(int son)
{
	if (parent[son] != son)
		return parent[son] = find_parent(parent[son]);
	else
		return son;
}

void union_parent(int a, int b)
{

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;


}

vector<pair<int,int>>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int human;
	cin >> human;
	for (int a = 1; a <= human; a++)
		parent[a] = a;

	for (int a = 1; a <= human - 2; a++)
	{
		int b, c;
		pair<int, int>p;
		cin >> b >> c;
		int bp = find_parent(b);
		int cp = find_parent(c);

		if (b > c)
			p = { c,b };
		else
			p = { b,c };

		v.push_back(p);
	}

	sort(v.begin(), v.end());

	for (int a = 0; a < human - 2; a++)
	{
		int bp = find_parent(v[a].first);
		int cp = find_parent(v[a].second);
		if (bp != cp)
			union_parent(bp, cp);


	}


	/*for (int a = 1; a <= human; a++)
		cout << find_parent(a) << ' ';

	cout << "-------------------\n";	*/


	for (int a = 2; a <= human; a++)
		if (find_parent(a - 1) != find_parent(a))
		{

			cout << find_parent(a - 1) << ' '<<find_parent(a);
			break;
		}
}