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
#include <tuple>

using namespace std;
#define MAXX 2147483647

int v, e, p;
vector<vector<pair<int,int>>> g;

int dik(int start, int eend) 
{
	vector<int> dist(v + 1,MAXX);
	vector<bool> visit(v + 1, false);
    
	priority_queue<pair<int,int>> pq; // 거리, 위치

	pq.push({0, start});
	dist[start] = 0;

	while (!pq.empty()) 
    {
		int cur = pq.top().second; pq.pop(); // 위치
		if (visit[cur])
            continue;

		visit[cur] = true;
		for (auto x : g[cur]) 
		if(!visit[x.second] && (dist[x.second] > dist[cur] + x.first))
        {
			dist[x.second] = dist[cur] + x.first;
			pq.push(make_pair(-dist[x.second], x.second));
		}
	}

	return dist[eend];
}

int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin >> v >> e >> p;
	g = vector<vector<pair<int,int>>>(v + 1);

	for (int i = 0; i < e; i++) 
    {
        int u,v,w;
		cin>>u>>v>>w;
        // 양방향 간선 
		g[u].push_back(make_pair(w, v));
		g[v].push_back(make_pair(w, u));
	}
    
	if ((dik(1, p) + dik(p, v)) <= dik(1, v)) // 도중에 들렸다 가는게 바로 가는거보다 같거나 짧다면
        cout<<"SAVE HIM";
	else
        cout<<"GOOD BYE";
   
    

    return 0;
}