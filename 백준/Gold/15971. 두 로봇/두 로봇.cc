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
#include <unordered_map>


using namespace std;

vector<vector<pair<int,int>>>v(100001);
bool visit[100001];
int n,start,eend;

int fn(int start)
{
    priority_queue<pair<int,pair<int,int>>>pq; // 누적거리, 제일 길었던 거리, 현재 방번호 
    pq.push({0,{0,start}});

    visit[start] = true;
    while(!pq.empty())
    {
        
        int total_dist = pq.top().first;
        int longest_dist  = pq.top().second.first;
        int cur = pq.top().second.second;

        if(cur == eend)
            return total_dist - longest_dist;
        pq.pop();

        for(int a=0; a<v[cur].size();a++)
        {
            int next = v[cur][a].first;
            int next_len = v[cur][a].second;

            if(!visit[next]) // 방문한 적이 없다면
            {
                visit[next]=true;
                int tmp_longest_dist = max(longest_dist, next_len);
                pq.push({total_dist+next_len, {tmp_longest_dist,next}});           
                //cout<<cur<<"에서 "<<next<<" 로 이동!"<<"총 거리는"<< total_dist+next_len<< "\n";
            }
        }


    }
    return -1;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>n>>start>>eend;

    for (int a=0;a<n-1 ;a++ )
    {
        int s,e,len;
        cin>>s>>e>>len;
        v[s].push_back({e,len});
        v[e].push_back({s,len});
    }

    
	cout<<fn(start);
    


    return 0;
}