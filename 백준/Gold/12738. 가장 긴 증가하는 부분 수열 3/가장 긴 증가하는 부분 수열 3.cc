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


vector<int>v;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin >>n;
    for (int a=0;a<n ;a++ )
    {
        int b;
        cin>>b;

        if(v.size()==0 || v[v.size()-1]<b)
            v.push_back(b);

        else
        {
            int change_pos = lower_bound(v.begin(), v.end(), b)-v.begin();
            v[change_pos]=b;


            
        }
    }

   /* for (int a=0;a<v.size() ;a++ )
        cout<<v[a]<<' ';
    */
    cout<<v.size();
    return 0;
}