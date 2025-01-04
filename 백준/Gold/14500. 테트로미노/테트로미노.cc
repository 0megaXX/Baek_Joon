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

int row,col;
int arr[500][500];
bool visit[500][500];

int dx[4] {1,-1,0,0};
int dy[4] {0,0,1,-1};

queue<pair<pair<int,int>,pair<int,int>>>q;
int rs = 0;
void bfs(int sx,int sy)
{
    q.push({{1,arr[sx][sy]},{sx,sy}});

    while(!q.empty())
        {
            int ct = q.front().first.first;
            int summ = q.front().first.second;
            int x= q.front().second.first;
            int y =q.front().second.second;
            visit[x][y]=true;
            q.pop();

            if(ct == 4)
            {
                rs = max(rs,summ);
                continue;
            }
            int nx,ny;
            for(int a=0;a<4;a++)
                {
                    nx = x+dx[a];
                    ny = y+dy[a];

                    if(nx>= 0 && nx<row && ny>= 0 && ny<col && !visit[nx][ny])
                    {
                        q.push({{ct+1, summ+arr[nx][ny]},{nx,ny}});
      
                    }
                }
            

            
        }



    
    // 'ㅗ' 모양을 처리하기 위한 코드 추가
    // 각 방향에서 특정 위치를 기준으로 추가 계산
    // 예를 들어, (sx, sy)를 기준으로 상, 하, 좌, 우에서 선택된 칸들을 활용.

    bool ready = true;
    int tmp = arr[sx][sy] ;
    for (int a = 0; a < 4; a++)
    {
             int nx = sx + dx[a];
             int ny = sy + dy[a];
        if(nx>= 0 && nx<row && ny>= 0 && ny<col )
                    {

                        tmp+=arr[nx][ny];
                    }
        else // 한칸이라도 벗어나면 십자는 안됨
            ready = false;
    }


    // + 십자 모양의 형태에서 상하좌우 한칸씩 빼서 비교
    if(ready) 
    {
        
        for (int a = 0; a < 4; a++)
        {
            int nx = sx + dx[a];
            int ny = sy + dy[a];
            int tmp2=tmp;

            tmp2-=arr[nx][ny];
            rs=max(rs,tmp2);
        }
    }


tmp = arr[sx][sy];  // 기준점 추가
int count = 0;  // 3개 칸을 더한 개수 체크

for (int a = 0; a < 4; a++) {
    int nx = sx + dx[a];
    int ny = sy + dy[a];

    // 유효한 범위 안에 있을 경우 칸을 더함
    if (nx >= 0 && nx < row && ny >= 0 && ny < col) {
        tmp += arr[nx][ny];  // 유효한 칸이면 합산
        count++;
    }
}

// 한 방향이 빠져도 3개 칸만 더할 경우 갱신
if (count == 3) {
    rs = max(rs, tmp);  // 3개의 칸만 더한 경우에 최대값 갱신
}



    
 // 네모 모양은 현재 위치에서 상하좌우로 2칸씩 탐색할 수 있는지 확인
   if (sx - 1 >= 0 && sy - 1 >= 0 && sx < row && sy < col)
    {
        int tmp2 = arr[sx][sy] + arr[sx - 1][sy] + arr[sx - 1][sy - 1 ] + arr[sx][sy - 1];
        rs = max(rs, tmp2);
    }
    
}



int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin>>row>>col;

    for (int a=0;a<row ;a++ ) 
        for (int b=0;b<col ;b++ )
                cin>>arr[a][b];

      for (int a=0;a<row ;a++ ) 
        for (int b=0;b<col ;b++ )
            {
                memset(visit,false,sizeof(visit));
               
                bfs(a,b);

                
            }
    
    cout<<rs;
	return 0;

}
