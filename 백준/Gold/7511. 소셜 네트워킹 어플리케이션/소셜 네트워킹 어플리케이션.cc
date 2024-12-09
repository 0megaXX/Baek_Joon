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

int parent[1000001];


int find_parent(int a)
{

	if (a == parent[a])
		return a;
	else
		return  parent[a] = find_parent(parent[a]);


}

void union_parent(int a, int b)
{

	if (a > b)
		parent[a] = b;
	else
		parent[b] = a;



}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int cass;
	cin >> cass;
	for (int i = 1; i <= cass; i++)
	{
		int node, edge;
		cin >> node;

		for (int a = 0; a <= node; a++)
			parent[a] = a;

		cin >> edge;

		for (int a = 1; a <= edge; a++)
		{

			int b, c;
			cin >> b >> c;
			int b_p = find_parent(b);
			int c_p = find_parent(c);

			if (b_p != c_p) // 만약 연결되지 않았다면
				union_parent(b_p, c_p);

		}

		cout << "Scenario " << i << ":\n";
		int q;
		cin >> q;
		for (int a = 0; a < q; a++) {

			int b, c;
			cin >> b >> c;
			int b_p = find_parent(b);
			int c_p = find_parent(c);
			if (b_p == c_p) // 연결되어있다면
				cout << "1\n";
			else
				cout << "0\n";
		}




		cout << '\n';


	}
}
