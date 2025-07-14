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
#include <regex>

using namespace std;
#define MAXX 2147483647

vector<int>parent, dist;

int find_parent(int x)
{
  if (parent[x] != x) // 루트 노드가 아니면 재귀 & 부모(루트) 노드 저장
  {
    int node = find_parent(parent[x]);
    dist[x] += dist[parent[x]];  // 거리 누적
    parent[x] = node;
  }
  return parent[x]; // 루트 노드면 자기 자신 return
}

void union_parent(int x, int y) 
{
  dist[x] = abs(x - y) % 1000; // 거리 저장
  parent[x] = y;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) 
    {
        int N;
        cin >> N;
            
        parent.resize(N + 1);
        for(int a=0;a<parent.size();a++)
            parent[a]=a;
        
        dist.resize(N + 1);
        
        fill(dist.begin(), dist.end(), 0);
        
        while (1) 
        {
          char c;
          cin >> c;
            
          if (c == 'E')
          { 
            int a;
            cin >> a;
            find_parent(a); // a로부터 루트까지의 거리 출력
            cout << dist[a] << '\n';
          } 
          else if (c == 'I')// E가 아니면 I임
          { 
            int a, b;
            cin >> a >> b;
            union_parent(a, b);
          } 
          else  // O 쿼리(종료)
           break;
      
  
        }
  }

    return 0;
}

