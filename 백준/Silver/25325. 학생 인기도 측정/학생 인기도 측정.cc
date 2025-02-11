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

    map<string,int>m;

    bool cmp(pair<string,int>a, pair<string,int>b)
    {
        if(a.second!=b.second)
            return a.second>b.second;
        else
            return a.first<b.first;
    }

	int main() {

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
        int n;
        cin>>n;

        string s;
        for (int a=0;a<n ;a++ ) 
        {
             cin>>s;
            m[s]=0;
        }
         cin.ignore();
          for (int a=0;a<n ;a++ ) 
              {
                 
                  string s;
                  getline(cin,s);
                  stringstream ss(s);
                  string tmp;
                  while (getline(ss, tmp, ' '))
                      m[tmp]++;
              }
        

        vector<pair<string,int>>v;
        for (const auto& p : m) 
           v.push_back({p.first,p.second});

        sort(v.begin(),v.end(),cmp);
         for (const auto& p : v) 
             cout<<p.first<<' '<<p.second<<'\n';
        
	}

    