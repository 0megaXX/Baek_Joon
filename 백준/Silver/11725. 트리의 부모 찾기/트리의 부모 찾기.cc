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

int Parent[100001];
bool visit[100001];
vector<vector<int>>v(100001);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(visit, false, sizeof(visit));
	int node;
	cin >> node;
	for (int a = 0; a < node - 1; a++) 
	{
		int b, c;
		cin >> b >> c;
		v[b].push_back(c);
		v[c].push_back(b);
	}


	queue<int>q;
	q.push(1);
	visit[1] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : v[cur]) 
			if (!visit[next])
			{ 
				visit[next] = true; 
				Parent[next] = cur; 
				q.push(next);
			}
	
	}


	for (int a = 2; a <= node; a++)
		cout << Parent[a] << '\n';
		
}