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

int n, q;
vector<pair<int, int>> v[5001];  // 각 노드의 연결된 간선 (목표 노드, USADO)

bool visit[5001];  // 각 노드의 방문 여부


int fn(int node, int USADO)
{
    int ct = 0;
    queue<pair<int, int>> q;  // {현재 노드, 경로 상 최소 USADO}
    q.push({node, MAXX});

    while (!q.empty()) {
        int cur = q.front().first;
        int val = q.front().second;
        q.pop();

        if (visit[cur]) 
            continue;
        
        visit[cur] = true;

        // 현재 노드에서 연결된 노드들 탐색
        for (auto& next : v[cur]) {
            int nextNode = next.first;
            int weight = next.second;

            // 경로 상 최소 USADO 값을 계산
            int new_usado = min(weight, val);
            
            // 최소 USADO 값이 쿼리에서 요구하는 값보다 크거나 같으면 추천
            if (new_usado >= USADO && !visit[nextNode]) {
                ct++;  // 추천 동영상 수 증가
                q.push({nextNode, new_usado});
            }
        }
    }

    return ct;
}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	


    cin>>n>>q;
    for (int a=0;a<n-1 ;a++ )
        {
            int b,c,USADO;
            cin>>b>>c>>USADO;
            v[b].push_back({c, USADO});
            v[c].push_back({b, USADO});
            
        }

    while(q--)
        {
            memset(visit,false,sizeof(visit));
            int USADO , node;
            cin>>USADO>>node;

               cout<< fn( node, USADO)<<'\n';

        }
    
	return 0;

}
