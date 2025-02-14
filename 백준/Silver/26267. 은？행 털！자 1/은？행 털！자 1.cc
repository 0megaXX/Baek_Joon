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

using namespace std;
#define MAXX 2147483647

unordered_map<int,long long>m;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    for (int a=0;a<n ;a++ )
        {
            int x,t,c; // 좌표, 입장시간, 획득금액
            cin>>x>>t>>c;
            m[t-x]+=c;
        }

    long long rs=0;
     for (auto it = m.begin(); it != m.end(); it++)
        rs=max(rs,it->second);
    
    cout<<rs;
 
	return 0;

}