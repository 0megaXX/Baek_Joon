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

#define MAXX 1000000000
using namespace std;
int N, M;

vector<int> v(100001);
vector<int> tree(400004); // {최대 , 최소} 트리

// 구간 트리 초기화
int init(int node, int start, int end) 
{
    if (start == end) 
        return tree[node] =v[start];
    
    int mid = (start + end) / 2;
   int left = init(2 * node, start, mid);
   int right = init(2 * node + 1, mid + 1, end);
    return tree[node] =  min(left, right) ;
}

// 구간 트리에서 쿼리
int query(int node, int start, int end, int left, int right) 
{
    if (right < start || end < left)
        return MAXX ; // 범위 밖

    else if (left <= start && end <= right) 
        return tree[node]; // 범위 안

    int mid = (start + end) / 2;
    int l = query(2 * node, start, mid, left, right);
    int r = query(2 * node + 1, mid + 1, end, left, right);

    return min(l ,r) ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int a = 0; a < N; a++) 
        cin >> v[a];
    

    // 구간 트리 초기화
    init(1, 0, N - 1);

    for (int a = 0; a < M; a++) {
        int s, e;
        cin >> s >> e;
        cout<<query(1, 0, N - 1, s - 1, e - 1)<<'\n';
       
    }

    return 0;
}