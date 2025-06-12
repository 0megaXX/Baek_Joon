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

map<string,string>m;


string find_parent(string s)
{
    if (m[s]!=s) 
        return m[s]=find_parent(m[s]);    
    
    else
        return s;
    
}


void union_patrent(string s1, string s2)
{
    s1 = find_parent(s1);
    s2 = find_parent(s2);

    
    if (s1 > s2)
    {
        m[s1] = s2;
    }
    else
    {
        m[s2] = s1;
    }
    
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cur = 1;
    int n=-1;
    cin >> n;
    while(n!=0)
    {
        
    
        int ct = 0;
        m.clear();
        for (int a=0;a<n ;a++ )
        {
            string s1,s2;
            cin>>s1>>s2;
    
           if (m.find(s1) == m.end())
                m[s1]=s1;
            
            if (m.find(s2) == m.end())
                m[s2]=s2;
    
            if(find_parent(s1) != find_parent(s2))
            {
                union_patrent(s1,s2);
            }
            else
                ct++;
    
        
            
        }
    
          cout<<cur++<<' '<<ct<<'\n';
        cin >> n;
    }
    
    return 0;
}

