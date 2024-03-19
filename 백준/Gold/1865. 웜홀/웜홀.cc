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

int n, m, w;
int MAX = 30000000;

struct edge {
	int s, e, t;
};

bool time_travel(int n, vector<edge> edges) {
	vector<int> dist(n + 1, MAX);

	int s, e, t;
	dist[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < edges.size(); j++) {
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;
			if (dist[e] > dist[s] + t) {
				dist[e] = dist[s] + t;
			}
		}
	}
	for (int j = 0; j < edges.size(); j++) {
		s = edges[j].s;
		e = edges[j].e;
		t = edges[j].t;
		if (dist[e] > dist[s] + t) {
			return true;
		}
	}

	return false;
}

int main(void)
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ct;
	cin >> ct;

	int s, e, t;
	while (ct--) {
		cin >> n >> m >> w;

		vector<edge> edges;

		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}

		if (time_travel(n, edges)) cout << "YES\n";
		else cout << "NO\n";

		
	}

	return 0;
	
}
