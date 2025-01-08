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
int Map[51][51];
pair<int,int>start_pos;
int dx[4]{-1,0,1,0};
int dy[4]{0,1,0,-1};

int fn(int sx, int sy, int look) {
    int cleaned = 0;
    int tmp =2;

    while (true) 
    {
        
        if (Map[sx][sy] == 0) // 현재 청소가 안되어있다면
        {
            Map[sx][sy] = tmp++;
            cleaned++;
        }

        bool moved = false;
        // 반시계 방향으로 90도 회전하며 탐색
        for (int a = 0; a < 4; a++)
      {
            int next_look = (look + 3 -a) % 4;
            int nx = sx + dx[next_look];
            int ny = sy + dy[next_look];

            if (nx >= 0 && nx < row && ny >= 0 && ny < col && Map[nx][ny] == 0) 
            {
                // 이동할 수 있으면
                sx = nx;
                sy = ny;
                look = next_look;
                moved = true;
                break;
            }
        }

        if (!moved)// 후진
        {        
            int next_look = (look + 2) % 4;
            int nx = sx + dx[next_look];
            int ny = sy + dy[next_look];

            if (nx < 0 || nx >= row || ny < 0 || ny >= col || Map[nx][ny] == 1) // 후진할 수 없으면 종료  
                break;
            else 
            {
                sx = nx;
                sy = ny;
            }
        }
    }
    return cleaned;
}

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin>>row>>col;
    int sx,sy,look;
    cin>>sx>>sy>>look;
    start_pos={sx,sy};
    
    
    for(int a=0;a<row;a++)
        for (int b=0;b<col ;b++ ) 
            cin>>Map[a][b];
        

    cout<<fn(sx,sy,look);


   /* cout<<endl<<endl;
    
     for(int a=0;a<row;a++)
         {  
             for (int b=0;b<col ;b++ ) 
                cout<<Map[a][b]<<' ';
          cout<<endl;
        }*/
	return 0;

}
