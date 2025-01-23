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
#define MAXX 2147483647


vector<int> v;


int dx[9]{1,-1,0,0,-1,-1,1,1,0};
int dy[9]{0,0,1,-1,-1,1,-1,1,0};
bool visit[10][9][9]; // [wave][x][y]
char arr[8][8];

void wave() // 한줄씩 밑으로 이동하는 로직
{

    for(int a=7;a>=0;a--)
        for (int b=0;b<8 ;b++ )
            arr[a][b]=arr[a-1][b];

    
    for (int b=0;b<8 ;b++ )
        arr[0][b]='.';

    
}


bool fn()
{
    pair<int,int>start_pos ={7,0};

    queue<pair<int,int>>q;
    q.push(start_pos);
    int wave_ct = 0;

    while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
                {
                    int x= q.front().first;
                    int y =q.front().second;
                    q.pop();

                    if(arr[x][y]=='#') // 눌렸다면 끝
                        continue;

                    int nx,ny;
                    for (int a=0;a<9 ;a++ )
                    {
                        nx=x+dx[a];
                        ny=y+dy[a];
                        if(nx>=0 && ny>=0 && nx<8 && ny<8 && arr[nx][ny]!='#'&& !visit[wave_ct][nx][ny])
                        {
                            //cout<<wave_ct<<"일때 "<<nx<<" "<<ny<<"로 이동!\n";
                            visit[wave_ct][nx][ny]=true;
                            q.push({nx,ny});
                            
                        }
                    }
    
                }
            
            wave_ct++;
            if(wave_ct==9) // 모든 웨이브를 통과했다는 것은 더 이상 벽은 없음
                return true;
            wave();
        }

    return false;
    
}




int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
     for(int a=0;a<8;a++)
        for (int b=0;b<8 ;b++ )
            cin>>arr[a][b];

    if(fn())
        cout<<1;
    else
        cout<<0;
	return 0;

}