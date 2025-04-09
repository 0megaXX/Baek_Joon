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

int row,col;
int before[30][30];
int after[30][30];
int dx[4]{1,-1,0,0};
int dy[4]{0,0,1,-1};


bool prove()
{
     for (int a=0;a<row ;a++ ) 
        for(int b=0;b<col;b++)
             if(before[a][b] != after[a][b])
                 return false;
        
    return true;
}


void bfs(int sx, int sy, int ori)
{
    queue<pair<int,int>>q;
    q.push({sx,sy});
    int virus = after[sx][sy];
    before[sx][sy]=virus;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();
        int nx,ny;
        for (int a=0;a<4 ;a++ )
        {
            nx=x+dx[a];
            ny=y+dy[a];
            if(nx>=0 && nx<row && ny>=0 && ny<col && before[nx][ny]==ori)
            {
                before[nx][ny] = virus;
                q.push({nx,ny});
            }
        }

    }


    
}




int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin>>row>>col;

    for (int a=0;a<row ;a++ ) 
        for(int b=0;b<col;b++)
            cin>>before[a][b];


     for (int a=0;a<row ;a++ ) 
        for(int b=0;b<col;b++)
            cin>>after[a][b];

    

   for (int a=0;a<row ;a++ ) 
        for(int b=0;b<col;b++)
             if(before[a][b] != after[a][b])
             {
              
                 bfs(a,b, before[a][b]);
                 
                  if(prove())
                    cout<<"YES";
                   else
                    cout<<"NO";
                 return 0;
             }

 cout<<"YES";
    
    return 0;
}

