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


vector<int>v;
int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n,m;
    cin>>n>>m;

    for (int a=0;a<m ;a++ )
    {
        int b;
        cin>>b;
        v.push_back(b);
    }

    sort(v.rbegin(), v.rend());

    int total_rs = 0;
    int rs;
    for (int a =0;a<m ;a++ )
    {
        if(a >= n)
            break;

        if( total_rs <v[a]*(a+1) )
        {
          rs = v[a];
          total_rs = v[a] * (a+1);
        }
        
    }

    cout << rs<< ' '<<total_rs;

    return 0;
}