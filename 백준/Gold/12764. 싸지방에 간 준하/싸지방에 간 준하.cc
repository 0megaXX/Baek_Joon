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
#define MAXX 99999999

int n;
vector<pair<int, int> > v;
priority_queue<pair<int, int> > pq; // 사용자의 종료 시간, 사용한 자리  
priority_queue<int> left_seats; // 빈 자리
int answer[100001];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int s, e;
    for (int a = 0; a < n; a++)
    {
        cin >> s >> e;
        v.push_back({ s, e });
    }

    sort(v.begin(), v.end());
    int seat = 0;

    for (int a = 0; a < v.size(); a++) {

        // 다음으로 들어오는 사용자의 시작 시간과 이용중인 사용자의 끝나는 시간을 비교
        // 다음 사용자가 들어오기 전에 끝난 사용자가 있으면, 자리 번호를 저장하고 pq에서 제거  
        while (!pq.empty()) 
        {
            if (-pq.top().first <= v[a].first)
            {
                left_seats.push(-pq.top().second);
                pq.pop();
            }
            else 
                break;
        }

        // 빈 자리가 없을 때  
        if (left_seats.empty())
        {
            pq.push({ -v[a].second, seat });
            answer[seat++]++;
        }

        // 빈 자리가 있을 때  
        else {
            int tmp_seat = -left_seats.top();
            pq.push({ -v[a].second, tmp_seat });
            answer[tmp_seat]++;
            left_seats.pop();
        }
    }

    cout << seat << '\n';
    for (int a = 0; a < seat; a++)
        cout << answer[a] << " ";

}