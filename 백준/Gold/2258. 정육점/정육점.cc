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


int n, m;

vector<pair<int,int>>v;

bool compare(pair<int,int>a, pair<int,int>b)
{
     
        if (a.second == b.second)
            return a.first > b.first;
        else
            return a.second < b.second;
}

int main()
{
    
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
   cin >> n >> m;

    for (int a = 0; a < n; a++)
    {
        int b,c;
        cin >> b >> c;
        v.push_back({ b, c });
    }

    sort(v.begin(), v.end(),compare);

    int total = 0; // 딸려오는 무게
    int price = 0;
    int rs = MAXX;
    bool flag = false;

    for (int a = 0; a < v.size();a++)
    {
        total += v[a].first;  // 

        if (a != 0 && v[a - 1].second == v[a].second) // 전 고기의 무게가 현 고기의 무게와 같다면 딸려오지 않음
            price += v[a].second;
        else
            price = 0;

        if (total >= m)
        {
            rs = min(rs, price + v[a].second);
            flag = true;
        }
    }


    cout << (flag ? rs : -1) ;

}