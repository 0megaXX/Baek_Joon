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

int n;
long long summ = 0; // 총 사람 수
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int a = 0; a < n; a++) 
    {
        int b, c;
        cin >> b >> c;
        v.push_back({ b,c });
        summ += c;
    }

    sort(v.begin(), v.end());
    long long human = 0;
    
    for (int a = 0; a < n; a++) 
    {
        human += v[a].second;
        double half = summ / 2.0;
        if (human >= half) // 누적 인원이 전체 인구의 절반 이상이면 최소거리 & 동일하면 왼쪽에 있는게 답
        {
             cout << v[a].first;
             return 0;
        }
    }
    

    return 0;
   
}


