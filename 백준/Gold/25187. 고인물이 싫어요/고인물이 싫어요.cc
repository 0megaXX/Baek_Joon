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
#include <regex>

using namespace std;
#define MAXX 2147483647



// parent[i]: i의 대표 노드
// clean[i]: i 대표 집합의 청정수 개수
// dirty[i]: i 대표 집합의 고인물 개수
int parent[100001];
int clean[100001], dirty[100001];

int find_pt(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find_pt(parent[x]);
}

void union_pt(int a, int b)
{
    a = find_pt(a);
    b = find_pt(b);
    if (a == b) return;
    if (a < b) {
        parent[b] = a;
        clean[a] += clean[b];
        dirty[a] += dirty[b];
    } else {
        parent[a] = b;
        clean[b] += clean[a];
        dirty[b] += dirty[a];
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, Q;
    cin >> N >> M >> Q;

    for (int a = 1; a <= N; a++) {
        parent[a] = a;
    }

    for (int a = 1; a <= N; a++)
    {
        int t;
        cin >> t;

        // 타입에따라 물 구별
        if (t == 1)
            clean[a] = 1;
        else
            dirty[a] = 1;
    }

    for (int a = 0; a < M; a++)
    {
        int u, v;
        cin >> u >> v;
        union_pt(u, v);
    }

    while (Q--)
    {
        int k;
        cin >> k;
        int p = find_pt(k);
        cout << (clean[p] > dirty[p] ? 1 : 0) << '\n';
    }
   
    return 0;
}
