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


int n;


bool compare(pair<int,int>a,pair<int,int>b)
{
    if(a.first!=b.first)
        return a.first > b.first;
    else
        return a.second < b.second;

    
}

// 우선순위 1. 끝나는 시간이 늦은거부터, 2. 걸리는 시간이 짧은거부터 ㅇ

int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<pair<int,int>>v;

   cin>>n;
    for (int a=0; a<n; a++)
        {
            int spend,eend;
            cin>>spend>>eend;
            v.push_back({eend,spend});
        }

    sort(v.begin(),v.end(),compare);


    int cur_time = v[0].first - v[0].second; // 모든 작업이 마쳐지는 시간

     if( cur_time < 0) // 성립이 안된다면 
               { 
                   cout<<-1;           
                   return 0;
                }
    
    for (int a=1; a<n; a++)
        {
            //cout<<cur_time<<endl;
            if(cur_time > v[a].first - v[a].second) // v[a].first - v[a].second 는 다음 작업시작의 최대 시간ㄱ
            { 
                
                cur_time= min(cur_time - v[a].second , v[a].first - v[a].second); // 최대한 늦게
              
            }
                
            else // 여유롭게 못한다면 최대한 빠르게 준비
            
               cur_time -=v[a].second;
                
               if( cur_time < 0) // 성립이 안된다면 
               { 
                   cout<<-1;           
                   return 0;
                }
            

            
        }
    cout<<cur_time;
	return 0;

}
