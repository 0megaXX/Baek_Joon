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
vector<long long> rs;

void DFS(long long idx, int cnt) // idx = 벡터에 들어가는 값, cnt = 벡터에 들어간 인자의 수
{
    if(cnt>10) // 최대 내려가는 값은 9876543210 이기에 10개를 넘게 들어갈 수는  없음
        return;
    
    rs.push_back(idx);
    
    for(int a=0; a<10; a++)
        if(idx%10>a)
            DFS(idx*10+a, cnt+1);
        
    
    return;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    
   for(int a=0; a<10; a++)
        DFS(a, 1);
    
    sort(rs.begin(), rs.end()); // 값이 섞여있기에 정렬
       
    if(rs.size()<=n)
        cout<<"-1";

        
    else if(rs.size()>n) 
        cout<<rs[n];
    
    return 0;
}