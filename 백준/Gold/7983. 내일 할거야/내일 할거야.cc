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

#define MAXX 987654321
using namespace std;


bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first; // 마감 시간 기준으로 오름차순 정렬
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin >> cass;

    vector<pair<int, int>> v;
    int spend_time, limit_time;

    for (int a = 0; a < cass; a++) 
    {
        cin >> spend_time >> limit_time;
        v.push_back({ limit_time, spend_time }); // {마감 시간, 걸리는 시간} 저장
    }

    sort(v.begin(), v.end(), compare); // 마감 시간이 빠른 순서대로 정렬

    int current_time = v[cass - 1].first; // 제일 늦은 마감 시간을 초기값으로 설정

    for (int a = cass - 1; a >= 0; a--)
    {
        current_time = min(current_time, v[a].first); // 마감 시간보다 늦지 않게 설정
        current_time -= v[a].second; // 과제를 수행하는 데 걸리는 시간만큼 감소
    }

    cout << current_time; // 최종적으로 가능한 가장 늦게 시작할 수 있는 시간 출력

    return 0;
}