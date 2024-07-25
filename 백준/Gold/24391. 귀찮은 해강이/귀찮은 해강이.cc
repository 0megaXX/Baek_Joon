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
int parent[100001];


int find_parent(int a)
{
	if (parent[a] == a)
		return a;
	else
		return parent[a] = find_parent(parent[a]);

}

void union_parent(int a, int b)
{


	if (a > b)
		parent[b] = a;
	else
		parent[a] = b;
	



}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int a = 1; a <= N; a++)
		parent[a] = a; 

	for (int a = 0; a < M; a++)
	{
		int b, c;
		cin >> b >> c;
		
		int b_p = find_parent(b);
		int c_p = find_parent(c);
		if (b_p != c_p)
			union_parent(b_p, c_p);

	}

	int start;
	int ct = 0;
	for (int a = 0; a < N; a++)
	{
		int b;
		cin >> b;
		if (a == 0) // 처음은 노카운트
		{
			start = find_parent(b);
			continue;
		}
		else
		{
			if (find_parent(b) == start) // 같은 건물이면
				continue;
			else
			{
				ct++;
				start = find_parent(b);
			}

		}
	}
	cout << ct;
}