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
#define MAXX 987654321
using namespace std;


int parent[1000001];
int len[1000001];

int parent_find(int a) // 부모찾기
{
	if (parent[a] != a)
		return parent_find(parent[a]);
	else
		return a;
}

void union_find(int a, int b)
{

	if (a < b) // b의 부모가 더 크면
	{

		parent[b] = parent_find(a); // b의 부모의 부모는 a의 부모의 부모 
		len[a] += len[b];
	}
	else
	{
		parent[a] = parent_find(b);
		len[b] += len[a];
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int a = 1; a <= 1000000; a++)
	{
		parent[a] = a;
		len[a] = 1;
	}
	int Q;
	cin >> Q;
	while (Q--)
	{
		char what;
		cin >> what;
		
		if (what == 'I')
		{
			
			int a, b;
			cin >> a >> b;

			int a_p = parent_find(a);
			int b_p = parent_find(b);
			if (a_p != b_p)
				union_find(a_p, b_p);
			//cout << max(len[a_p], len[b_p]) << '\n';


		}
		else
		{
			int a;
			cin >> a;
			cout << len[parent_find(a)] << '\n';

		}

	}
}
