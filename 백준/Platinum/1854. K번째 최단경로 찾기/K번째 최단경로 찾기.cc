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


vector<vector<pair<int,int>>>v;
int len[5001]; // 위치까지의 최소 거리

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K; // 정점, 간선, K번째
    cin >> V >> E >> K;

    v.resize(V + 1); 

    for (int a = 1; a <= V; a++) 
        len[a] = MAXX;
    

   
    for(int a=0;a<E;a++) 
    {
        int U, V, W;
        cin >> U >> V >> W;
        v[U].push_back({V, W});
    }

    priority_queue<int> h[1001]; // K개의 수를 저장할 최대힙 배열
    priority_queue<pair<int, int>> pq; // 다익스트라용 우선순위 큐

    h[1].push(0); // 1번에서 출발
    pq.push({0, 1});

    while (!pq.empty()) 
    {
        int cost = -(pq.top().first); // 현재 비용
        int cur = pq.top().second; // 현재 위치
        pq.pop();

        // 현재 정점에서 연결된 모든 정점 탐색
        for (pair<int, int> p : v[cur]) 
        {
            int next = p.first;
            int d = cost + p.second;

            // K개 이하라면 그냥 추가
            if (h[next].size() < K) 
            {
                h[next].push(d);
                pq.push({-d, next});
            }
            // K개를 초과하면 top 원소보다 작은 경우만 추가
            else if (h[next].top() > d)
            {
                h[next].pop();
                h[next].push(d);
                pq.push({-d, next});
            }
        }
    }

    // 각 정점에 대해 K번째로 작은 비용을 출력
    for (int a = 1; a <= V; a++) 
    {
        if(h[a].size() < K)
            cout<<-1<<'\n';
        else
            cout<<h[a].top() << '\n';

    }

    return 0;
}
