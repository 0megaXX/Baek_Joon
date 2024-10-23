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

#define MAXX 1000000005
using namespace std;

// 끝거리 + d 가 다음 길이의 시작거리보다 크거나 같다면 ok

bool compare(pair<int, int>a, pair<int, int>b)
{
    if  (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;



}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d;
    cin >> n;

    vector< pair<int, int>>v;
    for (int a = 0; a < n; a++)
    {
        int start, end;
        cin >> start >> end;
        if(start<end)
            v.push_back({ start,end });
        else
            v.push_back({ end,start });

    }

    cin >> d;
    sort(v.begin(), v.end(), compare);
    int rs = 0;

    priority_queue<int> pq;

    for (int i = 0; i < v.size(); i++) {
        int start = v[i].first;
        int end = v[i].second;

        // 길이가 철도 선분 d보다 크다면 pq에 넣지 않는다.  
        if (end - start <= d) 
            pq.push(-start);
        else
            continue;

        // pq에는 출발 위치가 저장되어 있다.
        // 다음으로 들어갈 사람의 도착 위치에서 -d한 위치과 저장된 출발 위치를 비교 
        while (!pq.empty())
        {
            if (-pq.top() < end - d)
                pq.pop();
            else
            {
                rs = max(rs, (int)pq.size());
                break;
            }
        }

    }

    cout << rs;

    return 0;

}