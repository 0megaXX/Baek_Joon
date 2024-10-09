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

#define MAXX 987654321
using namespace std;

vector<pair<int, int>>v[201];

int Costs[201][201];
int Parent[201][201];

void dik(int start)
{


    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>pq;
    // { 누적거리 , { 현재위치 , 시작위치 }}


    pq.push({ 0,{start,0} }); // 누적거리 0, 시작도시 start, 최초 시작도시는 없음
    while (!pq.empty())
    {

        int cur = pq.top().second.first; // 현재 위치
        int cur_parent = pq.top().second.second; // 현재 위치에 오기 위한 최초 집하장
        int cur_cost = pq.top().first; // start에서 현 위치까지의 누적거리
        pq.pop();

        int next, next_cost;
        for (int a = 0; a < v[cur].size(); a++)
        {
            next = v[cur][a].second; // 다음도시
            next_cost = v[cur][a].first + cur_cost; // 현재 도시에서 다음도시까지의 거리

            if (Costs[start][next] > next_cost) // 최단거리 갱신이 가능하다면
            {

                if (cur_parent == 0) 
                    // 시작위치로부터 현재거리의 집하장이 없다면 다음 위치가 집하장임
                {
                    Parent[start][next] = next; 
                    Costs[start][next] = next_cost;
                    pq.push({ next_cost,{next,next} });
                }
                else // 집하장이 이미 있다면 그 집하장을 따라감.
                {
                    Parent[start][next] = cur_parent;
                    Costs[start][next] = next_cost;
                    pq.push({ next_cost,{next, cur_parent} });
                }
            }


        }


    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, m;
    cin >> n >> m;

    for (int a = 1; a <= n; a++)
        for (int b = 1; b <= n; b++)
        {
            if (a != b)
                Costs[a][b] = MAXX;
        }

    for (int a = 0; a < m; a++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back({ cost,end });
        v[end].push_back({ cost,start });
    }

    for (int a = 1; a <= n; a++)
        dik(a);


    for (int a = 1; a <= n; a++)
    {
       for( int b = 1; b <= n; b++)
        {
           if (Parent[a][b] == 0)
               cout << "- ";
            else 
               cout << Parent[a][b] << ' ';
        }
        cout <<'\n';
    }

   
    return 0;
}