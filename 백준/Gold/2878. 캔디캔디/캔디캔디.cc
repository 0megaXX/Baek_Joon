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

vector<long long>v;

int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    long long m;
    int n;
    cin>>m>>n;

    long long sum = -m; // 부족한 사탕의 수
    
    for (int a = 0; a < n; a++)
    {
        long long val;
        cin>>val;
        v.push_back(val);
        sum += val;
    }
 
    sort(v.begin(), v.end());
 
    long long ans = 0;
    // 못받은 차이만큼 화를 내기에 요구량이 적은 사람은 안두고 많은 사람에게 최대한 주기
    for (int a = 0; a < n; a++) 
    {
        long long rmd = min(v[a], sum / (n - a)); // 개인의 남은 요구사탕 vs 남은 요구사탕의 평균
        ans += (rmd * rmd);
        sum -= rmd;
    }
    
    cout<< ans;
 
    

    return 0;
}