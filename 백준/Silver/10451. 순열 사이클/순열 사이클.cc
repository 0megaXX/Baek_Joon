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

int parent[1001];


int find_parent(int x) 
{
	if (parent[x] == x)
        return x;

	return parent[x] = find_parent(parent[x]);
}

void union_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int same_parent(int a, int b)
{
	a = find_parent(a);
	b = find_parent(b);

	if (a == b)
        return 1;

	else
        return 0;
}


int main() {
	ios_base::sync_with_stdio(false);

	int cass;
	cin >> cass;
	while (cass--)
	{
		int sizz;
		cin >> sizz;
		for (int a = 1; a <= sizz; a++)
			parent[a] = a;
		
		int ct = 0;
		for (int a = 1; a <= sizz; a++)
		{
			int b;
			cin >> b;
			if (!same_parent(a, b))
				union_parent(a, b);
	
		}

		for (int a = 1; a <= sizz; a++)
			if (parent[a] == a)
				ct++;
		cout << ct << '\n';
	}
    return 0;
}