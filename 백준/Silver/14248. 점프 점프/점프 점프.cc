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
#include <regex>

using namespace std;
#define MAXX 2147483647

vector<int>v;
vector<bool>visit;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    v.resize(n);
    visit.resize(n);
    
    for (int a=0;a<n ;a++ )
        cin>>v[a];        
    


    int start;
    cin>>start;

    queue<int>q;
    q.push(start-1);
    visit[start-1]=1;
    int ct = 1; // 현재 위치는 방문처리

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        //cout<<"현재 위치 "<<cur<<'\n';
        int r = cur+v[cur] ;
        //cout<<"우쪽 "<<r<<endl;
        if(r < n && !visit[r]) // 오른쪽으로 간 적이 없다면
        {
            visit[r]=1;
            ct++;
            q.push(r);
            //cout<<"이동 "<<r<<endl;
        }

        int l = cur-v[cur] ;
        //cout<<"좌쪽 "<<l<<endl;
        if(l >=0  && !visit[l]) // 왼쪽으로 간 적이 없다면
        {
            visit[l]=1;
            ct++;
            q.push(l);
            //cout<<"이동 "<<l<<endl;
        }

            
    }

    cout<<ct;

    return 0;
}

