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
#define MAX_N 100001
#define MAX_M 100001
using namespace std;



vector<int> tree(MAX_N * 8);
vector<int> arr(MAX_N);
vector<int> ans(MAX_M);

int update(int node, int start, int end, int target, int val) 
{
    if (target < start || target > end) return tree[node];
    if (start == end) return tree[node] = val;

    int mid = (start + end) / 2;
    int left = update(node * 2, start, mid, target, val);
    int right = update(node * 2 + 1, mid + 1, end, target, val);

    return tree[node] = left + right;
}


int query(int node, int start, int end, int left, int right) 
{
    if (right < start || end < left) 
        return 0;
    
    if (left <= start && end <= right) 
        return tree[node];

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right)
         + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, T;
    
    cin >> T;
    while (T--)
    {
        cin >> N >> M;

        int size = N + M + 1;
        fill(tree.begin(), tree.begin() + size * 4, 0);

        // 초기화
        for (int a = 0; a < N + M; a++) 
            update(1, 0, size - 1, a, (a < N ? 1 : 0));
        

        // 영화 번호 a의 현재 위치
        for (int a = 1; a <= N; a++) 
            arr[a] = N - a;
        

        int currentTop = N;

        for (int a = 0; a < M; a++) 
        {
            int movie;
            cin >> movie;

            int pos = arr[movie];
            ans[a] = query(1, 0, size - 1, pos + 1, size - 1);

            // 현재 위치 제거
            update(1, 0, size - 1, pos, 0);
            // 새로운 맨 위 위치 삽입
            update(1, 0, size - 1, currentTop, 1);
            arr[movie] = currentTop++;

        }

        for (int a = 0; a < M; a++) 
            cout << ans[a] << " ";
        
        cout << '\n';
    }

    return 0;
}