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
#define MAXX 987654321
using namespace std;





set<string>Set;
char arr[5][5];
int dx[4]{ 0,0,1,-1 };
int dy[4]{ 1,-1,0,0 };
pair<int, pair<int, int>>Start;
int ans = 0;



int BFS(int X, int Y, int COUNT,string cur)
{

    queue<pair<pair<int, string>, pair<int, int>>>q;
    q.push({ { COUNT,cur},{X,Y}});
    while (!q.empty())
    {
        int ct= q.front().first.first;
        string cur_S = q.front().first.second;
        int x = q.front().second.first;
        int y = q.front().second.second;
         q.pop();
        if (ct == 6)
        {
            if (Set.find(cur_S) == Set.end())
            {
               // cout << "삽입!\n";
            //    cout << cur_S << endl;
                Set.insert(cur_S);
                ans++;
               
            }
            continue;
        }
        
       
        int nx, ny;
        for (int a = 0; a < 4; a++)
        {
            nx = x + dx[a];
            ny = y + dy[a];

            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5)
                q.push({ {ct+1,cur_S+arr[nx][ny]},{nx,ny}});
            

        }

        
    }

    return 0;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    for (int a = 0; a < 5; a++)
        for (int b = 0; b < 5; b++)
        {
            
            cin>>arr[a][b];
        }


    for (int a = 0; a < 5; a++)
        for (int b = 0; b < 5; b++)
        {
           
            string s = "";
            s+=arr[a][b];
        // cout << "삽입 " <<s << endl;
            BFS(a, b, 1,s);
        }

    cout << ans;
   
}