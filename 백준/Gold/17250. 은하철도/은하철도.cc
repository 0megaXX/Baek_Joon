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

vector<int>parent;
vector<long long>val;

int find_parent(int a)
{
    if(parent[a] != a)
        return parent[a] = find_parent(parent[a]);

    else
        return a;  
}


long long union_parent(int a, int b)
{

    if (a > b)
    {
        val[a] += val[b];
        val[b] = val[a];
        parent[a] = b;
        return val[a];
    }
    else
    {
        val[b] += val[a];
        val[a] = val[b];
        parent[b] = a;
        return val[b] ;
    }
    

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;

    parent.resize(n+1);
    val.resize(n+1);
    
    for (int a=1;a<=n ;a++) 
        parent[a] = a;

    for (int a=1;a<=n ;a++ )
    {
        int b;
        cin>>b;
        val[a] = b;
    }

    for(int a=0;a<m;a++)
    {
        int b,c;
        cin>>b>>c;

        int fpb = find_parent(b);
        int fpc = find_parent(c);
        if( fpb != fpc )
        {
            cout << union_parent(fpb, fpc)<<'\n';
            
        }   
        else
            cout<<val[fpb]<<'\n';
        
    }
    


        //for (int a=1;a<=n ;a++ ) 
        //    cout << val[a] << ' ';

    return 0;
}

