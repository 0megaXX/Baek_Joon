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

#define MAXX 987654321
#define RED 1
#define BLUE 2
using namespace std;

int v, e;

vector<int>graph[20001];
int visit[20001];

void DFS(int cur)
{

    // 처음 방문하는 노드면 빨간색으로 칠
    if (!visit[cur])
        visit[cur] = RED;

    // 연결된 정점들을 모두 방문
    for (int a = 0; a < graph[cur].size(); a++) {
        int next = graph[cur][a];

        // 아직 방문하지 않은 정점이라면 현재 정점과 반대되는 색으로 칠한다.
        if (!visit[next])
        {
            if (visit[cur] == RED)
                visit[next] = BLUE;

            else if (visit[cur] == BLUE)
                visit[next] = RED;
            DFS(next);
        }
    }
}



bool isTrue()
{
    // 정점들을 돌아보면서 인접한 정점과의 색이 같다면 이분 그래프 X
    for (int cur = 1; cur <= v; cur++) 
        for (int a = 0; a < graph[cur].size(); a++) 
        {
            int next = graph[cur][a];
          
            if (visit[cur] == visit[next])   // 만일 인접한 정점과 색이 같다면 이분 그래프가 아님
                return false;
        }
    
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int cass;
    cin >> cass;
    while (cass--)
    {
        for(int a=0;a<20001;a++)
         graph[a].clear();
        memset(visit, 0, sizeof(visit));
        cin >> v >> e;

        for (int a = 0; a < e; a++)
        {
            int b, c;
            cin >> b >> c;
            graph[b].push_back(c);
            graph[c].push_back(b);
        }

        for (int a = 1; a <= v; a++) 
            if (!visit[a]) 
                DFS(a);
        
        if (isTrue())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}
