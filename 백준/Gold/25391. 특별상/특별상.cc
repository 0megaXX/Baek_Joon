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


vector<pair<long ,long>>v;

bool compare(pair<long,long>a,pair<long,long>b)
{
    return a.second > b.second;
}

int main() {

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    int n,m,k;
    cin>>n>>m>>k;

    for (int a=0;a<n ;a++ )
    {
        long aa,bb;
        cin>>aa>>bb;
        v.push_back({bb,aa});
    }

    sort(v.begin(),v.end(),greater<>());
    
    
	long sum = 0; 
	for (long i = 0; i < k; i++)  //심판은 뽑음.
    {
		sum += v[i].second;
		v[i].first = -100; // 심판이 뽑은 사람은 뽑지 않기 위해 음수 적용
	}
    
	sort(v.begin(), v.end(), compare); // 주최자 내림차순 

	int ct = 0;
	int cur = 0;
	while (1) 
    {
		if (ct == m) 
			break;
		
		if (v[cur].first != -100) // 심판이 안뽑지 사람 중 주최자가 높은 점수를 준 사람
        {
			sum += v[cur].second;
			ct++;
		}
        
		cur++;

	}
	cout << sum ;

	return 0;
}