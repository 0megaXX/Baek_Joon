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

int parent[1000001];


int find_parent(int a)
{
	if (a == parent[a])
        return a;
	return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) 
{
	a = find_parent(a);
    b = find_parent(b);
	if (a == b)
        return;

	parent[a] = b;
}


int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int x, y;
    
	for (int a = 0; a < n; a++)
		parent[a] = a;

	int dongbang = n;
	while (m--) 
    {
		cin >> x >> y;
		x, y;

		while (find_parent(x) != find_parent(y)) // 두 동방이 이어지지 않았다면
        {
			--dongbang;

			int next = find_parent(x) + 1; // 사이의 동방을 전부 이어야함 함
			union_parent(x, y);
			x = next; // 다음방으로 이동
		}
	}

	cout << dongbang;


	return 0;
}