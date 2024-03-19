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
using namespace std;
const int INF = 987654321;

int value[1001];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> >pq;
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> >q;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int node, degree, center;
    cin >> node >> degree >> center;
    vector<vector<pair<int, int>>>v(node+1);
    vector<vector<int>>v2(node + 1,vector<int>(node+1, INF));
    for (int a = 0; a < degree; a++)
    {
        int start, end, km;
        cin >> start >> end >> km;
        v[start].push_back(make_pair(end, km));
    }
    fill(value, value + node + 1, INF);

    for (int b = 1; b <= node; b++)
    {
        v2[b][b] = 0;
       
        q.push({ 0,b });
        while (!q.empty())
        {
            int cost = q.top().first;
            int start_node = q.top().second;
            q.pop();

            for (int a = 0; a < v[start_node].size(); a++)
            {
                int new_start_node = v[start_node][a].first;
                int new_cost = v[start_node][a].second + cost;

             
                    if (v2[b][new_start_node] == INF)
                    {
                        v2[b][new_start_node] = new_cost;
                        q.push(make_pair(new_cost, new_start_node));
                    }

                    else if (v2[b][new_start_node] > new_cost)
                    {
                        v2[b][new_start_node] = new_cost;
                        q.push(make_pair(new_cost, new_start_node));
                    }
            
            }
        }
 

    }


    pq.push(make_pair(0, center));
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int start_node = pq.top().second;
        pq.pop();

        
        for (int a = 0; a < v[start_node].size(); a++)
        {
            int new_start_node = v[start_node][a].first;
            int new_cost = v[start_node][a].second + cost;

            if (value[new_start_node] == INF)
            {
                value[new_start_node] = new_cost;
                pq.push(make_pair(new_cost, new_start_node));
            }

              else if (value[new_start_node] > new_cost)
            {
                value[new_start_node] = new_cost;
                pq.push(make_pair(new_cost, new_start_node));
            }

        }
    }

    int maxx = 0;
    for (int a = 1; a <= node; a++)
    {
        maxx = max(maxx, value[a] + v2[a][center]);


    }
    cout << maxx;

}