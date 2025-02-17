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


vector<int> v[3001]; 
int V,E;
int start; // 시작할 노드

// DFS(노드,간선의 수)
bool dfs(int x, int ct)
{
    // 간선의 수가 E와 같아진다면 
    if(ct >= E) 
    {
        // 노드 벡터 안에 남아있는 것이 하나라도 있으면 false
        for(int a = 1; a <= V; a++)
            if(!v[a].empty()) 
                return false;
        
        return true;
    }
    bool ans = false;
    // 노드 x에 연결되어 있는 노드 호출
    for(int a = 0; a < v[x].size(); a++)
    {
        int next = v[x][a]; // 다음 노드
        v[x].erase(v[x].begin()+a); // 제거
        
       
        auto it = find(v[next].begin(),v[next].end(),x);
        v[next].erase(it);
        ans = ans | dfs(next,ct+1);
        a--; 
        
    }
    
    return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

     cin >> V >> E;
    for(int a = 0; a < E; a++)
    {
        int v1,v2;
        cin >> v1 >> v2;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }
    start = 1;
    int max_size = 0;

    // 노드 중 간선이 가장 많은 노드를 찾아 start에 저장
    for(int a = 1; a <= V; a++) 
    {
        int size = v[a].size();
        if(size > max_size)
        {
            max_size = size;
            start = a;
        }
    }
    
    bool ans = dfs(start,0);

    if(ans) 
        cout << "YES";
        
    else
        cout << "NO";
   
}

