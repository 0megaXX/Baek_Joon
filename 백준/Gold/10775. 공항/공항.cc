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
#include <deque>
using namespace std;


int parent[100001];
int G, P, ans;


int find(int x){
    if(x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

void union_parent(int a, int b){
    a = find(a);
    b = find(b);
    parent[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0; i<=100000; i++) parent[i] = i;
    
    cin>>G>>P;
    for(int i=1; i<=G; i++){
        int gate;
        cin>>gate;
        
        if(find(gate) == 0) break;
        else{
            ans++;
            union_parent(find(gate), find(gate)-1);
        }
    }
    cout<<ans;
}