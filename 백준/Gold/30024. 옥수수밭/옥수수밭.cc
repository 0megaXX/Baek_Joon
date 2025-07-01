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


int arr[1001][1001];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool visit[1001][1001];
priority_queue<pair<int, pair<int, int>>> pq;
vector<pair<int, int> > rs;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, K;
    cin >> N >> M;
    for (int a = 0; a < N; a++) 
    {
        for (int b = 0; b < M; b++) 
        {
            cin >> arr[a][b];
            
            // 모서리면 삽입
            if ((a == 0) || (a == N - 1))  
            {
                pq.push(make_pair(arr[a][b], make_pair(a, b)));
                visit[a][b] = true;
            }
            else 
            {
                if ((b == 0) || (b == M - 1)) 
                {
                    pq.push(make_pair(arr[a][b], make_pair(a, b)));
                    visit[a][b] = true;
                }
            }

        }
    }
    
    cin >> K;

    while (K--)
    {
        if (pq.empty()) 
            break;
        
        auto cur = pq.top();
        pq.pop();
        
        for (int a = 0; a < 4; a++) 
        { 
            int nx = cur.second.second + dx[a];
            int ny = cur.second.first + dy[a];
            
            if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visit[ny][nx]) 
            {
                pq.push(make_pair(arr[ny][nx], make_pair(ny, nx))); // 우선순위큐에 다음 위치 삽입
                visit[ny][nx] = true;
            }
        }
        
        rs.push_back(make_pair(cur.second.first + 1, cur.second.second + 1)); // 순서 삽입
    };


    for (int a = 0; a < rs.size(); a++) // 순서대로 출력
        cout << rs[a].first << " " << rs[a].second << "\n";
    
    

    return 0;
}

