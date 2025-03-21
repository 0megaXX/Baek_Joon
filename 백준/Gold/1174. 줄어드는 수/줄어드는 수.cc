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

void fn(long long num, int lv)
{
	if(lv > 10) // 자릿수 최대
        return;
    
	v.push_back(num);

   long long next = num * 10;
    int next_lv = lv+1;
	for(int a = num % 10 - 1 ; a >= 0 ;a--) // 자리수 하나씩 증가
		fn(next + a, next_lv);
	
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
	cin >> n;

	for(int i = 0; i <= 9 ; i++)
		fn(i,1);

	sort(v.begin(),v.end());
	
	if(n > v.size()) 
        cout<< -1; 
    else 
        cout<< v[n-1]  ;
    

	return 0;
}
