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

int N, M;
int S, D; // Start, Destination

vector<pair<int, int>>road[501];
vector<int>things[501]; // things[@]는 @까지의 최단 거리의 선행 노드들의 집합
int dist[501];
int check[501];


void all_clear()
{
    for (int a = 0; a < 501; a++)
        road[a].clear();
    memset(check, 0, sizeof(check));
    for (int a = 0; a < 501; a++)
        dist[a] = MAXX;
    for (int i = 0; i < 501; ++i) 
        things[i].clear( );
}


void dik(int start) // 다익스트라
{

    priority_queue<pair<int, int>>pq;
    pq.push({ -0,start });
    dist[start] = 0;
    while (!pq.empty())
    {
        
        int cur = pq.top().second;
        int cost = - pq.top().first;
        pq.pop();

        if (dist[cur] < cost)
            continue;


        int next,next_cost;

        for (int a = 0; a < road[cur].size(); a++)
        {
           
            if (road[cur][a].second == -1) //최단거리라 제거되었다면
                continue;

            next = road[cur][a].first;
            next_cost = road[cur][a].second + cost;
         

            if (dist[next] > next_cost) // 다음 위치까지의 최단거리가 갱신된다면
            {
              
                dist[next] = next_cost;
                pq.push({ - next_cost, next });            
                things[next].clear();
                things[next].push_back(cur);
        
            }

            else if (dist[next] == next_cost) // 갱신되지는 않지만 최단거리와 동일한 길이라면
                things[next].push_back(cur);
            
        }
    }


}


void BFS(int end)
{
    queue<int>q;
    q.push(end);
    while (!q.empty())
    {

        int cur = q.front();
        q.pop();
        if (check[cur] != 0)
            continue;

        check[cur] = 1; // 여긴 들림
        
        for (int a = 0; a < things[cur].size(); a++)
        {
            int next = things[cur][a]; // 현재 위치로 오는 최단노드의 선행 맴버
            
            for (int b = 0; b < road[next].size(); b++)
                if (road[next][b].first == cur)//현재 위치와 연결된 간선이라면
                    road[next][b].second = -1;
            
            q.push(next);
        }


    }

}


void fn()
{
  

    dik(S); //최단거리 탐색
    BFS(D); // 최단거리 삭제

    for (int a = 0; a < 501; a++)
        dist[a] = MAXX;

    dik(S); //최단거리 탐색

    if (dist[D] == MAXX)
        cout << "-1\n";
    else
        cout << dist[D] << '\n';


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    while (!(N==0 && M==0))
    {
        all_clear();
        cin >> S >> D;

        for (int a = 0; a < M; a++)
        {
            int start, end, cost;
            cin >> start >> end >> cost;
            road[start].push_back({ end,cost });
        }

        fn();
        cin >> N >> M;
    }


}