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

#define MAXN 501
#define MAXX 1000000000
using namespace std;

vector<int> next_node[MAXN];
int first[MAXN]; // 각 노드의 선행 노드 수를 기록
vector<int> rank_list; // 초기 순위 정보 저장

// 함수 객체로 Compare 정의
struct Compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second != b.second)
            return a.second > b.second; // 오름차순을 위해 부등호 변경
        else
            return a.first > b.first;   // 오름차순을 위해 부등호 변경
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cass;
    cin >> cass;

    while (cass--) {
        int n;
        cin >> n;

        // 초기화
        rank_list.resize(n);
        memset(first, 0, sizeof(first));
        for (int i = 1; i <= n; i++)
            next_node[i].clear();

        // 초기 순위 입력
        for (int a = 0; a < n; a++) 
            cin >> rank_list[a];
        

        // 초기 순위에 따른 방향 그래프 구성
        for (int a = 0; a < n; a++) 
            for (int b = a + 1; b < n; b++) 
            {
                next_node[rank_list[a]].push_back(rank_list[b]);
                first[rank_list[b]]++;
            }
        

        
        int change_case;
        cin >> change_case;

        for (int a = 0; a < change_case; a++) // 순위가 바뀐 팀들에 대해 방향을 변경
        {
            int b, c;
            cin >> b >> c;

            // 방향 전환
            bool found = false;
            for (auto it = next_node[b].begin(); it != next_node[b].end(); it++)
            {
                if (*it == c) // 변경할 
                {
                    next_node[b].erase(it);
                    next_node[c].push_back(b);
                    first[c]--;
                    first[b]++;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                for (auto it = next_node[c].begin(); it != next_node[c].end(); it++) {
                    if (*it == b) {
                        next_node[c].erase(it);
                        next_node[b].push_back(c);
                        first[b]--;
                        first[c]++;
                        break;
                    }
                }
            }
        }

        // 위상 정렬
        priority_queue<int, vector<int>, greater<int>> pq; // 작은 수부터 처리

        for (int a = 1; a <= n; a++) 
            if (first[a] == 0) // 선행노드가 없다면
                pq.push(a);
        

        vector<int> result;
        bool ambiguous = false;

        while (!pq.empty()) {
            if (pq.size() > 1) {
                ambiguous = true; // 여러 개의 노드가 동시에 처리 가능하면 불확실한 순서
                break;
            }

            int cur = pq.top();
            pq.pop();
            result.push_back(cur);

            for (int next : next_node[cur]) {
                if (--first[next] == 0) {
                    pq.push(next);
                }
            }
        }

        // 결과 출력
        if (result.size() != n) {
            cout << "IMPOSSIBLE\n";
        }
        else if (ambiguous) {
            cout << "?\n";
        }
        else {
            for (int team : result) {
                cout << team << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}