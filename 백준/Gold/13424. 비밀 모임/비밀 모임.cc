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

int t;
int maxnum = 10000;
typedef pair<int, int> q;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<q> v[101];
        vector<int>ans(101);
        
        for(int a=0 ; a<101 ; a++) 
            ans[a] = 0;
        
        for(int a=0 ; a<m ; a++)
        {
            int b, c, d;
            cin >> b >> c >> d;
            v[b].push_back(q(c, d));
            v[c].push_back(q(b, d));
        }
        
        int k;
        cin >> k;
        for(int a=0 ; a<k ; a++) 
        {
            int s;
            cin >> s;
            int dist[101];
            for(int b=0 ; b<101 ; b++) 
                dist[b] = maxnum;

            priority_queue<q, vector<q>, greater<q>> pq;
            pq.push(q(0, s));
            dist[s] = 0;
            
            while(!pq.empty()) 
            {
                int cur = pq.top().second;
                pq.pop();

                for(int k=0 ; k<v[cur].size() ; k++) 
                {
                    int next = v[cur][k].first;
                    
                    if(dist[next] > dist[cur] + v[cur][k].second)
                    {
                        dist[next] = dist[cur] + v[cur][k].second;
                        pq.push(q(dist[next], next));
                    }
                }
            }
            
            for(int b=1 ; b<=n ; b++) 
                ans[b] += dist[b];
            
        }

        int rs = -1;
        int num;
        for(int a=1 ; a<=n ; a++) 
            if(rs == -1 || ans[a] < rs) // 갱신
            {
                rs = ans[a];
                num = a;
            }
        

        cout << num << "\n";
    }
    
    return 0;
}

