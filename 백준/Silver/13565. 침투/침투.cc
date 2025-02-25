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


char arr[1001][1001];
bool visit[1001][1001]{false};
int dx[4]{1,-1,0,0};
int dy[4]{0,0,-1,1};

int row,col;


bool bfs(int sx,int sy)
{

    priority_queue<pair<int,int>>pq;
    pq.push({sx,sy});

    while(!pq.empty())
    {
        int x= pq.top().first;
        int y= pq.top().second;
        pq.pop();

        if(x==row-1)
            return true;
        int nx,ny;
        for (int a=0;a<4 ;a++ )
        {
            nx=x+dx[a];
            ny=y+dy[a];

            if(nx>=0 && nx<row && ny>=0 && ny<col &&!visit[nx][ny] && arr[nx][ny]=='0')
            {
                visit[nx][ny]=true;
                pq.push({nx,ny});
            }
        }
    }

    return false;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>row>>col;

    for (int a=0;a<row ;a++ ) 
    {
        string s;
        cin>>s;
        for (int b=0;b<col ;b++ )
            arr[a][b]=s[b];
    }

    for (int a=0;a<col ;a++ )
    {
        if(!visit[0][a] && arr[0][a]=='0')
        {
            visit[0][a]=true;
            if(bfs(0,a))
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    
    cout<<"NO";
    return 0;
   
}


