#include <iostream>

#include <string>

#include <vector>

#include <ctime>

#include <cstdlib>

#include <fstream>

#include <stddef.h>

#include <algorithm>

#include <sstream>

#include <cmath>

#include <map>

#include <queue>

#include <stack>

#include <cstring>

#include <deque>

#include <set>

#include <unordered_map>

using namespace std;

int N, M, rs = 987654321;

int Map[50][50];

bool visit[50][50];

int Map_ct[50][50];

bool choose[10];

int dx[4]{ 0,0,1,-1 };

int dy[4]{ -1,1,0,0 };

vector<pair<int, int>> v;

vector<pair<int, int>> choose_v;

struct MyStruct

{

    int x, y, ct;

};

bool check_map()

{

    for (int a = 0; a < N; a++)

    {

        for (int b = 0; b < N; b++)

        {

            if (Map[a][b] == 1) // 벽이면 통과

                continue;

            if (Map[a][b] == 0 && !visit[a][b]) // 벽이 아닌데 바이러스가 간적이 없다면

                return false;

        }

    }

    return true;

}

int check_map_ct()

{

    int maxx = 0;

    for (int a = 0; a < N; a++)

    {

        for (int b = 0; b < N; b++)

        {

            if (Map[a][b] ==0) // 벽이 아닌 경우에만 최대값 계산

                maxx = max(maxx, Map_ct[a][b]);

        }

    }

    return maxx;

}

void bfs() {

    queue<MyStruct> q;

    

    for (auto &p : choose_v) {

        int x = p.first;

        int y = p.second;

        q.push({ x, y, 0 });

        visit[x][y] = true;

        Map_ct[x][y] = 0;

    }

    while (!q.empty()) {

        int x = q.front().x;

        int y = q.front().y;

        int ct = q.front().ct;

        q.pop();

        for (int a = 0; a < 4; a++) {

            int nx = x + dx[a];

            int ny = y + dy[a];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[nx][ny]) {

                if (Map[nx][ny] != 1) { // 벽이 아니라면

                    visit[nx][ny] = true;

                    Map_ct[nx][ny]=ct+1;

               q.push({ nx, ny, ct + 1 });

                    

                }

            }

        }

    }

if (check_map())

	rs = min(rs, check_map_ct());

}

void choose_virus(int idx, int cnt)

{

    if (cnt == M)

    {

        memset(visit, false, sizeof(visit));

        memset(Map_ct, 0, sizeof(Map_ct));

        bfs();

        return;

    }

    for (int a = idx; a < v.size(); a++)

    {

        if (choose[a]) // 이미 조합에 포함됐다면 넘김

            continue;

        choose[a] = true;

        choose_v.push_back(v[a]);

        choose_virus(a, cnt + 1);

        choose_v.pop_back();

        choose[a] = false;

    }

}

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    memset(choose, false, sizeof(choose));

    cin >> N >> M;

    for (int a = 0; a < N; a++)

    {

        for (int b = 0; b < N; b++)

        {

            cin >> Map[a][b];

            if (Map[a][b] == 2)

                v.push_back({ a, b });

        }

    }

    choose_virus(0, 0);

    if (rs == 987654321)

        rs = -1;

    cout << rs;

}