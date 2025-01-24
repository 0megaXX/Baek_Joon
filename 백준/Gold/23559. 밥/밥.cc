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





vector<pair<int,int>>v;

bool cmp(pair<int, int> p1, pair<int, int> p2) // 정렬기준은 천원과 오천원의 가치차이가 큰 순으로 정렬
{
    int a = abs(p1.first - p1.second);
    int b = abs(p2.first - p2.second);
    
    if (a == b) 
        return p1.second > p2.second;
    else
        return a > b;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n,x;
    int taste_sum = 0;
    cin>>n>>x;
    
    for (int a = 0; a < n; a++)
    {
        int b, c;
        cin >> b >> c;
        v.push_back({b,c});
        taste_sum += c; // 최소가격의 맛
    }
    
    sort(v.begin(), v.end(), cmp);
    
    int money = n * 1000; // 밥을 다 먹기 위한 최소비용
    x -= money; // 모두 천원 밥을 먹었다고 가정
    
    
    for (int a = 0; a < n; a++)
    {
        if (x <= 0) // 돈이 없으면 끝
            break;
        
        if (v[a].first > v[a].second && x >= 4000) // 5천원음식이 더 맛있고 돈이 남아있다면 (반드시 5천원음식이 맛있는건 아님)
        {
            taste_sum += v[a].first - v[a].second; // 맛 가산
            x -= 4000; // 천원대신 오천원으로 변경
        }
        
    }
    
    cout << taste_sum;

	return 0;

}