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

map<long long,long long>m;

int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    long long x;
    cin>>x;
    m[x]=0;

    priority_queue<pair<long long, long long> , vector<pair<long long, long long>>, greater<>>q; // 연산횟수, 현재 값
    q.push({0,x});
    while(!q.empty())
    {
        long long cur = q.top().second;
        long long ct = q.top().first;
        q.pop();
        long long cur_ct = ct+1;

        if(cur == 1) // 1이 되었다면 
        {
            cout<<ct;   
            return 0;
        }

        if(cur%3 == 0 && (!m.count(cur/3) || m[cur/3] > cur_ct)) // 한번도 나온적이 없는 값이거나 최소비용으로 갱신이 가능하다면
        {
            m[cur/3] = cur_ct;
            q.push({cur_ct,cur/3});
        }

         if(cur%2 == 0 && (!m.count(cur/2) || m[cur/2] > cur_ct)) // 한번도 나온적이 없는 값이거나 최소비용으로 갱신이 가능하다면
        {
            m[cur/2] = cur_ct;
            q.push({cur_ct,cur/2});
        }
        
         if(cur-1 > 0 && (!m.count(cur-1) || m[cur-1] > cur_ct)) // 한번도 나온적이 없는 값이거나 최소비용으로 갱신이 가능하다면
        {
            m[cur-1] = cur_ct;
            q.push({cur_ct,cur-1});
        }
    }
 

    return 0;
}