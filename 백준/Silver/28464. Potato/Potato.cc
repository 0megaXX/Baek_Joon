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


vector<int>v;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int sung = 0;
    v.resize(n);
   
    for (int a=0;a<n ;a++ )
        {
            cin>>v[a];
            sung+=v[a];
        }
    sort(v.begin(),v.end());

    // 박모씨
    int park = 0;
    for (int a=0; a<n/2 ;a++ )
    {
        park+=v[a];
    }

    sung-=park;

    cout<<park<<' '<<sung;

    return 0;
}