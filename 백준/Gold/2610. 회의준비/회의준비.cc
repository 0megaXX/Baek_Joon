#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define MAXX 987654321

set<int> S;
int parent[101];
int human;
vector<vector<int>> v(101, vector<int>(101, MAXX));

map<int, pair<int, int>> rs;

int find_parent(int a) {
    if (parent[a] != a)
        return parent[a] = find_parent(parent[a]);
    else
        return a;
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

void floyd() {
    for (int k = 1; k <= human; k++)
        for (int i = 1; i <= human; i++)
            for (int j = 1; j <= human; j++)
                if (v[i][j] > v[i][k] + v[k][j])
                    v[i][j] = v[i][k] + v[k][j];
}

int min_rel(int a) {
    int temp = 0;
    for (int b = 1; b <= human; b++) {
        if (a != b && v[a][b] != MAXX)
            temp = max(temp, v[a][b]);
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> human;

    for (int a = 1; a <= human; a++)
        parent[a] = a;

    int rel;
    cin >> rel;
    for (int a = 0; a < rel; a++) {
        int b, c;
        cin >> b >> c;
        if (find_parent(b) != find_parent(c))
            union_parent(b, c);

        v[b][c] = 1;
        v[c][b] = 1;
    }

    for (int a = 1; a <= human; a++) {
        for (int b = 1; b <= human; b++) {
            if (a == b)
                v[a][b] = 0;
        }
    }

    floyd();

    for (int a = 1; a <= human; a++) {
        int p_a = find_parent(a);
        if (S.find(p_a) == S.end()) {
            S.insert(p_a);
            rs[p_a] = { a, min_rel(a) };
        } else {
            int rel = min_rel(a);
            if (rs[p_a].second > rel || (rs[p_a].second == rel && rs[p_a].first > a)) {
                rs[p_a] = { a, rel };
            }
        }
    }

    cout << rs.size() << '\n';

    vector<int> rs_v;
    for (auto iter = rs.begin(); iter != rs.end(); iter++)
        rs_v.push_back(iter->second.first);

    sort(rs_v.begin(), rs_v.end());

    for (int a : rs_v)
        cout << a << '\n';

    return 0;
}