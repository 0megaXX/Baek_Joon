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

vector<long long> v;

int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    long long n, m, k;
    cin>>k;
    v.resize(k);
    for(int a = 0; a < k; a++) 
        cin>>v[a];
    
    sort(v.begin(), v.end());

    m=0;
    n = v[k - 1]; //최댓값
    for(int a = 0; a < k - 1; a++) 
        m += v[a]; // 나머지
    
    if(n >= m) // 나머지만큼 다 깨고 남음
        cout<< n - m;
        
    else // 아니라면 어떻게든 1개 혹은 0개가 남음
    {
        if(n % 2  ==  m % 2) 
            cout<<0;
        else
            cout<<1;
    }
    

    return 0;
}