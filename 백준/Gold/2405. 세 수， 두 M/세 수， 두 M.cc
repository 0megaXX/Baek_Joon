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

vector<long long>v;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin>>n;

    v.resize(n);

    for (int a=0;a<n ;a++ )
        cin>>v[a];

    sort(v.begin(), v.end());

    long long rs = 0;

    // a<b<c 일때 중위값은 b, 평균 (a+b+c)/3 , 이므로 도출값은 (b-(a+b+c)/3))*3 -> ( a-2b+c | -a+2b-c ) c를 고정 || a를 고정


    // a-2b+c -- c고정
    for (int a = 0; a < n - 2; a++)
        rs = max(rs, abs(v[a]  - v[a + 1] * 2 + v[n - 1]));

    // -a+2b-c -- a고정
    for (int a = 1; a < n - 1; a++) 
        rs = max(rs, abs(-v[0] + v[a] * 2 - v[a + 1]));

    cout<<rs;
    
    return 0;
}

