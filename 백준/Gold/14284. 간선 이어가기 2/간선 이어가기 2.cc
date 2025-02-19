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


    
    int n,m;
    cin>>n>>m;
    v.resize(n+1);
    for (int a=0;a<n+1 ; a++) 
        len[a]=MAXX;
    
    for (int a=0;a<m ;a++ )
    {
        int b,c,d;
        cin>>b>>c>>d;
        v[b].push_back({c,d});
        v[c].push_back({b,d});
    }


    priority_queue<pair<int,int>>pq; // 누적거리, 현재 도시
    int start,end;
    cin>>start>>end;
    pq.push({0,start});

    while(!pq.empty())
    {
        int cur_cost = -(pq.top().first);
        int cur = pq.top().second;

        if(cur == end)
        {
            cout<<cur_cost;
            return 0;
        }
        pq.pop();

        for (int a=0;a<v[cur].size() ;a++ )
        {
            int next = v[cur][a].first;
            int cost = v[cur][a].second;

            if(cur_cost+cost < len[next])
            {
                len[next]=cur_cost+cost;
                pq.push({-(cur_cost+cost), next});
            }
        }
        

            
    }

    
   
}

