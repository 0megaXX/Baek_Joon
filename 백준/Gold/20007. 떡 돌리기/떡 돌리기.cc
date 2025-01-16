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

int n, m, x,  y;

int d[1001];
vector<pair<int,int>> g[1001]; // { 거리, 이동도시 }


int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
     cin >> n >> m >> x >> y;
    for(int a=0;a<m;a++)
    {
        int b, c, d;
        cin >> b >> c >> d;
        g[c].push_back({d,b});
        g[b].push_back({d,c});
    }

    fill(d, d + n + 1, MAXX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // 오름차순 우선순위 큐
    
   
    d[y] = 0; // 시작위치의 누적거리는 0
    pq.push({d[y], y}); // 현 위치까지의 누적거리, 현 위치
    while(!pq.empty())
    {
        pair<int,int> cur = pq.top();
        pq.pop();
        
        if(d[cur.second] != cur.first) 
            continue;
        
        for(auto next : g[cur.second]) // 연결된 간선 탐색
        {
            if(d[next.second] <= d[cur.second] + next.first) // 최소 누적체력을 갱신하지 못한다면
                continue;
            
            d[next.second] = d[cur.second] + next.first; // 최소 누적체력 갱신
            
            pq.push({d[next.second], next.second}); // 갱신된 체력으로 최단거리 탐색
        }
    }

    vector<int> dist;
    for(int a = 0;a<n;a++)
    {
        if(a == y) // 시작 위치면 continue
            continue;
        
        if(d[a] == MAXX || 2 * d[a] > x) // a까지 갈 수 없거나 a로 왔다 가는게(왕복이) 불가능하다면
        {
            cout << -1;
            return 0;
        }
        
        dist.push_back(d[a]);
    }
    
    sort(dist.begin(), dist.end()); // 가까운 거리부터 방문
    int hp = x;
    int day = 1;
    for(auto e : dist)
    {
        if(hp - 2 * e >= 0) // 현재 체력에서 왕복이 가능하다면
            hp -= 2 * e;
            
        else // 불가능 하다면 하루 소모
        {
            hp = x;
            hp -= 2 * e;
            day++;
        }
    }

    cout << day ;
    return 0;

}
