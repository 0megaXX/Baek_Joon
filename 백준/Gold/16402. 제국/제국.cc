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

int n, m;
string s;
vector<string> nation;
int parent[502];
map<string, int> Map;
vector<string> rs;
map<int, int> check;
 
int find_p(int a)
{
   if(a==parent[a])
       return a;
   
   return parent[a] = find_p(parent[a]);
   
}
 
void union_p(string a, string b) // a가 b를 이겼다.
{
    int x = find_p(Map[a]);
    int y = find_p(Map[b]);
 
    if(x!=y)
    { // 다른 왕국끼리 싸움 y->x
    
        parent[y] = x;
    }
    else{ // 같은 왕국 안에서의 싸움
        parent[Map[a]] = Map[a];
        parent[x] = Map[a];
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    cin.ignore();
    
    for(int a=0; a<n; a++)
    {
        // 분리
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while(ss >> tmp)
        { 
            
        }
        nation.push_back(tmp);
        Map[tmp] = a;
        parent[a] = a;
    }
 
    for(int a=0; a<m; a++)
    {
        getline(cin, s);
        string s1, s2;
        int win = s[s.size()-1]-'0';
        int idx = 11;
        
        while(s[idx]!=',')
        {
            s1 += s[idx++];
        }
        
        idx += 12;
        
        while(s[idx]!=',')
        {
            s2 += s[idx++];
        }

        
        // 승자에 따라 다르게 함수 실행
        if(win==1) 
            union_p(s1, s2);
            
        else if(win==2)
            union_p(s2, s1);
        
    }

    
    for(int a=0; a<n; a++)
    {
        int tmp = find_p(a);
        if(check.count(tmp)==0)
        {
            check[tmp] = 1;
            rs.push_back(nation[tmp]);
        }
    }
 
    sort(rs.begin(), rs.end());
 
    cout<<rs.size()<<"\n";
    for(int i=0; i<rs.size(); i++)
        cout<<"Kingdom of "<<rs[i]<<"\n";
    

    return 0;
}

