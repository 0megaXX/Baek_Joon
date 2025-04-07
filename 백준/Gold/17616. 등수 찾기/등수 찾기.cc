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

int n,m,x;

vector< vector<int> >best(100001);
vector< vector<int> >worst(100001);
bool visited[100001];

int cnt = -1, reverse_cnt = -1;

void dfs(int cur)
{
    if (visited[cur])
        return;
 
    visited[cur] = true;
    cnt++;
 
    for (int next : best[cur])
        dfs(next);
}
 
void reverse_dfs(int cur)
{
    if (visited[cur])
        return;
 
    visited[cur] = true;
    reverse_cnt++;
 
    for (int next : worst[cur])
        reverse_dfs(next);
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>n>>m>>x;
 

    for (int a=0;a<m ;a++ )
    {
         int u,v;
         cin>>u>>v;
         best[u].push_back(v);
         worst[v].push_back(u);
    }

    dfs(x);
 
    memset(visited, false, sizeof(visited));
    reverse_dfs(x);
 
    cout << reverse_cnt + 1 << ' ' << n - cnt;
    
    return 0;
}

