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
#define MAXX 987654321
using namespace std;

int A, B,N,M;

int visit[100001]{0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   
    cin >> A >> B >> N >> M;

    vector<int>v;
    v.push_back(1);
    v.push_back(A);
    v.push_back(B);

    queue<int>q;
    q.push(N);
    int move = 0;
    while (!q.empty())
    {
        int sizz = q.size();
        
        for (int a = 0; a < sizz; a++)
        {
            int cur = q.front();
            
            q.pop();

            if (cur == M)
            {
               
                cout << move;
                return 0;
            }


            for (int a = 0; a < 3; a++)
            {
                int next_R = cur + v[a];
                if (next_R <= M && !visit[next_R]) // 우쪽 이동이 최대거리보다 같거나 작고 간적이 없다면
                {
                    visit[next_R] = move;
                    q.push(next_R);
                }
             
                int next_L = cur + (- v[a]);
                if (next_L >=0 && !visit[next_L]) // 좌쪽 이동이 0보다 같거나 작고 간적이 없다면
                {
                    visit[next_L] = move;
                    q.push(next_L);
                }
            }

            if (cur*A <= M && !visit[cur * A]) // 현재 위치에서 A배 힘을 모으는 경우
            {
                visit[cur * A] = move;
                q.push(cur * A);
            }

            if (cur * B <= M && !visit[cur * B]) // 현재 위치에서 B배 힘을 모으는 경우
            {
                visit[cur * B] = move;
                q.push(cur * B);
            }




        }
        move++;
    }
    
}