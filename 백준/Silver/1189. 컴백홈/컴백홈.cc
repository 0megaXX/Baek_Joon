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

using namespace std;
#define MAXX 99999999

int r,c,k;
char arr[5][5];
bool visit[5][5];
int dx[4]{0,0,1,-1};
int dy[4]{1,-1,0,0};

int rs=0;


void back(int Move, int x,int y)
{
    
    if(Move==k) // 걸음이 목표수에 도달할 경우우
    {
        if(x==0 && y== c-1)
        { 
           
            rs++;
        }


        return;
    }
    
    int nx,ny;
    for(int a=0;a<4;a++)
    {
        nx=x+dx[a];
        ny=y+dy[a];
        
        if(nx>=0 && nx <r && ny>=0 && ny<c) // 맵 범위 내라면
        {
            if(arr[nx][ny]!='T' && !visit[nx][ny]) // 방문기록이 없다면
            {
                visit[nx][ny]=true;

                back(Move+1,nx,ny);

                visit[nx][ny]=false;
                
                
            }
            
        }
        
    }
    
    
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>r>>c>>k;
    
    for(int a=0;a<r;a++)
        for(int b=0;b<c;b++)
            cin>>arr[a][b];
    
    
    visit[r-1][0]=true;
    back(1,r-1,0);
    cout<<rs;

}