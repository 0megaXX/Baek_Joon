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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    
    for (int a=0;a<n ;a++ )
    {
        string s;
        cin>>s;
        m[s]++;
    }

    for (int a=0;a<n-1 ;a++ )
    {
        string s;
        cin>>s;
        m[s]--;
    }

    for (auto it = m.begin(); it != m.end() ;it++ )
    {
        if(it->second!=0)
        { 
          cout<<it->first;
          break;
        }
    }
    
    return 0;
   
}


