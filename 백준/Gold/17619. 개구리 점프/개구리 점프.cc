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


struct P
{
    int x1,x2,num;
};

bool cmp(P a,P b)
{
    return a.x1 < b.x1;
};

vector<P>tree;
vector<int>g(100001);

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int N,Q;
    cin>>N>>Q;

    tree.resize(N);
    
    for(int a=0;a<N;a++)
    {
        int x1,x2,y;
        cin >> x1 >> x2 >> y; // 높이 y는 굳이 알 필요가 없는 정보
        tree[a]={x1,x2,a};
    }
    
    sort(tree.begin(),tree.end(),cmp);
 
    int sid=0;
    int e=tree[0].x2;
    g[0]=0;
 
    for(int a=1;a<N;a++)
    {
        if(tree[a].x1<=e)
        {
            if(tree[a].x2>e)
                e=tree[a].x2;    
        }
        else
        {
            sid++;
            e=tree[a].x2;
        }
        g[tree[a].num]=sid;
    }
    
    while(Q--){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        if(g[u]==g[v])
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }
    

    return 0;
}