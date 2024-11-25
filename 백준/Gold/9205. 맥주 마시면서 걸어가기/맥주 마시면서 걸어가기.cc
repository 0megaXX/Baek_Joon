#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

pair<int, int> start_pos, end_pos;
vector<pair<int, int>> v;
bool visit[101]; // 맥주 마시기 지점들의 방문 여부를 체크할 배열

bool bfs() {
    queue<pair<int, int>> q;
    q.push(start_pos);
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // 목적지까지의 거리가 1000 이하라면 도달 가능
        if (abs(end_pos.first - x) + abs(end_pos.second - y) <= 1000) {
            return true;
        }

        // 모든 맥주 마시기 지점 탐색
        for (int i = 0; i < v.size(); i++) {
            int nx = v[i].first;
            int ny = v[i].second;
            int diff = abs(nx - x) + abs(ny - y);

            // 아직 방문하지 않았고, 현재 위치에서 1000 이하로 이동 가능하다면
            if (!visit[i] && diff <= 1000) {
                visit[i] = true; // 해당 지점 방문 처리
                q.push({nx, ny});
            }
        }
    }

    return false; // 목적지에 도달할 수 없다면 false 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; // 테스트 케이스 개수
    
    while (t--) {
        v.clear(); // 벡터 초기화
        memset(visit, false, sizeof(visit)); // 방문 배열 초기화
        
        int n;
        cin >> n; // 맥주 마시기 지점 개수
        
        int sx, sy;
        cin >> sx >> sy; // 시작 지점
        start_pos = {sx, sy};

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y}); // 맥주 마시기 지점 추가
        }

        int ex, ey;
        cin >> ex >> ey; // 목표 지점
        end_pos = {ex, ey};

        // BFS 탐색 후 결과 출력
        if (bfs())
            cout << "happy\n";
        else
            cout << "sad\n";
    }

    return 0;
}
