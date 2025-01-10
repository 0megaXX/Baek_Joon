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


long long s,t;

map<long long,bool>m;

string fn()
{
    queue<pair<long long,string>>q;
    q.push({s,""});

    while(!q.empty())
        {
            long long cur= q.front().first;
            string commend = q.front().second;
            q.pop();
            if(cur == t)
            {
                return commend;
            }
            
            if(m.find(cur*cur)==m.end()) // 현재 값이 처음 등장인 경우
            {
                m[cur*cur]=true;
                q.push({cur*cur , commend+"*"});
            }
            if(m.find(cur+cur)==m.end()) // 현재 값이 처음 등장인 경우
            {
                m[cur+cur]=true;
                q.push({cur+cur , commend+"+"});
            }
            if(m.find(cur-cur)==m.end()) // 현재 값이 처음 등장인 경우
            {
                m[cur-cur]=true;
                q.push({cur-cur , commend+"-"});
            }
            if(cur!=0 && m.find(cur/cur)==m.end()) // 현재 값이 처음 등장인 경우
            {
                m[cur/cur]=true;
                q.push({cur/cur , commend+"/"});
            }

            
        }

    return "-1";
}
int main(void)
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin>>s>>t;

    if(s==t)
        cout<<0;
    else
        cout<<fn();
	return 0;

}
