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

int n;
int arr[3][3];
bool visit[3][3];

void fn()
{
    
    queue<pair<int,int>>q;
    q.push({0,0});
    visit[0][0]=true;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;



       // cout<<"cur pos "<<x<<' '<<y<<" "<<arr[x][y]<<endl;
        if(x==n-1 && y==n-1)
        {
            cout<<"HaruHaru";
            return;
        }
        
        q.pop();
        int nx,ny;
        
        nx=x+arr[x][y];
        
        if(!(nx<0 || nx>=n) && !visit[nx][y])
        {
            visit[nx][y]=true;
            q.push({nx,y});
        }

        ny = y+arr[x][y];
        
        if(!(ny<0 || ny>=n) && !visit[x][ny])
        {   
            visit[x][ny] = true;
            q.push({x,ny});
       
        }
    }


    cout<<"Hing";
    
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for (int a=0;a<n ;a++ ) 
        for (int b=0;b<n ;b++ ) 
            cin>>arr[a][b];

    fn();
   
}