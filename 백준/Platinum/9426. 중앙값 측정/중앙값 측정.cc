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

#define MAXX 1000000000
#define MAXVAL 65535

using namespace std;
vector<long long>tree(3000001);
vector<long long>v(1000001);



void init(int node, int start, int end, int val, int ct)
{

    if (start == end )
    {    
        tree[node]+=ct;
        return;
    }

    int mid = (start+end)/2;

    if(val<=mid) // 좌탐색
        init(node*2,start,mid,val, ct);

    else // 우탐색
        init(node*2+1,mid+1,end,val, ct);


    tree[node] = tree[node*2]+tree[node*2+1];
    
}

long long query(int node, int start, int end, int ran)
{

        if( start == end )
            return start;

          int mid = (start+end)/2;

        if(ran<=tree[node*2]) // 좌탐색
           return query(node*2,start,mid,ran);
    
        else // 우탐색
           return query(node*2+1,mid+1,end,ran-tree[node*2]);


    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N,K;
    cin>>N>>K;

    for (int a=0 ; a<N ; a++)
         cin>>v[a];

 
    for(int a=0;a<(K-1);a++)
        init(1,0,MAXVAL,v[a],1);

   
    long long rs=0;
    int slide = 0;
    for(int a=K-1; a<N; a++)
        {
            init(1,0,MAXVAL,v[a],1);
            rs += query(1,0,MAXVAL,(K+1)/2);
            init(1,0,MAXVAL,v[slide++],-1);

            
        }

    cout<<rs;
    return 0;
}