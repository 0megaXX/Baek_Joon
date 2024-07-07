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
vector<pair<int, int>>v[50001];
vector<int>cost(50001, MAXX);

void dik()
{

    priority_queue<int>pq;
    pq.push(1);
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        for (int a = 0; a < v[cur].size(); a++)
        {
            if (cost[v[cur][a].first] > cost[cur] + v[cur][a].second)
            {
                cost[v[cur][a].first] = cost[cur] + v[cur][a].second;
                pq.push(v[cur][a].first);
            }
        }



    }




}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cost[1] = 0;
    cin >> N >> M;
    for (int a = 0; a < M; a++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back({ end,cost });
        v[end].push_back({ start,cost });
    }
    dik();
  
    cout << cost[N];
    
}